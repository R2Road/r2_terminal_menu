#include "test_windows_utility_fill.hpp"

#include "r2tm/r2tm_inspector.hpp"
#include "r2tm/r2tm_ostream.hpp"
#include "r2tm/r2tm_windows_utility.hpp"

namespace test_windows_utility_fill
{
	r2tm::TitleFunctionT FillColor::GetTitleFunction() const
	{
		return []()->const char*
		{
			return "WIndows Utility : FillColor";
		};
	}
	r2tm::DoFunctionT FillColor::GetDoFunction() const
	{
		return []()->r2tm::eDoLeaveAction
		{
			LS();

			{
				OUTPUT_SUBJECT( "한 칸에 색 채우기" );

				LF();

				r2tm::WindowsUtility::FillColor( r2tm::WindowsUtility::GetCursorPoint(), r2tm::WindowsUtility::eColor::BG_Aqua );
				r2tm::WindowsUtility::FillColor( r2tm::WindowsUtility::GetCursorPoint() + r2tm::WindowsUtility::CursorPoint{ 1, 0 }, r2tm::WindowsUtility::eColor::BG_Green );
				r2tm::WindowsUtility::FillColor( r2tm::WindowsUtility::GetCursorPoint() + r2tm::WindowsUtility::CursorPoint{ 2, 0 }, ( r2tm::WindowsUtility::eColor::FG_Blue | r2tm::WindowsUtility::eColor::BG_LightYellow ) );
				r2tm::WindowsUtility::FillColor( r2tm::WindowsUtility::GetCursorPoint() + r2tm::WindowsUtility::CursorPoint{ 3, 0 }, ( r2tm::WindowsUtility::eColor::FG_Green | r2tm::WindowsUtility::eColor::BG_LightRed ) );

				//
				// Cursor Setup
				//
				r2tm::WindowsUtility::MoveCursorPointWithClearBuffer( r2tm::WindowsUtility::GetCursorPoint() + r2tm::WindowsUtility::CursorPoint{ 0, 1 } );
			}

			LS();

			{
				OUTPUT_SUBJECT( "지정된 길이 만큼 색 채우기" );

				LF();

				r2tm::WindowsUtility::FillColor( r2tm::WindowsUtility::GetCursorPoint() + r2tm::WindowsUtility::CursorPoint{ 0, 0 }, r2tm::WindowsUtility::eColor::BG_Aqua, 4 );
				r2tm::WindowsUtility::FillColor( r2tm::WindowsUtility::GetCursorPoint() + r2tm::WindowsUtility::CursorPoint{ 1, 1 }, r2tm::WindowsUtility::eColor::BG_Green, 4 );
				r2tm::WindowsUtility::FillColor( r2tm::WindowsUtility::GetCursorPoint() + r2tm::WindowsUtility::CursorPoint{ 2, 2 }, ( r2tm::WindowsUtility::eColor::FG_Blue | r2tm::WindowsUtility::eColor::BG_LightYellow ), 4 );
				r2tm::WindowsUtility::FillColor( r2tm::WindowsUtility::GetCursorPoint() + r2tm::WindowsUtility::CursorPoint{ 3, 3 }, ( r2tm::WindowsUtility::eColor::FG_Green | r2tm::WindowsUtility::eColor::BG_LightRed ), 4 );

				//
				// Cursor Setup
				//
				r2tm::WindowsUtility::MoveCursorPointWithClearBuffer( r2tm::WindowsUtility::GetCursorPoint() + r2tm::WindowsUtility::CursorPoint{ 0, 4 } );
			}

			LS();

			return r2tm::eDoLeaveAction::Pause;
		};
	}



