#include "test_window_utility_base.h"

#include "r2tm/r2tm_Inspector.h"
#include "r2tm/r2tm_ostream.h"
#include "r2tm/r2tm_WindowsUtility.h"

namespace test_window_utility_base
{
	r2tm::TitleFunctionT CursorPointOperator::GetTitleFunction() const
	{
		return []()->const char*
		{
			return "WIndow Utility : CursorPoint - Operator";
		};
	}
	r2tm::DoFunctionT CursorPointOperator::GetDoFunction() const
	{
		return []()->r2tm::eDoLeaveAction
		{
			LS();

			{
				OUTPUT_SUBJECT( "Operator +" );

				LF();

				DECLARATION_MAIN( r2tm::WindowsUtility::CursorPoint p );

				LF();

				PROCESS_MAIN( p = p + r2tm::WindowsUtility::CursorPoint( 2, 4 ) );

				LF();

				EXPECT_EQ( 2, p.x );
				EXPECT_EQ( 4, p.y );
			}

			LS();

			{
				OUTPUT_SUBJECT( "Operator +=" );

				LF();

				DECLARATION_MAIN( r2tm::WindowsUtility::CursorPoint p );

				LF();

				PROCESS_MAIN( p += r2tm::WindowsUtility::CursorPoint( 2, 4 ) );

				LF();

				EXPECT_EQ( 2, p.x );
				EXPECT_EQ( 4, p.y );
			}

			LS();

			return r2tm::eDoLeaveAction::Pause;
		};
	}
}