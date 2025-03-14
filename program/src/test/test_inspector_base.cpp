#include "test_inspector_base.h"

#include "r2tm/r2tm_Inspector.h"
#include "r2tm/r2tm_ostream.h"

namespace test_inspector_base
{
	r2tm::TitleFunctionT Basic::GetTitleFunction() const
	{
		return []()->const char*
		{
			return "Inspector : Basic";
		};
	}
	r2tm::DoFunctionT Basic::GetDoFunction() const
	{
		return []()->r2tm::eDoLeaveAction
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

			{
				DECLARATION_MAIN( std::cout << "output string > process" "\n" );

				LF();

				DECLARATION_SUB( std::cout << "output string > process" "\n" );
			}

			LS();

			return r2tm::eDoLeaveAction::Pause;
		};
	}



	r2tm::TitleFunctionT Expect::GetTitleFunction() const
	{
		return []()->const char*
		{
			return "Inspector : Expect";
		};
	}
	r2tm::DoFunctionT Expect::GetDoFunction() const
	{
		return []()->r2tm::eDoLeaveAction
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

			return r2tm::eDoLeaveAction::Pause;
		};
	}



	r2tm::TitleFunctionT Size::GetTitleFunction() const
	{
		return []()->const char*
		{
			return "Inspector : Size";
		};
	}
	r2tm::DoFunctionT Size::GetDoFunction() const
	{
		return []()->r2tm::eDoLeaveAction
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

			return r2tm::eDoLeaveAction::Pause;
		};
	}



	r2tm::TitleFunctionT Code::GetTitleFunction() const
	{
		return []()->const char*
		{
			return "Inspector : Code";
		};
	}
	r2tm::DoFunctionT Code::GetDoFunction() const
	{
		return []()->r2tm::eDoLeaveAction
		{
			LS();

			{
				OUTPUT_CODE( printf( "%s", "asdf" ) );
			}

			LS();

			return r2tm::eDoLeaveAction::Pause;
		};
	}



	r2tm::TitleFunctionT String_Note_Subject_Comment::GetTitleFunction() const
	{
		return []()->const char*
		{
			return "Inspector : String, Note, Subject, Comment";
		};
	}
	r2tm::DoFunctionT String_Note_Subject_Comment::GetDoFunction() const
	{
		return []()->r2tm::eDoLeaveAction
		{
			LS();

			{
				OUTPUT_STRING( "   <= prefix | message =>   OUTPUT_STRING : output string~!~!~!" );
			}

			LS();

			{
				OUTPUT_NOTE( "   <= prefix | message =>   OUTPUT_NOTE : output note~!~!~!" );
			}

			LS();

			{
				OUTPUT_SUBJECT( "   <= prefix | message =>   OUTPUT_SUBJECT : output subject~!~!~!" );
			}

			LS();

			{
				OUTPUT_COMMENT( "   <= prefix | message =>   OUTPUT_COMMENT : output comment~!~!~!" );
			}

			LS();

			return r2tm::eDoLeaveAction::Pause;
		};
	}
}