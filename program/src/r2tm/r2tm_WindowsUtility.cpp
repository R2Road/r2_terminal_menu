#include "r2tm_WindowsUtility.h"

#include <Windows.h>

namespace r2tm
{
	void WindowsUtility::ChangeTitle( const char* title_string )
	{
		SetConsoleTitleA( title_string );
	}

	void WindowsUtility::Resize( const int w, const int h )
	{
		HWND hWnd = GetConsoleWindow();
		RECT window_rect;
		GetClientRect( hWnd, &window_rect );
		MoveWindow( hWnd, window_rect.left, window_rect.top, w, h, TRUE );
	}

	void WindowsUtility::Move( const int x, const int y )
	{
		//
		// # MoveWindow( hWnd, 0, 0... ); �����δ� Window �� �������� 0, 0 ��ǥ�� ��ġ���� �ʴ´�.
		// # �Ʒ��� �ڵ带 �̿��ؼ� Ÿ��Ʋ �ٿ� ���� �������� ���� �ؾ߸� �� �ڵ�� 0, 0 ��ġ�� ��������.
		//		LONG lStyle = GetWindowLong( GetConsoleWindow(), GWL_STYLE );
		//		lStyle &= ~( WS_CAPTION | WS_THICKFRAME );
		//		SetWindowLong( GetConsoleWindow(), GWL_STYLE, lStyle );
		//
		// # �� ��ǥ�� Ÿ��Ʋ �ٴ� ���� ������ Window �� 0, 0 �� �ڸ��ϴ� ���̴�.
		// # ���� Frame ũ�⸦ ����ؼ� ������ 0, 0 ��ġ�� ���̰� �ϰ��� �Ѵ�.
		//
		int offset_x = 0;
		offset_x -= GetSystemMetrics( SM_CXBORDER );
		offset_x -= GetSystemMetrics( SM_CXFRAME );
		offset_x -= GetSystemMetrics( SM_CXFIXEDFRAME );

		HWND hWnd = GetConsoleWindow();
		RECT rectClient;
		GetClientRect( hWnd, &rectClient );
		MoveWindow( hWnd, x + offset_x, y, rectClient.right - rectClient.left, rectClient.bottom - rectClient.top, TRUE );
	}

	void WindowsUtility::ScrollBarVisible( const bool visible )
	{
		ShowScrollBar( GetConsoleWindow(), SB_VERT, visible );
	}

	void WindowsUtility::MaximizeButtonEnable( const bool enable )
	{
		LONG window_style = GetWindowLong( GetConsoleWindow(), GWL_STYLE );
		window_style = ( enable ? window_style | ( WS_MAXIMIZEBOX ) : window_style & ~( WS_MAXIMIZEBOX ) );
		SetWindowLong( GetConsoleWindow(), GWL_STYLE, window_style );
	}

	void WindowsUtility::ResizingByDraggingEnable( const bool enable )
	{
		LONG window_style = GetWindowLong( GetConsoleWindow(), GWL_STYLE );
		window_style = ( enable ? window_style | ( WS_SIZEBOX ) : window_style & ~( WS_SIZEBOX ) );
		SetWindowLong( GetConsoleWindow(), GWL_STYLE, window_style );
	}



	void WindowsUtility::QuickEditEnable( const bool enable )
	{
		DWORD console_mode = 0;
		GetConsoleMode( GetStdHandle( STD_INPUT_HANDLE ), &console_mode );
		if( enable )
		{
			console_mode |= ENABLE_EXTENDED_FLAGS;
			console_mode |= ENABLE_QUICK_EDIT_MODE;
		}
		else
		{
			console_mode &= ~( ENABLE_EXTENDED_FLAGS );
			console_mode &= ~( ENABLE_QUICK_EDIT_MODE );
		}
		SetConsoleMode( GetStdHandle( STD_INPUT_HANDLE ), console_mode );
	}



