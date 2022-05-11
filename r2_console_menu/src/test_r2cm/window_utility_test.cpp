#include "pch.h"
#include "window_utility_test.h"

#include <conio.h> // _kbhit(), _getch()

#include "r2cm/r2cm_constant.h"
#include "r2cm/r2cm_Inspector.h"
#include "r2cm/r2cm_WindowUtility.h"

namespace window_utility_test
{
	r2cm::iItem::TitleFuncT MoveCursorWithClearBuffer::GetTitleFunction() const
	{
		return []()->const char*
		{
			return "Move Cursor With Clear Buffer";
		};
	}
	r2cm::iItem::DoFuncT MoveCursorWithClearBuffer::GetDoFunction()
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

			return r2cm::eItemLeaveAction::Pause;
		};
	}
}