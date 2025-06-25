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
}