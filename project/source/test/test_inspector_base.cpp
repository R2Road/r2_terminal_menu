#include "test_inspector_base.hpp"

#include "r2tm/r2tm_inspector.hpp"
#include "r2tm/r2tm_ostream.hpp"

namespace test_inspector_base
{
	r2tm::TitleFunctionT Basic::GetTitleFunction() const
	{
		return []()->const char*
		{
			return "Inspector : Basic";
		};
	}
	r2tm::DoFunctionT Basic::GetDoFunction() const
	{
		return []()->r2tm::eDoLeaveAction
		{
			LS();

			{
				OUT_SUBJECT( "����" );

				LF();

				DECL_MAIN( int i = 0; );
				DECL_SUB( int j = 0; );

				SS();

				OUT_SUBJECT( "�۵�" );

				LF();

				PROC_MAIN( i = 1234567; );
				PROC_SUB( j = 7654321; );

				SS();

				OUT_SUBJECT( "���" );

				LF();

				OUT_VALUE( i );
				OUT_VALUE( j );
			}

			LS();

			return r2tm::eDoLeaveAction::Pause;
		};
	}



	r2tm::TitleFunctionT Expect_1::GetTitleFunction() const
	{
		return []()->const char*
		{
			return "Inspector : Expect 1";
		};
	}
	r2tm::DoFunctionT Expect_1::GetDoFunction() const
	{
		return []()->r2tm::eDoLeaveAction
		{
			LS();

			OUT_SUBJECT( "EXPECT Macro�� �̿��� �˻�" );

			LS();

#pragma warning( push )
#pragma warning( disable : 4127 )
			{
				EXPECT_TRUE( 1 == 1 );
				EXPECT_TRUE( 1 == 0 );

				SS();

				EXPECT_FALSE( 1 == 1 );
				EXPECT_FALSE( 1 == 0 );

				SS();

				EXPECT_EQ( 1, 1 );
				EXPECT_EQ( 1, 0 );

				SS();

				EXPECT_NE( 1, 1 );
				EXPECT_NE( 1, 0 );

			}
#pragma warning( pop )

			LS();

			return r2tm::eDoLeaveAction::Pause;
		};
	}



	r2tm::TitleFunctionT Expect_2::GetTitleFunction() const
	{
		return []()->const char*
		{
			return "Inspector : Expect 2";
		};
	}
	r2tm::DoFunctionT Expect_2::GetDoFunction() const
	{
		return []()->r2tm::eDoLeaveAction
		{
			LS();

			OUT_SUBJECT( "EXPECT Macro�� �̿��� �˻�" );

			LS();

#pragma warning( push )
#pragma warning( disable : 4127 )
			{
				EXPECT_GT( 1, 1 );
				EXPECT_GT( 1, 0 );

				SS();

				EXPECT_LT( 1, 1 );
				EXPECT_LT( 0, 1 );

				SS();

				EXPECT_GE( 1, 1 );
				EXPECT_GE( 0, 1 );

				SS();

				EXPECT_LE( 1, 1 );
				EXPECT_LE( 1, 0 );

			}
#pragma warning( pop )

			LS();

			return r2tm::eDoLeaveAction::Pause;
		};
	}



	r2tm::TitleFunctionT Expect_Epsilon_Float::GetTitleFunction() const
	{
		return []()->const char*
		{
			return "Inspector : Expect Epsilon : Float";
		};
	}
	r2tm::DoFunctionT Expect_Epsilon_Float::GetDoFunction() const
	{
		return []()->r2tm::eDoLeaveAction
		{
			LS();

			OUT_SUBJECT( "epsilon �� �̿��� float ��" );

			LS();

			{
				OUT_SUBJECT( "���е�" );

				LF();

				OUT_VALUE( r2tm_epsilon_float );
			}

			LS();

#pragma warning( push )
#pragma warning( disable : 4127 )
			{
				EXPECT_EP_EQ( 0.00001f, 0.00001f );
				EXPECT_EP_EQ( 0.00001f, 0.000011f );
				EXPECT_EP_EQ( 0.00001f, 0.00002f );

				SS();

				EXPECT_EP_NE( 0.00001f, 0.00002f );
				EXPECT_EP_NE( 0.00001f, 0.000011f );
				EXPECT_EP_NE( 0.00001f, 0.00001f );

			}
#pragma warning( pop )

			LS();

			return r2tm::eDoLeaveAction::Pause;
		};
	}



