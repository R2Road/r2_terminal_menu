#include "inspector_file_test.h"

#include <filesystem>

#include "r2cm/r2cm_Inspector.h"
#include "r2cm/r2cm_ostream.h"

namespace inspector_file_test
{
	r2cm::iItem::TitleFunctionT File::GetTitleFunction() const
	{
		return []()->const char*
		{
			return "Inspector : File";
		};
	}
	r2cm::iItem::DoFunctionT File::GetDoFunction() const
	{
		return []()->r2cm::eItemLeaveAction
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

			return r2cm::eItemLeaveAction::Pause;
		};
	}



	r2cm::iItem::TitleFunctionT FileRange::GetTitleFunction() const
	{
		return []()->const char*
		{
			return "Inspector : File Range";
		};
	}
	r2cm::iItem::DoFunctionT FileRange::GetDoFunction() const
	{
		return []()->r2cm::eItemLeaveAction
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

			return r2cm::eItemLeaveAction::Pause;
		};
	}
}