	WindowsUtility::CursorPoint WindowsUtility::GetCursorPoint()
	{
		CONSOLE_SCREEN_BUFFER_INFO csbi{};
		GetConsoleScreenBufferInfo( GetStdHandle( STD_OUTPUT_HANDLE ), &csbi );

		return CursorPoint{ csbi.dwCursorPosition.X, csbi.dwCursorPosition.Y };
	}
	void WindowsUtility::MoveCursorPoint( const CursorPoint new_cursor_point )
	{
		const CursorPoint fixed_new_cursor_point{ short( 0 > new_cursor_point.x ? 0 : new_cursor_point.x ), short( 0 > new_cursor_point.y ? 0 : new_cursor_point.y ) };
		SetConsoleCursorPosition( GetStdHandle( STD_OUTPUT_HANDLE ), COORD{ fixed_new_cursor_point.x, fixed_new_cursor_point.y } );
	}
	void WindowsUtility::MoveCursorPoint( const short x, const short y )
	{
		MoveCursorPoint( { x, y } );
	}

	void WindowsUtility::MoveCursorPointWithClearBuffer( const CursorPoint new_cursor_point )
	{
		const auto last_cursor_point = GetCursorPoint();

		const CursorPoint fixed_new_cursor_point{ short( 0 > new_cursor_point.x ? 0 : new_cursor_point.x ), short( 0 > new_cursor_point.y ? 0 : new_cursor_point.y ) };
		SetConsoleCursorPosition( GetStdHandle( STD_OUTPUT_HANDLE ), COORD{ fixed_new_cursor_point.x, fixed_new_cursor_point.y } );


		if( last_cursor_point.y >= fixed_new_cursor_point.y )
		{
			HANDLE hStdout = GetStdHandle( STD_OUTPUT_HANDLE );
			CONSOLE_SCREEN_BUFFER_INFO cs_buffer_info{};
			GetConsoleScreenBufferInfo( hStdout, &cs_buffer_info );

			DWORD out_result;
			for( short i = 0, end = last_cursor_point.y - fixed_new_cursor_point.y; end > i; ++i )
			{
				FillConsoleOutputCharacterA(
						hStdout
					,	' '
					,	cs_buffer_info.dwSize.X, COORD{ short( 0 ), short( fixed_new_cursor_point.y + i ) }
					,	&out_result
				);
				FillConsoleOutputAttribute(
						hStdout
					,	eColor::BG_Black | eColor::FG_White
					,	cs_buffer_info.dwSize.X
					,	COORD{ short( 0 ), short( fixed_new_cursor_point.y + i ) }
					,	&out_result
				);
			}
		}
	}
	void WindowsUtility::MoveCursorPointWithClearBuffer( const short x, const short y )
	{
		MoveCursorPointWithClearBuffer( { x, y } );
	}



	void WindowsUtility::FillColor( const CursorPoint point, const short c, const int size )
	{
		DWORD out_result;
		FillConsoleOutputAttribute( GetStdHandle( STD_OUTPUT_HANDLE ), c, size, { point.x, point.y }, &out_result );
	}
	void WindowsUtility::FillColor( const CursorPoint point, const short c )
	{
		FillColor( point, c, 1 );
	}
	void WindowsUtility::FillColor( const int x, const int y, const short c, const int size )
	{
		FillColor( { short( x ), short( y ) }, c, size );
	}
	void WindowsUtility::FillColor( const int x, const int y, const short c )
	{
		FillColor( { short( x ), short( y ) }, c, 1 );
	}