	r2tm::TitleFunctionT Expect_Epsilon_Double::GetTitleFunction() const
	{
		return []()->const char*
		{
			return "Inspector : Expect Epsilon : Double";
		};
	}
	r2tm::DoFunctionT Expect_Epsilon_Double::GetDoFunction() const
	{
		return []()->r2tm::eDoLeaveAction
		{
			LS();

			OUT_SUBJECT( "epsilon �� �̿��� double ��" );

			LS();

			{
				OUT_SUBJECT( "���е�" );

				LF();

				OUT_VALUE( r2tm_epsilon_double );
			}

			LS();

#pragma warning( push )
#pragma warning( disable : 4127 )
			{
				EXPECT_EP_EQ( 0.0000000001, 0.0000000001 );
				EXPECT_EP_EQ( 0.0000000001, 0.00000000011 );
				EXPECT_EP_EQ( 0.0000000001, 0.0000000002 );

				SS();

				EXPECT_EP_NE( 0.0000000001, 0.0000000002 );
				EXPECT_EP_NE( 0.0000000001, 0.00000000011 );
				EXPECT_EP_NE( 0.0000000001, 0.0000000001 );

			}
#pragma warning( pop )

			LS();

			return r2tm::eDoLeaveAction::Pause;
		};
	}



	r2tm::TitleFunctionT Size::GetTitleFunction() const
	{
		return []()->const char*
		{
			return "Inspector : Size";
		};
	}
	r2tm::DoFunctionT Size::GetDoFunction() const
	{
		return []()->r2tm::eDoLeaveAction
		{
			LS();

			{
				OUT_SUBJECT( "������ size ��� ���" );

				LF();

				OUT_VALUE( sizeof( int ) );
			}

			LS();

			{
				OUT_SUBJECT( "OUT_SIZE ���" );

				LF();

				OUT_SIZE( int );

				SS();

				DECL_MAIN( struct S { int i[10]; } );
				OUT_SIZE( S );
			}

			LS();

			return r2tm::eDoLeaveAction::Pause;
		};
	}



	r2tm::TitleFunctionT Align::GetTitleFunction() const
	{
		return []()->const char*
		{
			return "Inspector : Align";
		};
	}
	r2tm::DoFunctionT Align::GetDoFunction() const
	{
		return []()->r2tm::eDoLeaveAction
		{
			LS();

			{
				OUT_SUBJECT( "������ Align ��� ���" );

				LF();

				OUT_VALUE( alignof( int ) );
			}

			LS();

			{
				OUT_SUBJECT( "OUT_ALIGN ���" );

				LF();

				OUT_ALIGN( int );

				SS();

				DECL_MAIN( struct S {
					int i[10];
					long long j;
				} );
				OUT_ALIGN( S );
			}

			LS();

			return r2tm::eDoLeaveAction::Pause;
		};
	}



	r2tm::TitleFunctionT Code::GetTitleFunction() const
	{
		return []()->const char*
		{
			return "Inspector : Code";
		};
	}
	r2tm::DoFunctionT Code::GetDoFunction() const
	{
		return []()->r2tm::eDoLeaveAction
		{
			LS();

			{
				OUT_CODE( printf( "%s", "asdf" ) );
			}

			LS();

			return r2tm::eDoLeaveAction::Pause;
		};
	}



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

			DECL_MAIN( const int i = 100 );

			LS();

			{
				{
					OUT_SUBJECT( "������ ��� ���" );

					LF();

					OUT_VALUE( &i );
				}

				SS();

				{
					OUT_SUBJECT( "OUT_ADDRESS ���" );

					LF();

					OUT_ADDRESS( i );
				}
			}

			LS();

			return r2tm::eDoLeaveAction::Pause;
		};
	}



	r2tm::TitleFunctionT String_Note_Subject_Comment::GetTitleFunction() const
	{
		return []()->const char*
		{
			return "Inspector : String, Note, Subject, Comment";
		};
	}
	r2tm::DoFunctionT String_Note_Subject_Comment::GetDoFunction() const
	{
		return []()->r2tm::eDoLeaveAction
		{
			LS();

			{
				std::cout << "    " "+ OUT_STRING" << r2tm::linefeed;

				LF();

				OUT_STRING( "output string~!~!~!" );
			}

			LS();

			{
				std::cout << "    " "+ OUT_NOTE" << r2tm::linefeed;

				LF();

				OUT_NOTE( "output note~!~!~!" );
			}

			LS();

			{
				std::cout << "    " "+ OUT_SUBJECT" << r2tm::linefeed;

				LF();

				OUT_SUBJECT( "output subject~!~!~!" );
			}

			LS();

			{
				std::cout << "    " "+ OUT_COMMENT" << r2tm::linefeed;

				LF();

				OUT_COMMENT( "output comment~!~!~!" );
			}

			LS();

			return r2tm::eDoLeaveAction::Pause;
		};
	}
}