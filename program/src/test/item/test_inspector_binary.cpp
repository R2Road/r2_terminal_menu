#include "test_inspector_binary.h"

#include "r2tm/r2tm_Inspector.h"
#include "r2tm/r2tm_ostream.h"

namespace test_inspector_binary
{
	r2tm::TitleFunctionT Binary::GetTitleFunction() const
	{
		return []()->const char*
		{
			return "Inspector : Binary";
		};
	}
	r2tm::DoFunctionT Binary::GetDoFunction() const
	{
		return []()->r2tm::eDoLeaveAction
		{
			LS();

			{
				OUTPUT_BINARY( 123i8 );
				OUTPUT_BINARY( int8_t( -123i8 ) );

				OUTPUT_BINARY( 123ui8 );
			}

			LS();

			{
				OUTPUT_BINARY( 123i16 );
				OUTPUT_BINARY( int16_t( -123i16 ) );

				OUTPUT_BINARY( 123ui16 );
			}

			LS();

			{
				OUTPUT_BINARY( 123i32 );
				OUTPUT_BINARY( -123i32 );

				OUTPUT_BINARY( 123ui32 );
			}

			LS();

			{
				OUTPUT_BINARY( 123i64 );
				OUTPUT_BINARY( -123i64 );

				OUTPUT_BINARY( 123ui64 );
			}

			LS();

			{
				DECLARATION_MAIN( struct S { int32_t i1 = 1; int64_t i2 = 7; int32_t i3 = 2; int64_t i4 = 9; } d );
				OUTPUT_VALUE( sizeof( d ) );
				OUTPUT_BINARY( d );
			}

			LS();

			return r2tm::eDoLeaveAction::Pause;
		};
	}



	r2tm::TitleFunctionT Binaries_1::GetTitleFunction() const
	{
		return []()->const char*
		{
			return "Inspector : Binaries_1";
		};
	}
	r2tm::DoFunctionT Binaries_1::GetDoFunction() const
	{
		return []()->r2tm::eDoLeaveAction
		{
			LS();

			{
				DECLARATION_MAIN( short buffer[2] = { 0 } );

				LF();

				PROCESS_MAIN( buffer[0] = 1; buffer[1] = 2; );

				LF();

				OUTPUT_BINARIES( buffer, 2 );
			}

			LS();

			{
				DECLARATION_MAIN( short buffer[5] = { 0 } );

				LF();

				OUTPUT_BINARIES( buffer, 5 );
			}

			LS();

			{
				DECLARATION_MAIN( int buffer[4] = { 0 } );

				LF();

				PROCESS_MAIN( buffer[0] = 1; buffer[1] = 2; buffer[2] = 4; buffer[3] = 8; );

				LF();

				OUTPUT_BINARIES( buffer, 4 );
			}

			LS();

			{
				DECLARATION_MAIN( char buffer[10] = { 0 } );

				LF();

				OUTPUT_BINARIES( buffer, 10 );
			}

			LS();

			return r2tm::eDoLeaveAction::Pause;
		};
	}



	r2tm::TitleFunctionT Binaries_2::GetTitleFunction() const
	{
		return []()->const char*
		{
			return "Inspector : Binaries 2";
		};
	}
	r2tm::DoFunctionT Binaries_2::GetDoFunction() const
	{
		return []()->r2tm::eDoLeaveAction
		{
			LS();

			{
				DECLARATION_MAIN( struct S { int32_t i32 = 0; int64_t i64 = 0; } buffer[2] );

				LF();

				PROCESS_MAIN( buffer[0].i32 = 3; buffer[0].i64 = -1; );
				PROCESS_MAIN( buffer[1].i32 = 1; buffer[1].i64 = -3; );

				LF();

				OUTPUT_BINARIES( buffer, 2 );
			}

			LS();

			{
				DECLARATION_MAIN( struct S { int32_t i1 = 1; int32_t i2 = 2; int32_t i3 = 3; } buffer[2] );

				LF();

				OUTPUT_BINARIES( buffer, 2 );
			}

			LS();

			return r2tm::eDoLeaveAction::Pause;
		};
	}
}