#include "test_inspector_demo.hpp"

#include "r2tm/r2tm_inspector.hpp"
#include "r2tm/r2tm_ostream.hpp"

namespace test_inspector_demo
{
	r2tm::TitleFunctionT Demo_1::GetTitleFunction() const
	{
		return []()->const char*
		{
			return "Inspector : Demo 1";
		};
	}
	r2tm::DoFunctionT Demo_1::GetDoFunction() const
	{
		return []()->r2tm::eDoLeaveAction
		{
			LS();

			{
				OUTPUT_SUBJECT( "정의" );

				LF();

				DECL_MAIN( int i = 0 );
				DECL_MAIN( int j = i );

				SS();

				OUTPUT_SUBJECT( "작동 + 검사" );

				LF();

				EXPECT_EQ( i, j );

				LF();

				PROC_MAIN( j = 1 );
				EXPECT_NE( i, j );
			
			}

			LS();

			{
				OUTPUT_SUBJECT( "코드 출력" );

				LF();

				struct
				{
					int i = 255;

					void Do()
					{
						i <<= 2;
					}
				} s;

				OUTPUT_FILE_RANGE( "src/test/test_inspector_demo.cpp", 51, 59 );

				SS();

				PROC_MAIN( s.Do() );

				LF();

				OUTPUT_SUBJECT( "값 출력" );

				LF();

				OUTPUT_VALUE( s.i );

				SS();

				OUTPUT_SUBJECT( "바이너리 출력" );

				LF();

				OUTPUT_BINARY( s );
			}

			LS();

			return r2tm::eDoLeaveAction::Pause;
		};
	}



	r2tm::TitleFunctionT Demo_2::GetTitleFunction() const
	{
		return []()->const char*
		{
			return "Inspector : Demo 2";
		};
	}
	r2tm::DoFunctionT Demo_2::GetDoFunction() const
	{
		return []()->r2tm::eDoLeaveAction
		{
			LS();

			{
				OUTPUT_SUBJECT( "안되는 것" );

				LF();

#pragma warning( push )
#pragma warning( disable : 4002 )
				OUTPUT_CODE( std::pair<int, int> a );
#pragma warning( pop )

				LF();

				OUTPUT_NOTE( "인자가 2개인 템플릿의 선언에는 Inspector 의 사용이 안된다. C4002" );
			}

			SS();

			{
				OUTPUT_SUBJECT( "대안 : OUTPUT_SOURCE" );

				LF();

				OUTPUT_SOURCE_READY_N_BEGIN;
				std::pair<int, int> a;
				OUTPUT_SOURCE_END;

				// warning 제거용 더미 코드
				a.first = 0;
			}

			SS();

			{
				OUTPUT_SUBJECT( "대안 : OUTPUT_SOURCE + using" );

				LF();

				OUTPUT_SOURCE_READY_N_BEGIN;
				using P = std::pair<int, int>;
				OUTPUT_SOURCE_END;

				LF();

				DECL_MAIN( P a );

				// warning 제거용 더미 코드
				a.first = 0;
			}

			LS();

			return r2tm::eDoLeaveAction::Pause;
		};
	}
}