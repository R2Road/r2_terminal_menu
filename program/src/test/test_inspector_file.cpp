#include "test_inspector_file.h"

#include <filesystem>

#include "r2tm/r2tm_Inspector.h"
#include "r2tm/r2tm_ostream.h"

namespace test_inspector_file
{
	r2tm::TitleFunctionT File_1::GetTitleFunction() const
	{
		return []()->const char*
		{
			return "Inspector : File 1";
		};
	}
	r2tm::DoFunctionT File_1::GetDoFunction() const
	{
		return []()->r2tm::eDoLeaveAction
		{
			LS();

			OUTPUT_SUBJECT( "OUTPUT_FILE" );

			LS();

			{
				DECL_MAIN( std::filesystem::path p = std::filesystem::current_path() );
				PROC_MAIN( p.append( "resources" ).append( "inspector_file_test_helper_file_01.lua" ) );
				
				LF();

				EXPECT_TRUE( std::filesystem::exists( p ) );

				LF();

				PROC_MAIN( OUTPUT_FILE( p.string().c_str() ) );
			}

			LS();

			{
				DECL_MAIN( std::filesystem::path p = std::filesystem::current_path() );
				PROC_MAIN( p.append( "resources" ).append( "inspector_file_test_helper_file_01.cpp" ) );
				
				LF();

				EXPECT_TRUE( std::filesystem::exists( p ) );

				LF();

				PROC_MAIN( OUTPUT_FILE( p.string().c_str() ) );
			}

			LS();

			return r2tm::eDoLeaveAction::Pause;
		};
	}



	r2tm::TitleFunctionT File_2::GetTitleFunction() const
	{
		return []()->const char*
		{
			return "Inspector : File 2";
		};
	}
	r2tm::DoFunctionT File_2::GetDoFunction() const
	{
		return []()->r2tm::eDoLeaveAction
		{
			LS();

			OUTPUT_SUBJECT( "OUTPUT_FILE : with __FILE__" );

			LS();

			{
				PROC_MAIN( OUTPUT_FILE( __FILE__ ) );
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
				DECL_MAIN( std::filesystem::path p = std::filesystem::current_path() );
				PROC_MAIN( p.append( "resources" ).append( "inspector_file_test_helper_file_01.lua" ) );

				LF();

				EXPECT_TRUE( std::filesystem::exists( p ) );

				LF();

				OUTPUT_FILE_RANGE( p.string().c_str(), 1, 3 );
			}

			LS();

			{
				DECL_MAIN( std::filesystem::path p = std::filesystem::current_path() );
				PROC_MAIN( p.append( "resources" ).append( "inspector_file_test_helper_file_01.cpp" ) );
				
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
				DECL_MAIN( std::filesystem::path p = std::filesystem::current_path() );
				PROC_MAIN( p.append( "resources" ).append( "inspector_file_test_helper_file_01.cpp" ) );

				LF();

				EXPECT_TRUE( std::filesystem::exists( p ) );

				SS();

				PROC_MAIN( OUTPUT_FILE_RANGE( p.string().c_str(), 10, 5 ) );
			}

			LS();

			{
				OUTPUT_NOTE( "min > max 여도 문제 없다." );
				OUTPUT_NOTE( "File 내용은 아무것도 출력되지 않는다." );
			}

			LS();

			return r2tm::eDoLeaveAction::Pause;
		};
	}



	r2tm::TitleFunctionT FileRange_3::GetTitleFunction() const
	{
		return []()->const char*
		{
			return "Inspector : File Range 3";
		};
	}
	r2tm::DoFunctionT FileRange_3::GetDoFunction() const
	{
		return []()->r2tm::eDoLeaveAction
		{
			LS();

			OUTPUT_SUBJECT( "OUTPUT_FILE_RANGE : with __FILE__" );

			LS();

			{
				PROC_MAIN( OUTPUT_FILE_RANGE( __FILE__, 5, 10 ) );
			}

			LS();

			return r2tm::eDoLeaveAction::Pause;
		};
	}
}