#include "test_inspector_base.h"

#include "r2cm/r2cm_Inspector.h"
#include "r2cm/r2cm_ostream.h"

namespace test_inspector_base
{
	r2cm::TitleFunctionT Basic::GetTitleFunction() const
	{
		return []()->const char*
		{
			return "Inspector : Basic";
		};
	}
	r2cm::DoFunctionT Basic::GetDoFunction() const
	{
		return []()->r2cm::eDoLeaveAction
		{
			LS();

			{
				DECLARATION_MAIN( int i = 0; );

				LF();

				PROCESS_MAIN( i = 1234567; );

				LF();

				OUTPUT_VALUE( i );
			}

			LS();

			{
				DECLARATION_SUB( int j = 0; );

				LF();

				PROCESS_SUB( j = 7654321; );

				LF();

				OUTPUT_VALUE( j );
			}

			LS();

			{
				OUTPUT_VALUE( 11111 * 7 );
			}

			LS();

			return r2cm::eDoLeaveAction::Pause;
		};
	}



	r2cm::TitleFunctionT Expect::GetTitleFunction() const
	{
		return []()->const char*
		{
			return "Inspector : Expect";
		};
	}
	r2cm::DoFunctionT Expect::GetDoFunction() const
	{
		return []()->r2cm::eDoLeaveAction
		{
			LS();

#pragma warning( push )
#pragma warning( disable : 4127 )
			{
				EXPECT_TRUE( 1 == 1 );
				EXPECT_TRUE( 1 == 0 );

				LF();

				EXPECT_FALSE( 1 == 1 );
				EXPECT_FALSE( 1 == 0 );

				LF();

				EXPECT_EQ( 1, 1 );
				EXPECT_EQ( 1, 0 );

				LF();

				EXPECT_NE( 1, 1 );
				EXPECT_NE( 1, 0 );

				LF();

				EXPECT_GT( 1, 1 );
				EXPECT_GT( 1, 0 );

				LF();

				EXPECT_LT( 1, 1 );
				EXPECT_LT( 0, 1 );

				LF();

				EXPECT_GE( 1, 1 );
				EXPECT_GE( 0, 1 );

				LF();

				EXPECT_LE( 1, 1 );
				EXPECT_LE( 1, 0 );

			}
#pragma warning( pop )

			LS();

			return r2cm::eDoLeaveAction::Pause;
		};
	}



	r2cm::TitleFunctionT Size::GetTitleFunction() const
	{
		return []()->const char*
		{
			return "Inspector : Size";
		};
	}
	r2cm::DoFunctionT Size::GetDoFunction() const
	{
		return []()->r2cm::eDoLeaveAction
		{
			LS();

			{
				OUTPUT_SUBJECT( "기존의 size 출력 방식" );

				LF();

				OUTPUT_VALUE( sizeof( int ) );
			}

			LS();

			{
				OUTPUT_SUBJECT( "OUTPUT_SIZE 사용" );

				LF();

				OUTPUT_SIZE( int );

				LF();

				DECLARATION_MAIN( struct S { int i; } );
				OUTPUT_SIZE( S );
			}

			LS();

			return r2cm::eDoLeaveAction::Pause;
		};
	}



	r2cm::TitleFunctionT Code::GetTitleFunction() const
	{
		return []()->const char*
		{
			return "Inspector : Code";
		};
	}
	r2cm::DoFunctionT Code::GetDoFunction() const
	{
		return []()->r2cm::eDoLeaveAction
		{
			LS();

			{
				OUTPUT_CODE( printf( "%s", "asdf" ) );
			}

			LS();

			return r2cm::eDoLeaveAction::Pause;
		};
	}



	r2cm::TitleFunctionT String_Note_Subject_Comment::GetTitleFunction() const
	{
		return []()->const char*
		{
			return "Inspector : String, Note, Subject, Comment";
		};
	}
	r2cm::DoFunctionT String_Note_Subject_Comment::GetDoFunction() const
	{
		return []()->r2cm::eDoLeaveAction
		{
			LS();

			{
				OUTPUT_STRING( "output string~!~!~!" );

				LF();

				OUTPUT_NOTE( "output note~!~!~!" );

				LF();

				OUTPUT_SUBJECT( "output subject~!~!~!" );

				LF();

				OUTPUT_COMMENT( "output comment~!~!~!" );
			}

			LS();

			return r2cm::eDoLeaveAction::Pause;
		};
	}
}