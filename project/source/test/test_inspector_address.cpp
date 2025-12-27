#include "test_inspector_address.hpp"
#include "test_inspector_address___helper_function.hpp"
#include "test_inspector_address___helper_member_function.hpp"

#include "r2tm/r2tm_inspector.hpp"
#include "r2tm/r2tm_ostream.hpp"

namespace test_inspector_address
{
	r2tm::TitleFunctionT Value::GetTitleFunction() const
	{
		return []()->const char*
		{
			return "Inspector : Address : Value";
		};
	}
	r2tm::DoFunctionT Value::GetDoFunction() const
	{
		return []()->r2tm::eDoLeaveAction
		{
			LS();

			OUT_SOURCE_READY_N_BEGIN;
			int i = 0;
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

				OUT_VALUE( &i );
				OUT_VALUE( &s );
				OUT_VALUE( &s.i );
				OUT_VALUE( &s.j );
			}

			LS();

			{
				OUT_SUBJECT( "OUT_ADDRESS 사용" );

				LF();

				OUT_ADDRESS( i );
				OUT_ADDRESS( s );
				OUT_ADDRESS( s.i );
				OUT_ADDRESS( s.j );
			}

			LS();

			{
				OUT_SUBJECT( "OUT_ADDRESS_AND_OFFSET 사용" );

				LF();

				OUT_ADDRESS_AND_OFFSET( i, s );
				OUT_ADDRESS_AND_OFFSET( s, s.i );
				OUT_ADDRESS_AND_OFFSET( s, s.j );
			}

			LS();

			return r2tm::eDoLeaveAction::Pause;
		};
	}



	r2tm::TitleFunctionT Function::GetTitleFunction() const
	{
		return []()->const char*
		{
			return "Inspector : Address : Function";
		};
	}
	r2tm::DoFunctionT Function::GetDoFunction() const
	{
		return []()->r2tm::eDoLeaveAction
		{
			LS();

			{
				OUT_SUBJECT( "기존의 출력 방식" );

				LF();

				OUT_VALUE( &TestFunction_1 );
				OUT_VALUE( &TestFunction_2 );
			}

			LS();

			{
				OUT_SUBJECT( "OUT_ADDRESS 사용" );

				LF();

				OUT_ADDRESS( TestFunction_1 );
				OUT_ADDRESS( TestFunction_2 );
			}

			LS();

			{
				OUT_SUBJECT( "OUT_ADDRESS_AND_OFFSET 사용" );

				LF();

				OUT_ADDRESS_AND_OFFSET( TestFunction_1, TestFunction_2 );
			}

			LS();

			return r2tm::eDoLeaveAction::Pause;
		};
	}



	r2tm::TitleFunctionT Member_Function::GetTitleFunction() const
	{
		return []()->const char*
		{
			return "Inspector : Address : Member Function";
		};
	}
	r2tm::DoFunctionT Member_Function::GetDoFunction() const
	{
		return []()->r2tm::eDoLeaveAction
		{
			LS();

			OUT_FILE_CUR_DIR( "test_inspector_address___helper_member_function.hpp" );

			LS();

			{
				OUT_SUBJECT( "기존의 출력 방식 : 실패" );

				LF();

				OUT_VALUE( &S::TestFunction_1 );
				OUT_VALUE( &S::TestFunction_2 );
			}

			LS();

			{
				OUT_SUBJECT( "멤버 함수 주소를 출력하는 방법" );

				LF();

				auto p_1 = &S::TestFunction_1;
				std::printf( "S::TestFunction_1 : %p\n", ( void*& )p_1 );
				auto p_2 = &S::TestFunction_2;
				std::printf( "S::TestFunction_2 : %p\n", ( void*& )p_2 );
			}

			LS();

			{
				OUT_SUBJECT( "OUT_ADDRESS 사용" );

				LF();

				OUT_ADDRESS( &S::TestFunction_1 );
				OUT_ADDRESS( &S::TestFunction_2 );
			}

			LS();

			{
				OUT_SUBJECT( "OUT_ADDRESS_AND_OFFSET 사용" );

				LF();

				OUT_ADDRESS_AND_OFFSET( &S::TestFunction_1, &S::TestFunction_2 );
			}

			LS();

			return r2tm::eDoLeaveAction::Pause;
		};
	}



	r2tm::TitleFunctionT Convert2VoidPointer::GetTitleFunction() const
	{
		return []()->const char*
		{
			return "Inspector : Address : Convert 2 Void Pointer";
		};
	}
	r2tm::DoFunctionT Convert2VoidPointer::GetDoFunction() const
	{
		return []()->r2tm::eDoLeaveAction
		{
			LS();

			{
				OUT_SUBJECT( "변수 주소" );

				int i = 0;
				struct SS
				{
					const short i = 100;
					const short j = 200;
				} ss;

				LF();

				{
					OUT_VALUE(  &i );
					OUT_VALUE(  &ss );
					OUT_VALUE(  &ss.j );

					LF();

					OUT_ADDRESS( i );
					OUT_ADDRESS( ss );
					OUT_ADDRESS( ss.j );

					LF();

					OUT_VALUE( r2tm::Convert2VoidPointer( &i ) );
					OUT_VALUE( r2tm::Convert2VoidPointer( &ss ) );
					OUT_VALUE( r2tm::Convert2VoidPointer( &ss.j ) );
				}
			}

			LS();

			{
				OUT_SUBJECT( "함수 주소" );

				LF();

				{
					std::printf( "TestFunction_1 : %p\n", &TestFunction_1 );
					std::printf( "TestFunction_2 : %p\n", &TestFunction_2 );

					LF();

					OUT_ADDRESS( TestFunction_1 );
					OUT_ADDRESS( TestFunction_2 );

					LF();

					OUT_VALUE( r2tm::Convert2VoidPointer( &TestFunction_1 ) );
					OUT_VALUE( r2tm::Convert2VoidPointer( &TestFunction_2 ) );
				}
			}

			LS();

			{
				OUT_SUBJECT( "멤버 함수 주소" );

				LF();

				{
					auto p_1 = &S::TestFunction_1;
					std::printf( "S::TestFunction_1 : %p\n", ( void*& )p_1 );
					auto p_2 = &S::TestFunction_2;
					std::printf( "S::TestFunction_2 : %p\n", ( void*& )p_2 );

					LF();
					
					OUT_ADDRESS( &S::TestFunction_1 );
					OUT_ADDRESS( &S::TestFunction_2 );

					LF();

					OUT_VALUE( r2tm::Convert2VoidPointer( &S::TestFunction_1 ) );
					OUT_VALUE( r2tm::Convert2VoidPointer( &S::TestFunction_2 ) );
				}
			}

			LS();

			return r2tm::eDoLeaveAction::Pause;
		};
	}
}