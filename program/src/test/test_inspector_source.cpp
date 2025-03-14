#include "test_inspector_source.h"

#include <filesystem>

#include "r2tm/r2tm_Inspector.h"
#include "r2tm/r2tm_ostream.h"

namespace test_inspector_source
{
	r2tm::TitleFunctionT Basic::GetTitleFunction() const
	{
		return []()->const char*
		{
			return "Inspector : Source";
		};
	}
	r2tm::DoFunctionT Basic::GetDoFunction() const
	{
		return []()->r2tm::eDoLeaveAction
		{
			LS();

			OUTPUT_SUBJECT( "OUTPUT_SOURCE_READY, OUTPUT_SOURCE_BEGIN, OUTPUT_SOURCE_END" );
			OUTPUT_SUBJECT( "OUTPUT_SOURCE_READY_N_BEGIN" );

			LS();

			{
				DECLARATION_MAIN( OUTPUT_SOURCE_READY );

				LF();

				PROCESS_MAIN( OUTPUT_SOURCE_BEGIN );
				class C1
				{
					int a1;
					int a2;
					int a3;
					int a4;
					int a5;
					int a6;
				};
				PROCESS_MAIN( OUTPUT_SOURCE_END );
			}

			LS();

			DECLARATION_MAIN( OUTPUT_SOURCE_READY_N_BEGIN );
			class C2
			{
				int a1;
				int a2;
				int a3;
				int a4;
				int a5;
				int a6;
			};
			PROCESS_MAIN( OUTPUT_SOURCE_END );

			LS();

			return r2tm::eDoLeaveAction::Pause;
		};
	}



	r2tm::TitleFunctionT Warning::GetTitleFunction() const
	{
		return []()->const char*
		{
			return "Inspector : Source : Warning";
		};
	}
	r2tm::DoFunctionT Warning::GetDoFunction() const
	{
		return []()->r2tm::eDoLeaveAction
		{
			LS();

			OUTPUT_NOTE( "OUTPUT_SOURCE ����� ����� ��" );
			OUTPUT_NOTE( "�ҽ��� ���ڰ� ���ϴ� ���� �������� 98�� �̻� ������ ���Ŀ� ���� �и���." );
			OUTPUT_NOTE( "� ���µ� ��������( �ּ�, �ҽ�, �ǹ̾��� ���ڿ��� )" );

			LS();

			{
				OUTPUT_SUBJECT( "���� ���� ����" );

				LF();

				OUTPUT_SUBJECT( "123456789012345678901234567890123456789012345678901234567890123456789012" );

				LF();

				DECLARATION_MAIN( OUTPUT_SOURCE_READY_N_BEGIN );
				class C
				{
					int i;
				};
				PROCESS_MAIN( OUTPUT_SOURCE_END );
			}

			LS();

			{
				OUTPUT_NOTE( "���� �и��� ����" );

				LF();

				OUTPUT_SUBJECT( "1234567890123456789012345678901234567890123456789012345678901234567890123" );

				LF();

				DECLARATION_MAIN( OUTPUT_SOURCE_READY_N_BEGIN );
				class C
				{
					int i;
				};
				PROCESS_MAIN( OUTPUT_SOURCE_END );
			}

			LS();

			{
				OUTPUT_NOTE( "�ѹ� �и��� ��� �и�" );

				LF();

				DECLARATION_MAIN( OUTPUT_SOURCE_READY_N_BEGIN );
				class C
				{
					int i;
				};
				PROCESS_MAIN( OUTPUT_SOURCE_END );
			}

			LS();

			return r2tm::eDoLeaveAction::Pause;
		};
	}
}