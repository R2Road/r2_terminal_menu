#include "test_inspector_file.h"

#include <filesystem>

#include "r2tm/r2tm_Inspector.h"
#include "r2tm/r2tm_ostream.h"

namespace test_inspector_file
{
	r2tm::TitleFunctionT File::GetTitleFunction() const
	{
		return []()->const char*
		{
			return "Inspector : File";
		};
	}
	r2tm::DoFunctionT File::GetDoFunction() const
	{
		return []()->r2tm::eDoLeaveAction
		{
			LS();

			OUTPUT_SUBJECT( "OUTPUT_FILE" );

			LS();

			{
				DECLARATION_MAIN( std::filesystem::path p = std::filesystem::current_path() );
				PROCESS_MAIN( p.append( "resources" ).append( "inspector_file_test_helper_file_01.lua" ) );
				
				LF();

				EXPECT_TRUE( std::filesystem::exists( p ) );

				LF();

				OUTPUT_FILE( p.string().c_str() );
			}

			LS();

			{
				DECLARATION_MAIN( std::filesystem::path p = std::filesystem::current_path() );
				PROCESS_MAIN( p.append( "resources" ).append( "inspector_file_test_helper_file_01.cpp" ) );
				
				LF();

				EXPECT_TRUE( std::filesystem::exists( p ) );

				LF();

				OUTPUT_FILE( p.string().c_str() );
			}

			LS();

			return r2tm::eDoLeaveAction::Pause;
		};
	}



	r2tm::TitleFunctionT FileRange_1::GetTitleFunction() const
	{
		return []()->const char*
		{
			return "Inspector : File Range 1";
		};
	}
	r2tm::DoFunctionT FileRange_1::GetDoFunction() const
	{
		return []()->r2tm::eDoLeaveAction
		{
			LS();

			OUTPUT_SUBJECT( "OUTPUT_FILE_RANGE" );

			LS();

			{
				DECLARATION_MAIN( std::filesystem::path p = std::filesystem::current_path() );
				PROCESS_MAIN( p.append( "resources" ).append( "inspector_file_test_helper_file_01.lua" ) );

				LF();

				EXPECT_TRUE( std::filesystem::exists( p ) );

				LF();

				OUTPUT_FILE_RANGE( p.string().c_str(), 1, 3 );
			}

			LS();

			{
				DECLARATION_MAIN( std::filesystem::path p = std::filesystem::current_path() );
				PROCESS_MAIN( p.append( "resources" ).append( "inspector_file_test_helper_file_01.cpp" ) );
				
				LF();

				EXPECT_TRUE( std::filesystem::exists( p ) );

				LF();

				OUTPUT_FILE_RANGE( p.string().c_str(), 5, 10 );
			}

			LS();

			return r2tm::eDoLeaveAction::Pause;
		};
	}



	r2tm::TitleFunctionT FileRange_2::GetTitleFunction() const
	{
		return []()->const char*
		{
			return "Inspector : File Range 2";
		};
	}
	r2tm::DoFunctionT FileRange_2::GetDoFunction() const
	{
		return []()->r2tm::eDoLeaveAction
		{
			LS();

			OUTPUT_SUBJECT( "OUTPUT_FILE_RANGE : min > max" );

			LS();

			{
				DECLARATION_MAIN( std::filesystem::path p = std::filesystem::current_path() );
				PROCESS_MAIN( p.append( "resources" ).append( "inspector_file_test_helper_file_01.cpp" ) );

				LF();

				EXPECT_TRUE( std::filesystem::exists( p ) );

				SS();

				PROCESS_MAIN( OUTPUT_FILE_RANGE( p.string().c_str(), 10, 5 ) );
			}

			LS();

			{
				OUTPUT_NOTE( "min > max ���� ���� ����." );
				OUTPUT_NOTE( "File ������ �ƹ��͵� ��µ��� �ʴ´�." );
			}

			LS();

			return r2tm::eDoLeaveAction::Pause;
		};
	}
}