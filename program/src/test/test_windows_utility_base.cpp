#include "test_windows_utility_base.h"

#include "r2tm/r2tm_Inspector.h"
#include "r2tm/r2tm_ostream.h"
#include "r2tm/r2tm_WindowsUtility.h"

namespace test_window_utility_base
{
	r2tm::TitleFunctionT CursorPointDeclaration::GetTitleFunction() const
	{
		return []()->const char*
		{
			return "WIndows Utility : CursorPoint - Declaration";
		};
	}
	r2tm::DoFunctionT CursorPointDeclaration::GetDoFunction() const
	{
		return []()->r2tm::eDoLeaveAction
		{
			LS();

			{
				OUTPUT_SUBJECT( "기본 생성자" );

				LF();

				DECLARATION_MAIN( r2tm::WindowsUtility::CursorPoint p );

				LF();

				OUTPUT_SIZE( p );

				LF();

				OUTPUT_BINARY( p );

				LF();

				EXPECT_EQ( 0, p.x );
				EXPECT_EQ( 0, p.y );
			}

			LS();

			{
				OUTPUT_SUBJECT( "인자 있는 생성자" );

				LF();

				DECLARATION_MAIN( r2tm::WindowsUtility::CursorPoint p( 2, 4 ) );

				LF();

				OUTPUT_BINARY( p );

				LF();

				EXPECT_EQ( 2, p.x );
				EXPECT_EQ( 4, p.y );
			}

			LS();

			{
				OUTPUT_SUBJECT( "no explicit" );
				OUTPUT_COMMENT( "warning : 4244" );

				LF();

#pragma warning( push )
#pragma warning( disable : 4244 )
				DECLARATION_MAIN( r2tm::WindowsUtility::CursorPoint p( 3.f, 5.f ) );
#pragma warning( pop )

				LF();

				OUTPUT_BINARY( p );

				LF();

				EXPECT_EQ( 3, p.x );
				EXPECT_EQ( 5, p.y );
			}

			LS();

			return r2tm::eDoLeaveAction::Pause;
		};
	}



	r2tm::TitleFunctionT CursorPointOperator::GetTitleFunction() const
	{
		return []()->const char*
		{
			return "WIndows Utility : CursorPoint - Operator";
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