#include "inspector_test.h"

#include <filesystem>

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
	r2cm::iItem::DoFunctionT Basic::GetDoFunction()
	{
		return []()->r2cm::eItemLeaveAction
		{
			std::cout << "# " << GetInstance().GetTitleFunction()( ) << " #" << r2cm::linefeed2;
			std::cout << "[ESC] End" << r2cm::linefeed;

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
				DECLARATION_SUB( int j = i );
				EXPECT_EQ( i, j );
				PROCESS_MAIN( i = 1 );
				PROCESS_SUB( i = 2 );
				EXPECT_NE( i, 1 );
				EXPECT_EQ( i, 2 );

				std::cout << r2cm::linefeed;

				OUTPUT_VALUE( 1234 * 5678 );
				OUTPUT_CODE( printf( "%s", "asdf" ) );
			}
#pragma warning( pop )

			std::cout << r2cm::split;

			return r2cm::eItemLeaveAction::Pause;
		};
	}



	r2cm::iItem::TitleFunctionT Value::GetTitleFunction() const
	{
		return []()->const char*
		{
			return "Inspector : Value";
		};
	}
	r2cm::iItem::DoFunctionT Value::GetDoFunction()
	{
		return []()->r2cm::eItemLeaveAction
		{
			std::cout << "# " << GetInstance().GetTitleFunction()( ) << " #" << r2cm::linefeed2;

			std::cout << r2cm::split;

			{
				DECLARATION_MAIN( const int test_int_1 = 1234567; );
				OUTPUT_VALUE( test_int_1 );
			}

			std::cout << r2cm::split;

			return r2cm::eItemLeaveAction::Pause;
		};
	}



	r2cm::iItem::TitleFunctionT Binary::GetTitleFunction() const
	{
		return []()->const char*
		{
			return "Inspector : Binary";
		};
	}
	r2cm::iItem::DoFunctionT Binary::GetDoFunction()
	{
		return []()->r2cm::eItemLeaveAction
		{
			std::cout << "# " << GetInstance().GetTitleFunction()( ) << " #" << r2cm::linefeed;

			std::cout << r2cm::split;

			{
				OUTPUT_BINARY( 123i8 );
				OUTPUT_BINARY( int8_t( -123i8 ) );

				OUTPUT_BINARY( 123ui8 );
			}

			std::cout << r2cm::split;

			{
				OUTPUT_BINARY( 123i16 );
				OUTPUT_BINARY( int16_t( -123i16 ) );

				OUTPUT_BINARY( 123ui16 );
			}

			std::cout << r2cm::split;

			{
				OUTPUT_BINARY( 123i32 );
				OUTPUT_BINARY( -123i32 );

				OUTPUT_BINARY( 123ui32 );
			}

			std::cout << r2cm::split;

			{
				OUTPUT_BINARY( 123i64 );
				OUTPUT_BINARY( -123i64 );

				OUTPUT_BINARY( 123ui64 );
			}

			std::cout << r2cm::split;

			{
				DECLARATION_MAIN( const short buffer[2] = { 0 } );
				OUTPUT_BINARIES( buffer, 2 );
			}

			std::cout << r2cm::split;

			{
				DECLARATION_MAIN( const int buffer[4] = { 0 } );
				OUTPUT_BINARIES( buffer, 4 );
			}

			std::cout << r2cm::split;

			return r2cm::eItemLeaveAction::Pause;
		};
	}



	r2cm::iItem::TitleFunctionT ShowFile::GetTitleFunction() const
	{
		return []()->const char*
		{
			return "Inspector : ShowFile";
		};
	}
	r2cm::iItem::DoFunctionT ShowFile::GetDoFunction()
	{
		return []()->r2cm::eItemLeaveAction
		{
			std::cout << "# " << GetInstance().GetTitleFunction()( ) << " #" << r2cm::linefeed2;
			std::cout << "[ESC] End" << r2cm::linefeed;

			std::cout << r2cm::split;

			{
				DECLARATION_MAIN( std::filesystem::path p = std::filesystem::current_path() );
				PROCESS_MAIN( p.append( "resources" ).append( "show_code_test_01.lua" ) );
				std::cout << "> " << p << r2cm::linefeed2;

				EXPECT_TRUE( std::filesystem::exists( p ) );

				std::cout << r2cm::linefeed;

				SHOW_FILE( p.string().c_str() );
			}

			std::cout << r2cm::split;

			{
				DECLARATION_MAIN( std::filesystem::path p = std::filesystem::current_path() );
				PROCESS_MAIN( p.append( "resources" ).append( "show_code_test_01.cpp" ) );
				std::cout << "> " << p << r2cm::linefeed2;

				EXPECT_TRUE( std::filesystem::exists( p ) );

				std::cout << r2cm::linefeed;

				SHOW_FILE( p.string().c_str() );
			}

			std::cout << r2cm::split;

			return r2cm::eItemLeaveAction::Pause;
		};
	}
}