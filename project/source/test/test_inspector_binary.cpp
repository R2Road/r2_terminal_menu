#include "test_inspector_binary.hpp"

#include "r2tm/r2tm_inspector.hpp"
#include "r2tm/r2tm_ostream.hpp"

namespace test_inspector_binary
{
	r2tm::eStatus Binary::GetStatus() const
	{
		return r2tm::eStatus::Complete;
	}
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
				OUT_BINARY( 123i8 );
				OUT_BINARY( int8_t( -123i8 ) );

				OUT_BINARY( 123ui8 );
			}

			LS();

			{
				OUT_BINARY( 123i16 );
				OUT_BINARY( int16_t( -123i16 ) );

				OUT_BINARY( 123ui16 );
			}

			LS();

			{
				OUT_BINARY( 123i32 );
				OUT_BINARY( -123i32 );

				OUT_BINARY( 123ui32 );
			}

			LS();

			{
				OUT_BINARY( 123i64 );
				OUT_BINARY( -123i64 );

				OUT_BINARY( 123ui64 );
			}

			LS();

			{
				DECL_MAIN( struct S { int32_t i1 = 1; int64_t i2 = 7; int32_t i3 = 2; int64_t i4 = 9; } d );
				OUT_VALUE( sizeof( d ) );
				OUT_BINARY( d );
			}

			LS();

			return r2tm::eDoLeaveAction::Pause;
		};
	}



	r2tm::eStatus Binaries_1::GetStatus() const
	{
		return r2tm::eStatus::Complete;
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
				DECL_MAIN( short buffer[2] = { 0 } );

				LF();

				PROC_MAIN( buffer[0] = 1; buffer[1] = 2; );

				LF();

				OUT_BINARIES( buffer, 2 );
			}

			LS();

			{
				DECL_MAIN( short buffer[5] = { 0 } );

				LF();

				OUT_BINARIES( buffer, 5 );
			}

			LS();

			{
				DECL_MAIN( int buffer[4] = { 0 } );

				LF();

				PROC_MAIN( buffer[0] = 1; buffer[1] = 2; buffer[2] = 4; buffer[3] = 8; );

				LF();

				OUT_BINARIES( buffer, 4 );
			}

			LS();

			{
				DECL_MAIN( char buffer[10] = { 0 } );

				LF();

				OUT_BINARIES( buffer, 10 );
			}

			LS();

			return r2tm::eDoLeaveAction::Pause;
		};
	}



	r2tm::eStatus Binaries_2::GetStatus() const
	{
		return r2tm::eStatus::Complete;
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
				DECL_MAIN( struct S { int32_t i32 = 0; int64_t i64 = 0; } buffer[2] );

				LF();

				PROC_MAIN( buffer[0].i32 = 3; buffer[0].i64 = -1; );
				PROC_MAIN( buffer[1].i32 = 1; buffer[1].i64 = -3; );

				LF();

				OUT_BINARIES( buffer, 2 );
			}

			LS();

			{
				DECL_MAIN( struct S { int32_t i1 = 1; int32_t i2 = 2; int32_t i3 = 3; } buffer[2] );

				LF();

				OUT_BINARIES( buffer, 2 );
			}

			LS();

			return r2tm::eDoLeaveAction::Pause;
		};
	}



	r2tm::eStatus Binaries_With_Array::GetStatus() const
	{
		return r2tm::eStatus::Complete;
	}
	r2tm::TitleFunctionT Binaries_With_Array::GetTitleFunction() const
	{
		return []()->const char*
		{
			return "Inspector : Binaries With Array";
		};
	}
	r2tm::DoFunctionT Binaries_With_Array::GetDoFunction() const
	{
		return []()->r2tm::eDoLeaveAction
		{
			LS();

			OUT_SUBJECT( "배열 타입에 template 특수화" );
			OUT_SUBJECT( "OUT_BINARY에 배열을 넣으면 정상 작동" );

			LS();

			{
				DECL_MAIN( short buffer[2] = { 0 } );

				LF();

				PROC_MAIN( buffer[0] = 1; buffer[1] = 2; );

				LF();

				OUT_BINARY( buffer );
			}

			LS();

			{
				DECL_MAIN( short buffer[5] = { 0 } );

				LF();

				OUT_BINARY( buffer );
			}

			LS();

			{
				DECL_MAIN( int buffer[4] = { 0 } );

				LF();

				PROC_MAIN( buffer[0] = 1; buffer[1] = 2; buffer[2] = 4; buffer[3] = 8; );

				LF();

				OUT_BINARY( buffer );
			}

			LS();

			{
				DECL_MAIN( char buffer[10] = { 0 } );

				LF();

				OUT_BINARY( buffer );
			}

			LS();

			return r2tm::eDoLeaveAction::Pause;
		};
	}
}