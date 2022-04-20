#include "pch.h"
#include "inspector_test.h"

#include <filesystem>

#include "base/r2cm_eTestEndAction.h"
#include "r2/r2_Inspector.h"

namespace inspector_test
{
	r2cm::iItem::TitleFuncT Basic::GetTitleFunction() const
	{
		return []()->const char*
		{
			return "Inspector : Basic";
		};
	}
	r2cm::iItem::DoFuncT Basic::GetDoFunction()
	{
		return []()->r2cm::eTestEndAction
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

				std::cout << r2::linefeed;

				DECLARATION_MAIN( int i = 0 );
				EXPECT_EQ( i, 0 );
				PROCESS_MAIN( i = 1 );
				PROCESS_SUB( i = 2 );
				EXPECT_NE( i, 1 );
				EXPECT_EQ( i, 2 );
			}
#pragma warning( pop )

			std::cout << r2::split;

			return r2cm::eTestEndAction::Pause;
		};
	}



	r2cm::iItem::TitleFuncT ShowFile::GetTitleFunction() const
	{
		return []()->const char*
		{
			return "Inspector : ShowFile";
		};
	}
	r2cm::iItem::DoFuncT ShowFile::GetDoFunction()
	{
		return []()->r2cm::eTestEndAction
		{
			std::cout << "# " << GetInstance().GetTitleFunction()( ) << " #" << r2::linefeed2;
			std::cout << "[ESC] End" << r2::linefeed;

			std::cout << r2::split;

			DECLARATION_MAIN( std::filesystem::path p = std::filesystem::current_path() );
			PROCESS_MAIN( p.append( "resources" ) );
			PROCESS_MAIN( p.append( "show_code_test_01.lua" ) );
			std::cout << "> " << p << r2::linefeed2;

			EXPECT_TRUE( std::filesystem::exists( p ) );

			std::cout << r2::split;

			{
				SHOW_FILE( p.string().c_str() );
			}

			std::cout << r2::split;

			return r2cm::eTestEndAction::Pause;
		};
	}
}