#include "test_window_utility.h"

#include <conio.h> // _kbhit(), _getch()

#include "r2tm/r2tm_Inspector.h"
#include "r2tm/r2tm_ostream.h"
#include "r2tm/r2tm_WindowUtility.h"

namespace test_window_utility
{
	r2tm::TitleFunctionT MoveCursorWithClearBuffer::GetTitleFunction() const
	{
		return []()->const char*
		{
			return "WIndow Utility : Move Cursor With Clear Buffer";
		};
	}
	r2tm::DoFunctionT MoveCursorWithClearBuffer::GetDoFunction() const
	{
		return []()->r2tm::eDoLeaveAction
		{
			LS();

			{
				std::cout << "ddddddddddddddddduuuuuuuuuuummmmmmmmmmmyyyyyyyyyyyyyyyyyy" << r2tm::linefeed;
				std::cout << "ddddddddddddddddduuuuuuuuuuummmmmmmmmmmyyyyyyyyyyyyyyyyyy" << r2tm::linefeed;
			}

			LS();

			DECLARATION_MAIN( const auto last_cursor_point = r2tm::WindowUtility::GetCursorPoint() );

			LS();

			for( int i = 0; 20 > i; ++i )
			{
				std::cout << "ddddddddddddddddduuuuuuuuuuummmmmmmmmmmyyyyyyyyyyyyyyyyyy" << r2tm::linefeed;
			}

			LS();

			std::cout << "[Any Key] Move Cursor with Clear Buffer";
			_getch();

			PROCESS_MAIN( r2tm::WindowUtility::MoveCursorPointWithClearBuffer( last_cursor_point ) );

			std::cout << "[Any Key] End";
			_getch();

			return r2tm::eDoLeaveAction::None;
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
				r2tm::WindowUtility::FillColor( r2tm::WindowUtility::GetCursorPoint(), r2tm::WindowUtility::eColor::BG_Aqua );
				r2tm::WindowUtility::FillCharacter( r2tm::WindowUtility::GetCursorPoint(), 'T' );

				r2tm::WindowUtility::FillColor( r2tm::WindowUtility::GetCursorPoint() + r2tm::WindowUtility::CursorPoint{ 1, 0 }, r2tm::WindowUtility::eColor::BG_Green );
				r2tm::WindowUtility::FillCharacter( r2tm::WindowUtility::GetCursorPoint() + r2tm::WindowUtility::CursorPoint{ 1, 0 }, 'E' );

				r2tm::WindowUtility::FillColor( r2tm::WindowUtility::GetCursorPoint() + r2tm::WindowUtility::CursorPoint{ 2, 0 }, ( r2tm::WindowUtility::eColor::FG_Blue | r2tm::WindowUtility::eColor::BG_LightYellow ) );
				r2tm::WindowUtility::FillCharacter( r2tm::WindowUtility::GetCursorPoint() + r2tm::WindowUtility::CursorPoint{ 2, 0 }, 'S' );

				r2tm::WindowUtility::FillColor( r2tm::WindowUtility::GetCursorPoint() + r2tm::WindowUtility::CursorPoint{ 3, 0 }, ( r2tm::WindowUtility::eColor::FG_Green | r2tm::WindowUtility::eColor::BG_LightRed ) );
				r2tm::WindowUtility::FillCharacter( r2tm::WindowUtility::GetCursorPoint() + r2tm::WindowUtility::CursorPoint{ 3, 0 }, 'T' );

				LF();
			}

			LS();

			return r2tm::eDoLeaveAction::Pause;
		};
	}



	r2tm::TitleFunctionT FillString::GetTitleFunction() const
	{
		return []()->const char*
		{
			return "WIndow Utility : FillString";
		};
	}
	r2tm::DoFunctionT FillString::GetDoFunction() const
	{
		return []()->r2tm::eDoLeaveAction
		{
			LS();

			{
				PROCESS_MAIN( r2tm::WindowUtility::FillString( r2tm::WindowUtility::GetCursorPoint(), "asdfgh", 6 ) );

				LF();
			}

			LS();

			{
				DECLARATION_MAIN( auto cursor_point = r2tm::WindowUtility::GetCursorPoint() );
				PROCESS_MAIN( cursor_point.x += 4 );
				PROCESS_MAIN( cursor_point.y += 6 );
				PROCESS_MAIN( r2tm::WindowUtility::FillString( cursor_point, "asdfgh", 4 ) );

				r2tm::WindowUtility::MoveCursorPoint( cursor_point.x, cursor_point.y + 1 );
			}

			LS();

			{
				DECLARATION_MAIN( auto cursor_point = r2tm::WindowUtility::GetCursorPoint() );
				PROCESS_MAIN( cursor_point.x += 4 );
				PROCESS_MAIN( cursor_point.y += 6 );
				PROCESS_MAIN( r2tm::WindowUtility::FillString( cursor_point, "asdfgh", 4, r2tm::WindowUtility::eColor::BG_LightGreen ) );

				r2tm::WindowUtility::MoveCursorPoint( cursor_point.x, cursor_point.y + 1 );
			}

			LS();

			return r2tm::eDoLeaveAction::Pause;
		};
	}
}