	r2tm::TitleFunctionT FillCharacter::GetTitleFunction() const
	{
		return []()->const char*
		{
			return "WIndows Utility : FillCharacter";
		};
	}
	r2tm::DoFunctionT FillCharacter::GetDoFunction() const
	{
		return []()->r2tm::eDoLeaveAction
		{
			LS();

			{
				OUTPUT_SUBJECT( "한 칸에 글자/색 채우기" );

				LF();

				r2tm::WindowsUtility::FillCharacter( r2tm::WindowsUtility::GetCursorPoint() + r2tm::WindowsUtility::CursorPoint{ 0, 0 }, 'T', r2tm::WindowsUtility::eColor::BG_Green );
				r2tm::WindowsUtility::FillCharacter( r2tm::WindowsUtility::GetCursorPoint() + r2tm::WindowsUtility::CursorPoint{ 1, 1 }, 'E', r2tm::WindowsUtility::eColor::BG_Aqua );
				r2tm::WindowsUtility::FillCharacter( r2tm::WindowsUtility::GetCursorPoint() + r2tm::WindowsUtility::CursorPoint{ 2, 2 }, 'S', ( r2tm::WindowsUtility::eColor::FG_Green | r2tm::WindowsUtility::eColor::BG_LightRed ) );
				r2tm::WindowsUtility::FillCharacter( r2tm::WindowsUtility::GetCursorPoint() + r2tm::WindowsUtility::CursorPoint{ 3, 3 }, 'T', ( r2tm::WindowsUtility::eColor::FG_Blue | r2tm::WindowsUtility::eColor::BG_LightYellow ) );

				//
				// Cursor Setup
				//
				r2tm::WindowsUtility::MoveCursorPointWithClearBuffer( r2tm::WindowsUtility::GetCursorPoint() + r2tm::WindowsUtility::CursorPoint{ 0, 4 } );
			}

			LS();

			return r2tm::eDoLeaveAction::Pause;
		};
	}



	r2tm::TitleFunctionT FillString_1::GetTitleFunction() const
	{
		return []()->const char*
		{
			return "WIndows Utility : FillString 1";
		};
	}
	r2tm::DoFunctionT FillString_1::GetDoFunction() const
	{
		return []()->r2tm::eDoLeaveAction
		{
			LS();

			DECL_MAIN( using P = r2tm::WindowsUtility::CursorPoint; );

			LS();

			{
				OUTPUT_SUBJECT( "문자열 출력" );

				LF();

				PROC_MAIN( r2tm::WindowsUtility::FillString( r2tm::WindowsUtility::GetCursorPoint(), "asdfgh", 6 ) );

				LF();
			}

			LS();

			{
				OUTPUT_SUBJECT( "문자열, Offset" );

				LF();

				DECL_MAIN( auto cursor_point = ( r2tm::WindowsUtility::GetCursorPoint() + P{ 4, 5 } ) );
				PROC_MAIN( r2tm::WindowsUtility::FillString( cursor_point, "asdfgh", 4 ) );

				r2tm::WindowsUtility::MoveCursorPoint( cursor_point.x, cursor_point.y + 1 );
			}

			LS();

			{
				OUTPUT_SUBJECT( "문자열, Offset, 색상" );

				LF();

				DECL_MAIN( auto cursor_point = ( r2tm::WindowsUtility::GetCursorPoint() + P{ 4, 5 } ) );
				PROC_MAIN( r2tm::WindowsUtility::FillString( cursor_point, "asdfgh", 4, r2tm::WindowsUtility::eColor::BG_LightGreen ) );

				r2tm::WindowsUtility::MoveCursorPoint( cursor_point.x, cursor_point.y + 1 );
			}

			LS();

			return r2tm::eDoLeaveAction::Pause;
		};
	}






	r2tm::TitleFunctionT FillString_2::GetTitleFunction() const
	{
		return []()->const char*
		{
			return "WIndows Utility : FillString 2";
		};
	}
	r2tm::DoFunctionT FillString_2::GetDoFunction() const
	{
		return []()->r2tm::eDoLeaveAction
		{
			LS();

			DECL_MAIN( using P = r2tm::WindowsUtility::CursorPoint; );

			LS();

			{
				OUTPUT_SUBJECT( "한 문자를 여러개 찍기" );

				LF();

				DECL_MAIN( auto cursor_point = ( r2tm::WindowsUtility::GetCursorPoint() + P{ 4, 5 } ) );
				PROC_MAIN( r2tm::WindowsUtility::FillString( cursor_point, 'z', 10 ) );

				r2tm::WindowsUtility::MoveCursorPoint( cursor_point.x, cursor_point.y + 1 );
			}

			LS();

			{
				OUTPUT_SUBJECT( "한 문자를 색상을 넣어 여러개 찍기" );

				LF();

				DECL_MAIN( auto cursor_point = ( r2tm::WindowsUtility::GetCursorPoint() + P{ 4, 5 } ) );
				PROC_MAIN( r2tm::WindowsUtility::FillString( cursor_point, 'z', 10, r2tm::WindowsUtility::eColor::BG_LightGreen ) );

				r2tm::WindowsUtility::MoveCursorPoint( cursor_point.x, cursor_point.y + 1 );
			}

			LS();

			return r2tm::eDoLeaveAction::Pause;
		};
	}
}