#include "window_utility_test.h"

#include <conio.h> // _kbhit(), _getch()

#include "r2cm/r2cm_Inspector.h"
#include "r2cm/r2cm_ostream.h"
#include "r2cm/r2cm_WindowUtility.h"

namespace window_utility_test
{
	r2cm::iItem::TitleFunctionT MoveCursorWithClearBuffer::GetTitleFunction() const
	{
		return []()->const char*
		{
			return "WIndow Utility : Move Cursor With Clear Buffer";
		};
	}
	r2cm::iItem::DoFunctionT MoveCursorWithClearBuffer::GetDoFunction()
	{
		return []()->r2cm::eItemLeaveAction
		{
			std::cout << "# " << GetInstance().GetTitleFunction()( ) << " #" << r2cm::linefeed;

			std::cout << r2cm::split;

			{
				std::cout << "ddddddddddddddddduuuuuuuuuuummmmmmmmmmmyyyyyyyyyyyyyyyyyy" << r2cm::linefeed;
				std::cout << "ddddddddddddddddduuuuuuuuuuummmmmmmmmmmyyyyyyyyyyyyyyyyyy" << r2cm::linefeed;
			}

			std::cout << r2cm::split;

			DECLARATION_MAIN( const auto last_cursor_point = r2cm::WindowUtility::GetCursorPoint() );

			std::cout << r2cm::split;

			for( int i = 0; 20 > i; ++i )
			{
				std::cout << "ddddddddddddddddduuuuuuuuuuummmmmmmmmmmyyyyyyyyyyyyyyyyyy" << r2cm::linefeed;
			}

			std::cout << r2cm::split;

			std::cout << "[Any Key] Move Cursor with Clear Buffer";
			_getch();

			PROCESS_MAIN( r2cm::WindowUtility::MoveCursorPointWithClearBuffer( last_cursor_point ) );

			std::cout << "[Any Key] End";
			_getch();

			return r2cm::eItemLeaveAction::None;
		};
	}



	r2cm::iItem::TitleFunctionT FillColor::GetTitleFunction() const
	{
		return []()->const char*
		{
			return "WIndow Utility : FillColor";
		};
	}
	r2cm::iItem::DoFunctionT FillColor::GetDoFunction()
	{
		return []()->r2cm::eItemLeaveAction
		{
			std::cout << "# " << GetInstance().GetTitleFunction()( ) << " #" << r2cm::linefeed2;

			std::cout << r2cm::split;

			{
				r2cm::WindowUtility::FillColor( r2cm::WindowUtility::GetCursorPoint(), r2cm::WindowUtility::eColor::BG_Aqua );
				r2cm::WindowUtility::FillCharacter( r2cm::WindowUtility::GetCursorPoint(), 'T' );

				r2cm::WindowUtility::FillColor( r2cm::WindowUtility::GetCursorPoint() + r2cm::WindowUtility::CursorPoint{ 1, 0 }, r2cm::WindowUtility::eColor::BG_Green );
				r2cm::WindowUtility::FillCharacter( r2cm::WindowUtility::GetCursorPoint() + r2cm::WindowUtility::CursorPoint{ 1, 0 }, 'E' );

				r2cm::WindowUtility::FillColor( r2cm::WindowUtility::GetCursorPoint() + r2cm::WindowUtility::CursorPoint{ 2, 0 }, ( r2cm::WindowUtility::eColor::FG_Blue | r2cm::WindowUtility::eColor::BG_LightYellow ) );
				r2cm::WindowUtility::FillCharacter( r2cm::WindowUtility::GetCursorPoint() + r2cm::WindowUtility::CursorPoint{ 2, 0 }, 'S' );

				r2cm::WindowUtility::FillColor( r2cm::WindowUtility::GetCursorPoint() + r2cm::WindowUtility::CursorPoint{ 3, 0 }, ( r2cm::WindowUtility::eColor::FG_Green | r2cm::WindowUtility::eColor::BG_LightLed ) );
				r2cm::WindowUtility::FillCharacter( r2cm::WindowUtility::GetCursorPoint() + r2cm::WindowUtility::CursorPoint{ 3, 0 }, 'T' );
			}

			std::cout << r2cm::split;

			return r2cm::eItemLeaveAction::Pause;
		};
	}
}