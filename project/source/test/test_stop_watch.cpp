#include "test_stop_watch.hpp"

#include "r2tm/r2tm_inspector.hpp"
#include "r2tm/r2tm_ostream.hpp"
#include "r2tm/r2tm_windows_utility.hpp"

#include "r2tm/r2tm_stop_watch.hpp"

namespace test_stop_watch
{
	r2tm::eStatus Declaration::GetStatus() const
	{
		return r2tm::eStatus::Complete;
	}
	r2tm::TitleFunctionT Declaration::GetTitleFunction() const
	{
		return []()->const char*
		{
			return "Stop Watch : Declaration";
		};
	}
	r2tm::DoFunctionT Declaration::GetDoFunction() const
	{
		return []()->r2tm::eDoLeaveAction
		{
			LS();

			OUT_SUBJECT( "기본 생성자" );

			LS();

			{
				DECL_MAIN( r2tm::StopWatch s );

				LF();

				OUT_SIZE( s );

				LF();

				OUT_BINARY( s );

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


	r2tm::eStatus Basic::GetStatus() const
	{
		return r2tm::eStatus::Complete;
	}
	r2tm::TitleFunctionT Basic::GetTitleFunction() const
	{
		return []()->const char*
		{
			return "Stop Watch : Basic";
		};
	}
	r2tm::DoFunctionT Basic::GetDoFunction() const
	{
		return []()->r2tm::eDoLeaveAction
		{
			LS();

			DECL_MAIN( r2tm::StopWatch s );

			LS();

			{
				{
					OUT_SUBJECT( "Start + Stop" );

					LF();

					PROC_MAIN( s.Start() );
					PROC_SUB( r2tm::WindowsUtility::RequestSleep( 1000 ) );
					PROC_MAIN( s.Stop() );
				}

				SS();

				{
					OUT_SUBJECT( "경과 시간 단위 별로 출력" );

					LF();

					PROC_MAIN( s.PrintElapsedTime_MilliSeconds() );
					LF2();
					PROC_MAIN( s.PrintElapsedTime_MicroSeconds() );
					LF2();
					PROC_MAIN( s.PrintElapsedTime_NanoSeconds() );
					LF();
				}

				SS();

				{
					OUT_SUBJECT( "경과 시간 전부 출력" );

					LF();

					PROC_MAIN( s.PrintElapsedTime_All() );
					LF();
				}
			}

			LS();

			return r2tm::eDoLeaveAction::Pause;
		};
	}


	r2tm::eStatus Min_Max::GetStatus() const
	{
		return r2tm::eStatus::Complete;
	}
	r2tm::TitleFunctionT Min_Max::GetTitleFunction() const
	{
		return []()->const char*
		{
			return "Stop Watch : Min / Max";
		};
	}
	r2tm::DoFunctionT Min_Max::GetDoFunction() const
	{
		return []()->r2tm::eDoLeaveAction
		{
			LS();

			DECL_MAIN( r2tm::StopWatch s );

			LS();

			{
				{
					OUT_SUBJECT( "Start + Stop" );

					LF();

					PROC_MAIN( s.Start() );
					PROC_SUB( r2tm::WindowsUtility::RequestSleep( 1000 ) );
					PROC_MAIN( s.Stop() );

					SS();

					PROC_MAIN( s.Start() );
					PROC_SUB( r2tm::WindowsUtility::RequestSleep( 200 ) );
					PROC_MAIN( s.Stop() );
				}

				SS();

				{
					OUT_SUBJECT( "최소 / 최대 경과 시간" );

					LF();

					PROC_MAIN( s.PrintMinAndMaxTime_MilliSeconds() );
					LF2();
					PROC_MAIN( s.PrintMinAndMaxTime_MicroSeconds() );
					LF2();
					PROC_MAIN( s.PrintMinAndMaxTime_NanoSeconds() );
					LF();
				}
			}

			LS();

			return r2tm::eDoLeaveAction::Pause;
		};
	}


	r2tm::eStatus Accumulate::GetStatus() const
	{
		return r2tm::eStatus::Complete;
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

			OUT_SUBJECT( "누적 과 평균" );

			LS();

			DECL_MAIN( r2tm::StopWatch s );

			LF();

			OUT_VALUE( s.GetAverageTime() );

			LS();

			{
				PROC_MAIN( s.Start() );
				PROC_SUB( r2tm::WindowsUtility::RequestSleep( 100 ) );
				PROC_MAIN( s.Stop() );
				OUT_VALUE( s.GetAverageTime() );

				SS();

				PROC_MAIN( s.Start() );
				PROC_SUB( r2tm::WindowsUtility::RequestSleep( 500 ) );
				PROC_MAIN( s.Stop() );
				OUT_VALUE( s.GetAverageTime() );

				SS();

				PROC_MAIN( s.Start() );
				PROC_SUB( r2tm::WindowsUtility::RequestSleep( 700 ) );
				PROC_MAIN( s.Stop() );
				OUT_VALUE( s.GetAverageTime() );

				SS();

				PROC_MAIN( s.PrintAverageTime_MilliSeconds() );
				LF2();
				PROC_MAIN( s.PrintAverageTime_MicroSeconds() );
				LF2();
				PROC_MAIN( s.PrintAverageTime_NanoSeconds() );
				LF();
			}

			LS();

			return r2tm::eDoLeaveAction::Pause;
		};
	}


	r2tm::eStatus Reset::GetStatus() const
	{
		return r2tm::eStatus::Complete;
	}
	r2tm::TitleFunctionT Reset::GetTitleFunction() const
	{
		return []()->const char*
		{
			return "Stop Watch : Reset";
		};
	}
	r2tm::DoFunctionT Reset::GetDoFunction() const
	{
		return []()->r2tm::eDoLeaveAction
		{
			LS();

			OUT_SUBJECT( "초기화" );

			LS();

			DECL_MAIN( r2tm::StopWatch s );

			LS();

			{
				PROC_MAIN( s.Start() );
				PROC_SUB( r2tm::WindowsUtility::RequestSleep( 100 ) );
				PROC_MAIN( s.Stop() );
			}

			SS();

			{
				PROC_MAIN( s.PrintElapsedTime_All() );
				LF();

				LF();

				PROC_MAIN( s.PrintAverageTime_All() );
				LF();
			}

			SS();

			PROC_MAIN( s.Reset() );

			SS();

			{
				PROC_MAIN( s.PrintElapsedTime_All() );
				LF();

				LF();

				PROC_MAIN( s.PrintAverageTime_All() );
				LF();
			}

			LS();

			return r2tm::eDoLeaveAction::Pause;
		};
	}
}