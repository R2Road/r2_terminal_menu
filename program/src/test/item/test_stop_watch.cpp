#include "test_stop_watch.h"

#include "r2tm/r2tm_Inspector.h"
#include "r2tm/r2tm_ostream.h"
#include "r2tm/r2tm_WindowUtility.h"

#include "r2tm/r2tm_StopWatch.h"

namespace test_stop_watch
{
	r2tm::TitleFunctionT Basic::GetTitleFunction() const
	{
		return []()->const char*
		{
			return "Stop Watch";
		};
	}
	r2tm::DoFunctionT Basic::GetDoFunction() const
	{
		return []()->r2tm::eDoLeaveAction
		{
			LS();

			DECLARATION_MAIN( r2tm::StopWatch s );

			LS();

			{
				PROCESS_MAIN( s.Start() );
				PROCESS_SUB( r2tm::WindowUtility::RequestSleep( 1000 ) );
				PROCESS_MAIN( s.Stop() );

				SS();

				PROCESS_MAIN( s.PrintElapsedTime_MilliSeconds() );
				LF2();
				PROCESS_MAIN( s.PrintElapsedTime_MicroSeconds() );
				LF2();
				PROCESS_MAIN( s.PrintElapsedTime_NanoSeconds() );
				LF();

				SS();

				PROCESS_MAIN( s.PrintElapsedTime_All() );
				LF();

				SS();

				PROCESS_MAIN( s.PrintMinAndMaxTime_MilliSeconds() );
				LF2();
				PROCESS_MAIN( s.PrintMinAndMaxTime_MicroSeconds() );
				LF2();
				PROCESS_MAIN( s.PrintMinAndMaxTime_NanoSeconds() );
				LF();
			}

			LS();

			return r2tm::eDoLeaveAction::Pause;
		};
	}
}