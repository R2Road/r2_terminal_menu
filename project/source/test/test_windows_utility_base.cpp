#include "test_windows_utility_base.hpp"

#include "r2tm/r2tm_inspector.hpp"
#include "r2tm/r2tm_ostream.hpp"
#include "r2tm/r2tm_windows_utility.hpp"

namespace test_windows_utility_base
{
	r2tm::eStatus CursorPointDeclaration::GetStatus() const
	{
		return r2tm::eStatus::Complete;
	}
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
				OUT_SUBJECT( "기본 생성자" );

				LF();

				DECL_MAIN( r2tm::WindowsUtility::CursorPoint p );

				LF();

				OUT_SIZE( p );

				LF();

				OUT_BINARY( p );

				LF();

				EXPECT_EQ( 0, p.x );
				EXPECT_EQ( 0, p.y );
			}

			LS();

			{
				OUT_SUBJECT( "인자 있는 생성자" );

				LF();

				DECL_MAIN( r2tm::WindowsUtility::CursorPoint p( 2, 4 ) );

				LF();

				OUT_BINARY( p );

				LF();

				EXPECT_EQ( 2, p.x );
				EXPECT_EQ( 4, p.y );
			}

			LS();

			{
				OUT_SUBJECT( "no explicit" );
				OUT_COMMENT( "warning : 4244" );

				LF();

#pragma warning( push )
#pragma warning( disable : 4244 )
				DECL_MAIN( r2tm::WindowsUtility::CursorPoint p( 3.f, 5.f ) );
#pragma warning( pop )

				LF();

				OUT_BINARY( p );

				LF();

				EXPECT_EQ( 3, p.x );
				EXPECT_EQ( 5, p.y );
			}

			LS();

			return r2tm::eDoLeaveAction::Pause;
		};
	}



	r2tm::eStatus CursorPointOperator::GetStatus() const
	{
		return r2tm::eStatus::Complete;
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
				OUT_SUBJECT( "Operator +" );

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
				OUT_SUBJECT( "Operator +" );

				LF();

				DECL_MAIN( r2tm::WindowsUtility::CursorPoint p );

				LF();

				OUT_SOURCE_READY_N_BEGIN;
				//p = p + { 2, 4 };
				OUT_SOURCE_END;

				LF();

				OUT_NOTE( "타입 유추 실패로 위 코드는 정상 작동하지 못한다." );
				OUT_NOTE( "initialize-list 와의 경합이 원인으로 보인다." );
				OUT_NOTE( "{ 2, 4 } 를 함수 인자로 사용한 경우는 타입 유추에 성공한다." );
			}

			LS();

			{
				OUT_SUBJECT( "Operator +=" );

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