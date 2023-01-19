#include "test_inspector_file.h"

#include <filesystem>

#include "r2cm/r2cm_Inspector.h"
#include "r2cm/r2cm_ostream.h"

namespace test_inspector_file
{
	r2cm::TitleFunctionT File::GetTitleFunction() const
	{
		return []()->const char*
		{
			return "Inspector : File";
		};
	}
	r2cm::DoFunctionT File::GetDoFunction() const
	{
		return []()->r2cm::eDoLeaveAction
		{
			std::cout << r2cm::split;

			{
				DECLARATION_MAIN( std::filesystem::path p = std::filesystem::current_path() );
				PROCESS_MAIN( p.append( "resources" ).append( "inspector_file_test_helper_file_01.lua" ) );
				std::cout << "> " << p << r2cm::linefeed2;

				EXPECT_TRUE( std::filesystem::exists( p ) );

				std::cout << r2cm::linefeed;

				OUTPUT_FILE( p.string().c_str() );
			}

			std::cout << r2cm::split;

			{
				DECLARATION_MAIN( std::filesystem::path p = std::filesystem::current_path() );
				PROCESS_MAIN( p.append( "resources" ).append( "inspector_file_test_helper_file_01.cpp" ) );
				std::cout << "> " << p << r2cm::linefeed2;

				EXPECT_TRUE( std::filesystem::exists( p ) );

				std::cout << r2cm::linefeed;

				OUTPUT_FILE( p.string().c_str() );
			}

			std::cout << r2cm::split;

			return r2cm::eDoLeaveAction::Pause;
		};
	}



	r2cm::TitleFunctionT FileRange::GetTitleFunction() const
	{
		return []()->const char*
		{
			return "Inspector : File Range";
		};
	}
	r2cm::DoFunctionT FileRange::GetDoFunction() const
	{
		return []()->r2cm::eDoLeaveAction
		{
			std::cout << r2cm::split;

			{
				DECLARATION_MAIN( std::filesystem::path p = std::filesystem::current_path() );
				PROCESS_MAIN( p.append( "resources" ).append( "inspector_file_test_helper_file_01.lua" ) );
				std::cout << "> " << p << r2cm::linefeed2;

				EXPECT_TRUE( std::filesystem::exists( p ) );

				std::cout << r2cm::linefeed;

				OUTPUT_FILE_RANGE( p.string().c_str(), 1, 3 );
			}

			std::cout << r2cm::split;

			{
				DECLARATION_MAIN( std::filesystem::path p = std::filesystem::current_path() );
				PROCESS_MAIN( p.append( "resources" ).append( "inspector_file_test_helper_file_01.cpp" ) );
				std::cout << "> " << p << r2cm::linefeed2;

				EXPECT_TRUE( std::filesystem::exists( p ) );

				std::cout << r2cm::linefeed;

				OUTPUT_FILE_RANGE( p.string().c_str(), 5, 10 );
			}

			std::cout << r2cm::split;

			return r2cm::eDoLeaveAction::Pause;
		};
	}
}