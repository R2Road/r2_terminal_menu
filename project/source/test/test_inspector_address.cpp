#include "test_inspector_address.hpp"

#include "r2tm/r2tm_inspector.hpp"
#include "r2tm/r2tm_ostream.hpp"

namespace test_inspector_address
{
	r2tm::TitleFunctionT Address::GetTitleFunction() const
	{
		return []()->const char*
		{
			return "Inspector : Address";
		};
	}
	r2tm::DoFunctionT Address::GetDoFunction() const
	{
		return []()->r2tm::eDoLeaveAction
		{
			LS();

			OUT_SOURCE_READY_N_BEGIN;
			struct
			{
				const short i = 100;
				const short j = 200;
			} s;
			OUT_SOURCE_END;

			LS();

			{
				OUT_SUBJECT( "기존의 출력 방식" );

				LF();

				OUT_VALUE( &s );
				OUT_VALUE( &s.i );
				OUT_VALUE( &s.j );
			}

			LS();

			{
				OUT_SUBJECT( "OUT_ADDRESS 사용" );

				LF();

				OUT_ADDRESS( s );
				OUT_ADDRESS( s.i );
				OUT_ADDRESS( s.j );
			}

			LS();

			{
				OUT_SUBJECT( "OUT_ADDRESS_AND_OFFSET 사용" );

				LF();

				OUT_ADDRESS_AND_OFFSET( s, s.i );
				OUT_ADDRESS_AND_OFFSET( s, s.j );
			}

			LS();

			return r2tm::eDoLeaveAction::Pause;
		};
	}
}