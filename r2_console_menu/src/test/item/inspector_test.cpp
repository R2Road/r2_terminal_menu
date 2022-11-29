#include "inspector_test.h"

#include "r2cm/r2cm_Inspector.h"
#include "r2cm/r2cm_ostream.h"

namespace inspector_test
{
	r2cm::iItem::TitleFunctionT Basic::GetTitleFunction() const
	{
		return []()->const char*
		{
			return "Inspector : Basic";
		};
	}
	r2cm::iItem::DoFunctionT Basic::GetDoFunction() const
	{
		return []()->r2cm::eItemLeaveAction
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

			return r2cm::eItemLeaveAction::Pause;
		};
	}



	r2cm::iItem::TitleFunctionT Expect::GetTitleFunction() const
	{
		return []()->const char*
		{
			return "Inspector : Expect";
		};
	}
	r2cm::iItem::DoFunctionT Expect::GetDoFunction() const
	{
		return []()->r2cm::eItemLeaveAction
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

			std::cout << r2cm::split;

			{
				DECLARATION_MAIN( int i = 0 );
				DECLARATION_MAIN( int j = i );
				EXPECT_EQ( i, j );
				PROCESS_MAIN( i = 1 );
				PROCESS_MAIN( i = 2 );
				EXPECT_NE( i, 1 );
				EXPECT_EQ( i, 2 );
			}
#pragma warning( pop )

			std::cout << r2cm::split;

			return r2cm::eItemLeaveAction::Pause;
		};
	}



	r2cm::iItem::TitleFunctionT Code::GetTitleFunction() const
	{
		return []()->const char*
		{
			return "Inspector : Code";
		};
	}
	r2cm::iItem::DoFunctionT Code::GetDoFunction() const
	{
		return []()->r2cm::eItemLeaveAction
		{
			std::cout << r2cm::split;

			{
				OUTPUT_CODE( printf( "%s", "asdf" ) );
			}

			std::cout << r2cm::split;

			return r2cm::eItemLeaveAction::Pause;
		};
	}



	r2cm::iItem::TitleFunctionT Note::GetTitleFunction() const
	{
		return []()->const char*
		{
			return "Inspector : Note";
		};
	}
	r2cm::iItem::DoFunctionT Note::GetDoFunction() const
	{
		return []()->r2cm::eItemLeaveAction
		{
			std::cout << r2cm::split;

			{
				OUTPUT_NOTE( "output note~!~!~!" );
				OUTPUT_COMMENT( "output comment~!~!~!" );
			}

			std::cout << r2cm::split;

			return r2cm::eItemLeaveAction::Pause;
		};
	}
}