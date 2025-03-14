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

			OUTPUT_NOTE( "OUTPUT_SOURCE 기능을 사용할 때" );
			OUTPUT_NOTE( "소스에 문자가 우하단 정보 기준으로 98개 이상 나오면 이후에 줄이 밀린다." );
			OUTPUT_NOTE( "어떤 형태든 마찬가지( 주석, 소스, 의미없는 문자열등 )" );

			LS();

			{
				OUTPUT_SUBJECT( "여기 까지 안전" );

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
				OUTPUT_NOTE( "줄이 밀리기 시작" );

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
				OUTPUT_NOTE( "한번 밀리면 계속 밀림" );

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