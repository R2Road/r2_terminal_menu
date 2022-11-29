#include "inspector_binary_test.h"

#include "r2cm/r2cm_Inspector.h"
#include "r2cm/r2cm_ostream.h"

namespace inspector_binary_test
{
	r2cm::iItem::TitleFunctionT Binary::GetTitleFunction() const
	{
		return []()->const char*
		{
			return "Inspector : Binary";
		};
	}
	r2cm::iItem::DoFunctionT Binary::GetDoFunction() const
	{
		return []()->r2cm::eItemLeaveAction
		{
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
				DECLARATION_MAIN( struct Dummy { int32_t i1 = 1; int64_t i2 = 7; int32_t i3 = 2; int64_t i4 = 9; } d );
				OUTPUT_VALUE( sizeof( d ) );
				OUTPUT_BINARY( d );
			}

			std::cout << r2cm::split;

			return r2cm::eItemLeaveAction::Pause;
		};
	}



	r2cm::iItem::TitleFunctionT Binaries::GetTitleFunction() const
	{
		return []()->const char*
		{
			return "Inspector : Binaries";
		};
	}
	r2cm::iItem::DoFunctionT Binaries::GetDoFunction() const
	{
		return []()->r2cm::eItemLeaveAction
		{
			std::cout << r2cm::split;

			{
				DECLARATION_MAIN( short buffer[2] = { 0 } );
				PROCESS_MAIN( buffer[0] = 1; buffer[1] = 2; );
				OUTPUT_BINARIES( buffer, 2 );
			}

			std::cout << r2cm::split;

			{
				DECLARATION_MAIN( short buffer[5] = { 0 } );
				OUTPUT_BINARIES( buffer, 5 );
			}

			std::cout << r2cm::split;

			{
				DECLARATION_MAIN( int buffer[4] = { 0 } );
				PROCESS_MAIN( buffer[0] = 1; buffer[1] = 2; buffer[2] = 4; buffer[3] = 8; );
				OUTPUT_BINARIES( buffer, 4 );
			}

			std::cout << r2cm::split;

			{
				DECLARATION_MAIN( char buffer[10] = { 0 } );
				OUTPUT_BINARIES( buffer, 10 );
			}

			std::cout << r2cm::split;

			{
				DECLARATION_MAIN( struct Dummy { int32_t i32 = 0; int64_t i64 = 0; } buffer[2] );
				PROCESS_MAIN( buffer[0].i32 = 3; buffer[0].i64 = -1; );
				PROCESS_MAIN( buffer[1].i32 = 1; buffer[1].i64 = -3; );
				OUTPUT_BINARIES( buffer, 2 );
			}

			std::cout << r2cm::split;

			{
				DECLARATION_MAIN( struct Dummy { int32_t i1 = 1; int32_t i2 = 2; int32_t i3 = 3; } buffer[2] );
				OUTPUT_BINARIES( buffer, 2 );
			}

			std::cout << r2cm::split;

			return r2cm::eItemLeaveAction::Pause;
		};
	}
}