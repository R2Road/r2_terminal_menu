#include "test_inspector_demo.hpp"

#include "r2tm/r2tm_inspector.hpp"
#include "r2tm/r2tm_ostream.h"

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
				DECL_MAIN( int i = 0 );
				DECL_MAIN( int j = i );

				SS();

				EXPECT_EQ( i, j );

				SS();

				PROC_MAIN( i = 1 );
				PROC_MAIN( i = 2 );
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

				OUTPUT_FILE_RANGE( "src/test/test_inspector_demo.cpp", 40, 48 );

				LF();

				DECL_MAIN( S s );

				LF();

				PROC_MAIN( s.Do() );
				EXPECT_EQ( 255 * 2 * 2, s.i );

				LF();

				OUTPUT_VALUE( s.i );

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
				OUTPUT_SUBJECT( "�ȵǴ� ��" );

				LF();

#pragma warning( push )
#pragma warning( disable : 4002 )
				OUTPUT_CODE( std::pair<int, int> a );
#pragma warning( pop )

				LF();

				OUTPUT_NOTE( "���ڰ� 2���� ���ø��� ���𿡴� Inspector �� ����� �ȵȴ�. C4002" );
			}

			SS();

			{
				OUTPUT_SUBJECT( "��� : OUTPUT_SOURCE" );

				LF();

				OUTPUT_SOURCE_READY_N_BEGIN;
				std::pair<int, int> a;
				OUTPUT_SOURCE_END;

				// warning ���ſ� ���� �ڵ�
				a.first = 0;
			}

			SS();

			{
				OUTPUT_SUBJECT( "��� : OUTPUT_SOURCE + using" );

				LF();

				OUTPUT_SOURCE_READY_N_BEGIN;
				using P = std::pair<int, int>;
				OUTPUT_SOURCE_END;

				LF();

				DECL_MAIN( P a );

				// warning ���ſ� ���� �ڵ�
				a.first = 0;
			}

			LS();

			return r2tm::eDoLeaveAction::Pause;
		};
	}
}