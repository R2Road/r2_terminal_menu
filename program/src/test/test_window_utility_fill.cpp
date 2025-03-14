#include "test_window_utility_fill.h"

#include "r2tm/r2tm_Inspector.h"
#include "r2tm/r2tm_ostream.h"
#include "r2tm/r2tm_WindowUtility.h"

namespace test_window_utility_fill
{
	r2tm::TitleFunctionT FillColor::GetTitleFunction() const
	{
		return []()->const char*
		{
			return "WIndow Utility : FillColor";
		};
	}
	r2tm::DoFunctionT FillColor::GetDoFunction() const
	{
		return []()->r2tm::eDoLeaveAction
		{
			LS();

			{
				OUTPUT_SUBJECT( "�� ĭ�� �� ä���" );

				LF();

				r2tm::WindowUtility::FillColor( r2tm::WindowUtility::GetCursorPoint(), r2tm::WindowUtility::eColor::BG_Aqua );
				r2tm::WindowUtility::FillColor( r2tm::WindowUtility::GetCursorPoint() + r2tm::WindowUtility::CursorPoint{ 1, 0 }, r2tm::WindowUtility::eColor::BG_Green );
				r2tm::WindowUtility::FillColor( r2tm::WindowUtility::GetCursorPoint() + r2tm::WindowUtility::CursorPoint{ 2, 0 }, ( r2tm::WindowUtility::eColor::FG_Blue | r2tm::WindowUtility::eColor::BG_LightYellow ) );
				r2tm::WindowUtility::FillColor( r2tm::WindowUtility::GetCursorPoint() + r2tm::WindowUtility::CursorPoint{ 3, 0 }, ( r2tm::WindowUtility::eColor::FG_Green | r2tm::WindowUtility::eColor::BG_LightRed ) );

				//
				// Cursor Setup
				//
				r2tm::WindowUtility::MoveCursorPointWithClearBuffer( r2tm::WindowUtility::GetCursorPoint() + r2tm::WindowUtility::CursorPoint{ 0, 1 } );
			}

			LS();

			{
				OUTPUT_SUBJECT( "������ ���� ��ŭ �� ä���" );

				LF();

				r2tm::WindowUtility::FillColor( r2tm::WindowUtility::GetCursorPoint() + r2tm::WindowUtility::CursorPoint{ 0, 0 }, r2tm::WindowUtility::eColor::BG_Aqua, 4 );
				r2tm::WindowUtility::FillColor( r2tm::WindowUtility::GetCursorPoint() + r2tm::WindowUtility::CursorPoint{ 1, 1 }, r2tm::WindowUtility::eColor::BG_Green, 4 );
				r2tm::WindowUtility::FillColor( r2tm::WindowUtility::GetCursorPoint() + r2tm::WindowUtility::CursorPoint{ 2, 2 }, ( r2tm::WindowUtility::eColor::FG_Blue | r2tm::WindowUtility::eColor::BG_LightYellow ), 4 );
				r2tm::WindowUtility::FillColor( r2tm::WindowUtility::GetCursorPoint() + r2tm::WindowUtility::CursorPoint{ 3, 3 }, ( r2tm::WindowUtility::eColor::FG_Green | r2tm::WindowUtility::eColor::BG_LightRed ), 4 );

				//
				// Cursor Setup
				//
				r2tm::WindowUtility::MoveCursorPointWithClearBuffer( r2tm::WindowUtility::GetCursorPoint() + r2tm::WindowUtility::CursorPoint{ 0, 4 } );
			}

			LS();

			return r2tm::eDoLeaveAction::Pause;
		};
	}



