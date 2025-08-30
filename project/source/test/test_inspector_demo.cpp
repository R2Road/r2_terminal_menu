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
				OUT_SUBJECT( "����" );

				LF();

				DECL_MAIN( int i = 0 );
				DECL_MAIN( int j = i );

				SS();

				OUT_SUBJECT( "�۵� + �˻�" );

				LF();

				EXPECT_EQ( i, j );

				LF();

				PROC_MAIN( j = 1 );
				EXPECT_NE( i, j );
			
			}

			LS();

			{
				OUT_SUBJECT( "�ڵ� ���" );

				LF();

				struct
				{
					int i = 255;

					void Do()
					{
						i <<= 8;
					}
				} s;

				OUT_FILE_RANGE( "src/test/test_inspector_demo.cpp", 51, 59 );

				SS();

				PROC_MAIN( s.Do() );

				LF();

				OUT_SUBJECT( "�� ���" );

				LF();

				OUT_VALUE( s.i );

				SS();

				OUT_SUBJECT( "���̳ʸ� ���" );

				LF();

				OUT_BINARY( s );
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
				OUT_SUBJECT( "�ȵǴ� ��" );

				LF();

#pragma warning( push )
#pragma warning( disable : 4002 )
				OUT_CODE( std::pair<int, int> a );
#pragma warning( pop )

				LF();

				OUT_NOTE( "���ڰ� 2���� ���ø��� ���𿡴� Inspector �� ����� �ȵȴ�. C4002" );
			}

			SS();

			{
				OUT_SUBJECT( "��� : OUT_SOURCE" );

				LF();

				OUT_SOURCE_READY_N_BEGIN;
				std::pair<int, int> a;
				OUT_SOURCE_END;

				// warning ���ſ� ���� �ڵ�
				a.first = 0;
			}

			SS();

			{
				OUT_SUBJECT( "��� : OUT_SOURCE + using" );

				LF();

				OUT_SOURCE_READY_N_BEGIN;
				using P = std::pair<int, int>;
				OUT_SOURCE_END;

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