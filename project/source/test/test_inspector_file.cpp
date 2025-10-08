#include "test_inspector_file.hpp"

#include <filesystem>

#include "r2tm/r2tm_inspector.hpp"
#include "r2tm/r2tm_ostream.hpp"

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

			OUT_SUBJECT( "OUT_FILE" );

			LS();

			{
				DECL_MAIN( std::filesystem::path p = std::filesystem::current_path() );
				PROC_MAIN( p.append( "resources" ).append( "inspector_file_test_helper_file_01.lua" ) );
				
				LF();

				EXPECT_TRUE( std::filesystem::exists( p ) );

				LF();

				PROC_MAIN( OUT_FILE( p.string().c_str() ) );
			}

			LS();

			{
				DECL_MAIN( std::filesystem::path p = std::filesystem::current_path() );
				PROC_MAIN( p.append( "resources" ).append( "inspector_file_test_helper_file_01.cpp" ) );
				
				LF();

				EXPECT_TRUE( std::filesystem::exists( p ) );

				LF();

				PROC_MAIN( OUT_FILE( p.string().c_str() ) );
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

			OUT_SUBJECT( "OUT_FILE : with __FILE__" );

			LS();

			{
				PROC_MAIN( OUT_FILE( __FILE__ ) );
			}

			LS();

			return r2tm::eDoLeaveAction::Pause;
		};
	}



	r2tm::TitleFunctionT File_3::GetTitleFunction() const
	{
		return []()->const char*
		{
			return "Inspector : File 3";
		};
	}
	r2tm::DoFunctionT File_3::GetDoFunction() const
	{
		return []()->r2tm::eDoLeaveAction
		{
			LS();

			OUT_SUBJECT( "OUT_FILE : 잘못된 파일 경로" );

			LS();

			{
				PROC_MAIN( OUT_FILE( "" ) );
			}

			LS();

			return r2tm::eDoLeaveAction::Pause;
		};
	}



	r2tm::TitleFunctionT Out_File_Current_Directory::GetTitleFunction() const
	{
		return []()->const char*
		{
			return "Inspector : OUT_FILE_CUR_DIR";
		};
	}
	r2tm::DoFunctionT Out_File_Current_Directory::GetDoFunction() const
	{
		return []()->r2tm::eDoLeaveAction
		{
			LS();

			{
				OUT_SUBJECT( "OUT_FILE_CUR_DIR : 정상 경로" );

				LF();

				PROC_MAIN( OUT_FILE_CUR_DIR( "menu_inspector.hpp" ) );
			}

			LS();

			{
				OUT_SUBJECT( "OUT_FILE_CUR_DIR : 비정상 경로" );

				LF();

				PROC_MAIN( OUT_FILE_CUR_DIR( "" ) );
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

			OUT_SUBJECT( "OUT_FILE_RANGE" );

			LS();

			{
				DECL_MAIN( std::filesystem::path p = std::filesystem::current_path() );
				PROC_MAIN( p.append( "resources" ).append( "inspector_file_test_helper_file_01.lua" ) );

				LF();

				EXPECT_TRUE( std::filesystem::exists( p ) );

				LF();

				OUT_FILE_RANGE( p.string().c_str(), 1, 3 );
			}

			LS();

			{
				DECL_MAIN( std::filesystem::path p = std::filesystem::current_path() );
				PROC_MAIN( p.append( "resources" ).append( "inspector_file_test_helper_file_01.cpp" ) );
				
				LF();

				EXPECT_TRUE( std::filesystem::exists( p ) );

				LF();

				OUT_FILE_RANGE( p.string().c_str(), 5, 10 );
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

			OUT_SUBJECT( "OUT_FILE_RANGE : min > max" );

			LS();

			{
				DECL_MAIN( std::filesystem::path p = std::filesystem::current_path() );
				PROC_MAIN( p.append( "resources" ).append( "inspector_file_test_helper_file_01.cpp" ) );

				LF();

				EXPECT_TRUE( std::filesystem::exists( p ) );

				SS();

				PROC_MAIN( OUT_FILE_RANGE( p.string().c_str(), 10, 5 ) );
			}

			LS();

			{
				OUT_NOTE( "min > max 여도 문제 없다." );
				OUT_NOTE( "File 내용은 아무것도 출력되지 않는다." );
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

			OUT_SUBJECT( "OUT_FILE_RANGE : with __FILE__" );

			LS();

			{
				PROC_MAIN( OUT_FILE_RANGE( __FILE__, 5, 10 ) );
			}

			LS();

			return r2tm::eDoLeaveAction::Pause;
		};
	}



	r2tm::TitleFunctionT FileRange_4::GetTitleFunction() const
	{
		return []()->const char*
		{
			return "Inspector : File Range 4";
		};
	}
	r2tm::DoFunctionT FileRange_4::GetDoFunction() const
	{
		return []()->r2tm::eDoLeaveAction
		{
			LS();

			OUT_SUBJECT( "OUT_FILE_RANGE :  잘못된 파일 경로" );

			LS();

			{
				PROC_MAIN( OUT_FILE_RANGE( "", 5, 10));
			}

			LS();

			return r2tm::eDoLeaveAction::Pause;
		};
	}



	r2tm::TitleFunctionT DirectoryOpen::GetTitleFunction() const
	{
		return []()->const char*
		{
			return "Inspector : DirectoryOpen";
		};
	}
	r2tm::DoFunctionT DirectoryOpen::GetDoFunction() const
	{
		return []()->r2tm::eDoLeaveAction
		{
			LS();

			OUT_SUBJECT( "DIR_OPEN" );

			LS();

			{
				OUT_SUBJECT( "Directory 경로" );

				LF();

				PROC_MAIN( DIR_OPEN( std::filesystem::current_path().string().c_str() ) );

				LF();

				OUT_VALUE( std::filesystem::current_path().string().c_str() );
			}

			LS();

			{
				OUT_SUBJECT( "File 경로" );

				LF();

				PROC_MAIN( DIR_OPEN( __FILE__ ) );

				LF();

				OUT_VALUE( __FILE__ );
			}

			LS();

			return r2tm::eDoLeaveAction::Pause;
		};
	}
}