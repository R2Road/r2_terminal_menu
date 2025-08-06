#include "test_windows_utility_cursor_buffer.hpp"

#include "r2tm/r2tm_inspector.hpp"
#include "r2tm/r2tm_ostream.h"
#include "r2tm/r2tm_WindowsUtility.h"

namespace test_windows_utility_cursor_buffer
{
	r2tm::TitleFunctionT MoveCursorWithClearBuffer::GetTitleFunction() const
	{
		return []()->const char*
		{
			return "WIndows Utility : Move Cursor With Clear Buffer";
		};
	}
	r2tm::DoFunctionT MoveCursorWithClearBuffer::GetDoFunction() const
	{
		return []()->r2tm::eDoLeaveAction
		{
			LS();

			DECL_MAIN( const auto p1 = r2tm::WindowsUtility::GetCursorPoint() );

			LS();

			{
				OUTPUT_STRING( "ddddddddddddddddduuuuuuuuuuummmmmmmmmmmyyyyyyyyyyyyyyyyyy" );
				OUTPUT_STRING( "ddddddddddddddddduuuuuuuuuuummmmmmmmmmmyyyyyyyyyyyyyyyyyy" );
			}

			LS();

			DECL_MAIN( const auto p2 = r2tm::WindowsUtility::GetCursorPoint() );

			LS();

			for( int i = 0; 20 > i; ++i )
			{
				OUTPUT_STRING( "ddddddddddddddddduuuuuuuuuuummmmmmmmmmmyyyyyyyyyyyyyyyyyy" );
			}

			LS();

			OUTPUT_SUBJECT( "[Any Key] p2 까지 라인 지우기" );
			WAIT_ANY_KEY;

			r2tm::WindowsUtility::MoveCursorPointWithClearBuffer( p2 );

			OUTPUT_SUBJECT( "[Any Key] p1 까지 라인 지우기" );
			WAIT_ANY_KEY;

			r2tm::WindowsUtility::MoveCursorPointWithClearBuffer( p1.x, p1.y );

			OUTPUT_SUBJECT( "[Any Key] End" );
			WAIT_ANY_KEY;

			return r2tm::eDoLeaveAction::None;
		};
	}
}