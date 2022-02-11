#include "pch.h"
#include "inspector_test.h"

#include <conio.h> // _getch

#include "base/r2_eTestResult.h"
#include "base/r2_Inspector.h"

namespace inspector_test
{
	r2::iTest::TitleFunc Basic::GetTitleFunction() const
	{
		return []()->const char*
		{
			return "Inspector : Basic";
		};
	}
	r2::iTest::DoFunc Basic::GetDoFunction()
	{
		return []()->r2::eTestEndAction
		{
			std::cout << "# " << GetInstance().GetTitleFunction()( ) << " #" << r2::linefeed2;
			std::cout << "[ESC] End" << r2::linefeed;

			std::cout << r2::split;

#pragma warning( push )
#pragma warning( disable : 4127 )
			{
				EXPECT_TRUE( 1 == 1 );
				EXPECT_TRUE( 1 == 0 );

				std::cout << r2::linefeed;

				EXPECT_FALSE( 1 == 1 );
				EXPECT_FALSE( 1 == 0 );

				std::cout << r2::linefeed;

				EXPECT_EQ( 1, 1 );
				EXPECT_EQ( 1, 0 );

				std::cout << r2::linefeed;

				EXPECT_NE( 1, 1 );
				EXPECT_NE( 1, 0 );

				std::cout << r2::linefeed;

				EXPECT_GT( 1, 1 );
				EXPECT_GT( 1, 0 );

				std::cout << r2::linefeed;

				EXPECT_LT( 1, 1 );
				EXPECT_LT( 0, 1 );

				std::cout << r2::linefeed;

				EXPECT_GE( 1, 1 );
				EXPECT_GE( 0, 1 );

				std::cout << r2::linefeed;

				EXPECT_LE( 1, 1 );
				EXPECT_LE( 1, 0 );
			}
#pragma warning( pop )

			std::cout << r2::split;

			return r2::eTestEndAction::Pause;
		};
	}
}