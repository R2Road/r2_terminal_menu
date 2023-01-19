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
			std::cout << r2cm::split;

			{
				DECLARATION_MAIN( int i = 0; );

				std::cout << r2cm::linefeed;

				PROCESS_MAIN( i = 1234567; );

				std::cout << r2cm::linefeed;

				OUTPUT_VALUE( i );
			}

			std::cout << r2cm::split;

			{
				DECLARATION_SUB( int j = 0; );

				std::cout << r2cm::linefeed;

				PROCESS_SUB( j = 7654321; );

				std::cout << r2cm::linefeed;

				OUTPUT_VALUE( j );
			}

			std::cout << r2cm::split;

			{
				OUTPUT_VALUE( 11111 * 7 );
			}

			std::cout << r2cm::split;

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
			std::cout << r2cm::split;

#pragma warning( push )
#pragma warning( disable : 4127 )
			{
				EXPECT_TRUE( 1 == 1 );
				EXPECT_TRUE( 1 == 0 );

				std::cout << r2cm::linefeed;

				EXPECT_FALSE( 1 == 1 );
				EXPECT_FALSE( 1 == 0 );

				std::cout << r2cm::linefeed;

				EXPECT_EQ( 1, 1 );
				EXPECT_EQ( 1, 0 );

				std::cout << r2cm::linefeed;

				EXPECT_NE( 1, 1 );
				EXPECT_NE( 1, 0 );

				std::cout << r2cm::linefeed;

				EXPECT_GT( 1, 1 );
				EXPECT_GT( 1, 0 );

				std::cout << r2cm::linefeed;

				EXPECT_LT( 1, 1 );
				EXPECT_LT( 0, 1 );

				std::cout << r2cm::linefeed;

				EXPECT_GE( 1, 1 );
				EXPECT_GE( 0, 1 );

				std::cout << r2cm::linefeed;

				EXPECT_LE( 1, 1 );
				EXPECT_LE( 1, 0 );

			}
#pragma warning( pop )

			std::cout << r2cm::split;

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
				OUTPUT_NOTE( "기존의 size 출력 방식" );

				LF();

				OUTPUT_VALUE( sizeof( int ) );
			}

			LS();

			{
				OUTPUT_NOTE( "OUTPUT_SIZE 사용" );

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
			std::cout << r2cm::split;

			{
				OUTPUT_CODE( printf( "%s", "asdf" ) );
			}

			std::cout << r2cm::split;

			return r2cm::eDoLeaveAction::Pause;
		};
	}



	r2cm::TitleFunctionT Note_Subject_Comment::GetTitleFunction() const
	{
		return []()->const char*
		{
			return "Inspector : Note, Subject, Comment";
		};
	}
	r2cm::DoFunctionT Note_Subject_Comment::GetDoFunction() const
	{
		return []()->r2cm::eDoLeaveAction
		{
			std::cout << r2cm::split;

			{
				OUTPUT_NOTE( "output note~!~!~!" );
				OUTPUT_SUBJECT( "output subject~!~!~!" );
				OUTPUT_COMMENT( "output comment~!~!~!" );
			}

			std::cout << r2cm::split;

			return r2cm::eDoLeaveAction::Pause;
		};
	}
}