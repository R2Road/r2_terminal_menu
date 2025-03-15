#include "test_window_utility_cursor_buffer.h"

#include <conio.h> // _kbhit(), _getch()

#include "r2tm/r2tm_Inspector.h"
#include "r2tm/r2tm_ostream.h"
#include "r2tm/r2tm_WindowsUtility.h"

namespace test_window_utility_cursor_buffer
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

			DECLARATION_MAIN( const auto cursor_point_1 = r2tm::WindowsUtility::GetCursorPoint() );

			LS();

			{
				std::cout << "ddddddddddddddddduuuuuuuuuuummmmmmmmmmmyyyyyyyyyyyyyyyyyy" << r2tm::linefeed;
				std::cout << "ddddddddddddddddduuuuuuuuuuummmmmmmmmmmyyyyyyyyyyyyyyyyyy" << r2tm::linefeed;
			}

			LS();

			DECLARATION_MAIN( const auto cursor_point_2 = r2tm::WindowsUtility::GetCursorPoint() );

			LS();

			for( int i = 0; 20 > i; ++i )
			{
				std::cout << "ddddddddddddddddduuuuuuuuuuummmmmmmmmmmyyyyyyyyyyyyyyyyyy" << r2tm::linefeed;
			}

			LS();

			std::cout << "[Any Key] Move Cursor 2 with Clear Buffer";
			_getch();

			PROCESS_MAIN( r2tm::WindowsUtility::MoveCursorPointWithClearBuffer( cursor_point_2 ) );

			std::cout << "[Any Key] Move Cursor 1 with Clear Buffer";
			_getch();

			PROCESS_MAIN( r2tm::WindowsUtility::MoveCursorPointWithClearBuffer( cursor_point_1.x, cursor_point_1.y ) );

			std::cout << "[Any Key] End";
			_getch();

			return r2tm::eDoLeaveAction::None;
		};
	}
}