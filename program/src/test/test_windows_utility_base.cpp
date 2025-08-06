#include "test_windows_utility_base.hpp"

#include "r2tm/r2tm_inspector.hpp"
#include "r2tm/r2tm_ostream.h"
#include "r2tm/r2tm_WindowsUtility.h"

namespace test_windows_utility_base
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
				OUTPUT_SUBJECT( "�⺻ ������" );

				LF();

				DECL_MAIN( r2tm::WindowsUtility::CursorPoint p );

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
				OUTPUT_SUBJECT( "���� �ִ� ������" );

				LF();

				DECL_MAIN( r2tm::WindowsUtility::CursorPoint p( 2, 4 ) );

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
				DECL_MAIN( r2tm::WindowsUtility::CursorPoint p( 3.f, 5.f ) );
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

				DECL_MAIN( r2tm::WindowsUtility::CursorPoint p );

				LF();

				PROC_MAIN( p = p + r2tm::WindowsUtility::CursorPoint( 2, 4 ) );

				LF();

				EXPECT_EQ( 2, p.x );
				EXPECT_EQ( 4, p.y );
			}

			LS();

			{
				OUTPUT_SUBJECT( "Operator +" );

				LF();

				DECL_MAIN( r2tm::WindowsUtility::CursorPoint p );

				LF();

				OUTPUT_SOURCE_READY_N_BEGIN;
				//p = p + { 2, 4 };
				OUTPUT_SOURCE_END;

				LF();

				OUTPUT_NOTE( "Ÿ�� ���� ���з� �� �ڵ�� ���� �۵����� ���Ѵ�." );
				OUTPUT_NOTE( "initialize-list ���� ������ �������� ���δ�." );
				OUTPUT_NOTE( "{ 2, 4 } �� �Լ� ���ڷ� ����� ���� Ÿ�� ���߿� �����Ѵ�." );
			}

			LS();

			{
				OUTPUT_SUBJECT( "Operator +=" );

				LF();

				DECL_MAIN( r2tm::WindowsUtility::CursorPoint p );

				LF();

				PROC_MAIN( p += r2tm::WindowsUtility::CursorPoint( 2, 4 ) );

				LF();

				EXPECT_EQ( 2, p.x );
				EXPECT_EQ( 4, p.y );
			}

			LS();

			return r2tm::eDoLeaveAction::Pause;
		};
	}
}