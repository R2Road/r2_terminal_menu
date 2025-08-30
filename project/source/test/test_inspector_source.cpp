#include "test_inspector_source.hpp"

#include <filesystem>

#include "r2tm/r2tm_inspector.hpp"
#include "r2tm/r2tm_ostream.hpp"

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

			OUT_SUBJECT( "OUT_SOURCE_READY, OUT_SOURCE_BEGIN, OUT_SOURCE_END" );
			OUT_SUBJECT( "OUT_SOURCE_READY_N_BEGIN" );

			LS();

			{
				DECL_MAIN( OUT_SOURCE_READY );

				LF();

				PROC_MAIN( OUT_SOURCE_BEGIN );
				class C1
				{
					int a1;
					int a2;
					int a3;
					int a4;
					int a5;
					int a6;
				};
				PROC_MAIN( OUT_SOURCE_END );
			}

			LS();

			DECL_MAIN( OUT_SOURCE_READY_N_BEGIN );
			class C2
			{
				int a1;
				int a2;
				int a3;
				int a4;
				int a5;
				int a6;
			};
			PROC_MAIN( OUT_SOURCE_END );

			LS();

			return r2tm::eDoLeaveAction::Pause;
		};
	}
}