	void WindowsUtility::FillCharacter( const CursorPoint point, const char c )
	{
		DWORD out_result;
		FillConsoleOutputCharacterA( GetStdHandle( STD_OUTPUT_HANDLE ), c, 1, { point.x, point.y }, &out_result );
	}
	void WindowsUtility::FillCharacter( const CursorPoint point, const char c, const short color )
	{
		FillCharacter( point, c );
		FillColor( point, color );
	}
	void WindowsUtility::FillCharacter( const int x, const int y, const char c )
	{
		FillCharacter( { short( x ), short( y ) }, c );
	}
	void WindowsUtility::FillCharacter( const int x, const int y, const char c, const short color )
	{
		FillCharacter( { short( x ), short( y ) }, c );
		FillColor( { short( x ), short( y ) }, color );
	}



	void WindowsUtility::FillString( const CursorPoint point, const char* str, const int size )
	{
		DWORD out_result;
		WriteConsoleOutputCharacterA( GetStdHandle( STD_OUTPUT_HANDLE ), str, size, { point.x, point.y }, &out_result );
	}
	void WindowsUtility::FillString( const CursorPoint point, const char* str, const int size, const short color )
	{
		FillString( point, str, size );
		for( int cur = 0; size > cur; ++cur )
		{
			FillColor( { short( point.x + cur ), short( point.y ) }, color );
		}
	}
	void WindowsUtility::FillString( const int x, const int y, const char* str, const int size )
	{
		FillString( { short( x ), short( y ) }, str, size );
	}
	void WindowsUtility::FillString( const int x, const int y, const char* str, const int size, const short color )
	{
		FillString( { short( x ), short( y ) }, str, size, color );
	}

	void WindowsUtility::FillString( const CursorPoint point, const char c, const int size )
	{
		DWORD out_result;
		FillConsoleOutputCharacterA( GetStdHandle( STD_OUTPUT_HANDLE ), c, size, { point.x, point.y }, &out_result );
	}
	void WindowsUtility::FillString( const CursorPoint point, const char c, const int size, const short color )
	{
		FillString( point, c, size );
		FillColor( point, color, size );
	}
	void WindowsUtility::FillString( const int x, const int y, const char c, const int size )
	{
		FillString( { short( x ), short( y ) }, c, size );
	}
	void WindowsUtility::FillString( const int x, const int y, const char c, const int size, const short color )
	{
		FillString( { short( x ), short( y ) }, c, size );
		FillColor( { short( x ), short( y ) }, color, size );
	}



	void WindowsUtility::RequestSleep( const uint32_t milli_seconds )
	{
		Sleep( milli_seconds );
	}



	typedef BOOL( WINAPI* LPFN_GetLogicalProcessorInformation )( PSYSTEM_LOGICAL_PROCESSOR_INFORMATION, PDWORD );
	int WindowsUtility::GetCPUCacheSize()
	{
		int ret = 0;

		LPFN_GetLogicalProcessorInformation glpi = ( LPFN_GetLogicalProcessorInformation )GetProcAddress( GetModuleHandle( TEXT( "kernel32" ) ), "GetLogicalProcessorInformation" );

		if( nullptr == glpi )
			return ret;

		//
		// ù ���ڷ� 0�� �ָ� ������ ������ ���� �ʿ��� �޸� ũ�⸦ ��ȯ �Ѵ�.
		//
		DWORD buffer_bytes = 0;
		glpi( 0, &buffer_bytes );

		//
		// �޸� �Ҵ�.
		//
		const DWORD size = buffer_bytes / sizeof( SYSTEM_LOGICAL_PROCESSOR_INFORMATION );
		SYSTEM_LOGICAL_PROCESSOR_INFORMATION* buffer = new SYSTEM_LOGICAL_PROCESSOR_INFORMATION[size];

		//
		// ���� ȹ��.
		//
		glpi( buffer, &buffer_bytes );

		//
		// ���
		//
		for( DWORD i = 0; size > i; ++i )
		{
			if( buffer[i].Relationship == _LOGICAL_PROCESSOR_RELATIONSHIP::RelationCache )
			{
				ret += buffer[i].Cache.Size;
			}
		}

		//
		//
		//
		delete[] buffer;

		return ret;
	}
}