	r2tm::TitleFunctionT FillCharacter::GetTitleFunction() const
	{
		return []()->const char*
		{
			return "WIndow Utility : FillCharacter";
		};
	}
	r2tm::DoFunctionT FillCharacter::GetDoFunction() const
	{
		return []()->r2tm::eDoLeaveAction
		{
			LS();

			{
				OUTPUT_SUBJECT( "�� ĭ�� ����/�� ä���" );

				LF();

				r2tm::WindowUtility::FillCharacter( r2tm::WindowUtility::GetCursorPoint() + r2tm::WindowUtility::CursorPoint{ 0, 0 }, 'T', r2tm::WindowUtility::eColor::BG_Green );
				r2tm::WindowUtility::FillCharacter( r2tm::WindowUtility::GetCursorPoint() + r2tm::WindowUtility::CursorPoint{ 1, 1 }, 'E', r2tm::WindowUtility::eColor::BG_Aqua );
				r2tm::WindowUtility::FillCharacter( r2tm::WindowUtility::GetCursorPoint() + r2tm::WindowUtility::CursorPoint{ 2, 2 }, 'S', ( r2tm::WindowUtility::eColor::FG_Green | r2tm::WindowUtility::eColor::BG_LightRed ) );
				r2tm::WindowUtility::FillCharacter( r2tm::WindowUtility::GetCursorPoint() + r2tm::WindowUtility::CursorPoint{ 3, 3 }, 'T', ( r2tm::WindowUtility::eColor::FG_Blue | r2tm::WindowUtility::eColor::BG_LightYellow ) );

				//
				// Cursor Setup
				//
				r2tm::WindowUtility::MoveCursorPointWithClearBuffer( r2tm::WindowUtility::GetCursorPoint() + r2tm::WindowUtility::CursorPoint{ 0, 4 } );
			}

			LS();

			return r2tm::eDoLeaveAction::Pause;
		};
	}



	r2tm::TitleFunctionT FillString_1::GetTitleFunction() const
	{
		return []()->const char*
		{
			return "WIndow Utility : FillString 1";
		};
	}
	r2tm::DoFunctionT FillString_1::GetDoFunction() const
	{
		return []()->r2tm::eDoLeaveAction
		{
			LS();

			DECLARATION_MAIN( using P = r2tm::WindowUtility::CursorPoint; );

			LS();

			{
				OUTPUT_SUBJECT( "���ڿ� ���" );

				LF();

				PROCESS_MAIN( r2tm::WindowUtility::FillString( r2tm::WindowUtility::GetCursorPoint(), "asdfgh", 6 ) );

				LF();
			}

			LS();

			{
				OUTPUT_SUBJECT( "���ڿ�, Offset" );

				LF();

				DECLARATION_MAIN( auto cursor_point = ( r2tm::WindowUtility::GetCursorPoint() + P{ 4, 5 } ) );
				PROCESS_MAIN( r2tm::WindowUtility::FillString( cursor_point, "asdfgh", 4 ) );

				r2tm::WindowUtility::MoveCursorPoint( cursor_point.x, cursor_point.y + 1 );
			}

			LS();

			{
				OUTPUT_SUBJECT( "���ڿ�, Offset, ����" );

				LF();

				DECLARATION_MAIN( auto cursor_point = ( r2tm::WindowUtility::GetCursorPoint() + P{ 4, 5 } ) );
				PROCESS_MAIN( r2tm::WindowUtility::FillString( cursor_point, "asdfgh", 4, r2tm::WindowUtility::eColor::BG_LightGreen ) );

				r2tm::WindowUtility::MoveCursorPoint( cursor_point.x, cursor_point.y + 1 );
			}

			LS();

			return r2tm::eDoLeaveAction::Pause;
		};
	}






	r2tm::TitleFunctionT FillString_2::GetTitleFunction() const
	{
		return []()->const char*
		{
			return "WIndow Utility : FillString 2";
		};
	}
	r2tm::DoFunctionT FillString_2::GetDoFunction() const
	{
		return []()->r2tm::eDoLeaveAction
		{
			LS();

			DECLARATION_MAIN( using P = r2tm::WindowUtility::CursorPoint; );

			LS();

			{
				OUTPUT_SUBJECT( "�� ���ڸ� ������ ���" );

				LF();

				DECLARATION_MAIN( auto cursor_point = ( r2tm::WindowUtility::GetCursorPoint() + P{ 4, 5 } ) );
				PROCESS_MAIN( r2tm::WindowUtility::FillString( cursor_point, 'z', 10 ) );

				r2tm::WindowUtility::MoveCursorPoint( cursor_point.x, cursor_point.y + 1 );
			}

			LS();

			{
				OUTPUT_SUBJECT( "�� ���ڸ� ������ �־� ������ ���" );

				LF();

				DECLARATION_MAIN( auto cursor_point = ( r2tm::WindowUtility::GetCursorPoint() + P{ 4, 5 } ) );
				PROCESS_MAIN( r2tm::WindowUtility::FillString( cursor_point, 'z', 10, r2tm::WindowUtility::eColor::BG_LightGreen ) );

				r2tm::WindowUtility::MoveCursorPoint( cursor_point.x, cursor_point.y + 1 );
			}

			LS();

			return r2tm::eDoLeaveAction::Pause;
		};
	}
}