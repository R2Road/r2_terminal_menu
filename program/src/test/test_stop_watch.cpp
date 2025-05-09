#include "test_stop_watch.h"

#include "r2tm/r2tm_Inspector.h"
#include "r2tm/r2tm_ostream.h"
#include "r2tm/r2tm_WindowsUtility.h"

#include "r2tm/r2tm_StopWatch.h"

namespace test_stop_watch
{
	r2tm::TitleFunctionT Declaration::GetTitleFunction() const
	{
		return []()->const char*
		{
			return "Declaration";
		};
	}
	r2tm::DoFunctionT Declaration::GetDoFunction() const
	{
		return []()->r2tm::eDoLeaveAction
		{
			LS();

			{
				DECLARATION_MAIN( r2tm::StopWatch s );

				LF();

				OUTPUT_SIZE( s );

				LF();

				OUTPUT_BINARY( s );

				LF();

				EXPECT_EQ( 0ll, s.GetMilliTime() );
				EXPECT_EQ( 0ll, s.GetMicroTime() );
				EXPECT_EQ( 0ll, s.GetNanoTime() );
				EXPECT_EQ( 0ll, s.GetMaxTime() );
				EXPECT_EQ( LLONG_MAX, s.GetMinTime() );

				LF();

				EXPECT_EQ( 0ll, s.GetAccumulateTime() );
				EXPECT_EQ( 0ll, s.GetAccumulateCount() );
				EXPECT_EQ( 0ll, s.GetAverageTime() );
			}

			LS();

			return r2tm::eDoLeaveAction::Pause;
		};
	}


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
				PROCESS_SUB( r2tm::WindowsUtility::RequestSleep( 1000 ) );
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


	r2tm::TitleFunctionT Accumulate::GetTitleFunction() const
	{
		return []()->const char*
		{
			return "Stop Watch : Accumulate";
		};
	}
	r2tm::DoFunctionT Accumulate::GetDoFunction() const
	{
		return []()->r2tm::eDoLeaveAction
		{
			LS();

			DECLARATION_MAIN( r2tm::StopWatch s );

			LS();

			OUTPUT_VALUE( s.GetAverageTime() );

			LS();

			{
				PROCESS_MAIN( s.Start() );
				PROCESS_SUB( r2tm::WindowsUtility::RequestSleep( 100 ) );
				PROCESS_MAIN( s.Stop() );
				OUTPUT_VALUE( s.GetAverageTime() );

				SS();

				PROCESS_MAIN( s.Start() );
				PROCESS_SUB( r2tm::WindowsUtility::RequestSleep( 500 ) );
				PROCESS_MAIN( s.Stop() );
				OUTPUT_VALUE( s.GetAverageTime() );

				SS();

				PROCESS_MAIN( s.Start() );
				PROCESS_SUB( r2tm::WindowsUtility::RequestSleep( 700 ) );
				PROCESS_MAIN( s.Stop() );
				OUTPUT_VALUE( s.GetAverageTime() );

				SS();

				OUTPUT_VALUE( s.GetAverageTime() );

				LF();

				PROCESS_MAIN( s.PrintAverageTime_MilliSeconds() );
				LF2();
				PROCESS_MAIN( s.PrintAverageTime_MicroSeconds() );
				LF2();
				PROCESS_MAIN( s.PrintAverageTime_NanoSeconds() );
				LF();
			}

			LS();

			return r2tm::eDoLeaveAction::Pause;
		};
	}


	r2tm::TitleFunctionT Reset::GetTitleFunction() const
	{
		return []()->const char*
		{
			return "Reset";
		};
	}
	r2tm::DoFunctionT Reset::GetDoFunction() const
	{
		return []()->r2tm::eDoLeaveAction
		{
			LS();

			DECLARATION_MAIN( r2tm::StopWatch s );

			LS();

			{
				PROCESS_MAIN( s.Start() );
				PROCESS_SUB( r2tm::WindowsUtility::RequestSleep( 100 ) );
				PROCESS_MAIN( s.Stop() );
			}

			SS();

			{
				PROCESS_MAIN( s.PrintElapsedTime_All() );
				LF();

				LF();

				PROCESS_MAIN( s.PrintAverageTime_All() );
				LF();
			}

			SS();

			PROCESS_MAIN( s.Reset() );

			SS();

			{
				PROCESS_MAIN( s.PrintElapsedTime_All() );
				LF();

				LF();

				PROCESS_MAIN( s.PrintAverageTime_All() );
				LF();
			}

			LS();

			return r2tm::eDoLeaveAction::Pause;
		};
	}
}