#include "test_inspector_demo.h"

#include "r2tm/r2tm_Inspector.h"
#include "r2tm/r2tm_ostream.h"

namespace test_inspector_demo
{
	r2tm::TitleFunctionT Demo::GetTitleFunction() const
	{
		return []()->const char*
		{
			return "Inspector : Demo";
		};
	}
	r2tm::DoFunctionT Demo::GetDoFunction() const
	{
		return []()->r2tm::eDoLeaveAction
		{
			LS();

			{
				DECLARATION_MAIN( int i = 0 );
				DECLARATION_MAIN( int j = i );

				SS();

				EXPECT_EQ( i, j );

				SS();

				PROCESS_MAIN( i = 1 );
				PROCESS_MAIN( i = 2 );
				EXPECT_NE( i, 1 );
				EXPECT_EQ( i, 2 );
			}

			LS();

			{
				struct S
				{
					int i = 255;

					void Do()
					{
						i <<= 2;
					}
				};

				OUTPUT_FILE_RANGE( "src/test/item/test_inspector_demo.cpp", 40, 48 );

				LF();

				DECLARATION_MAIN( S s );

				LF();

				PROCESS_MAIN( s.Do() );
				EXPECT_EQ( 255 * 2 * 2, s.i );

				LF();

				OUTPUT_VALUE( s.i );

				LF();

				OUTPUT_BINARY( s );
			}

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

			LS();

			return r2tm::eDoLeaveAction::Pause;
		};
	}
}