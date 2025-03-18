#include "r2tm_StopWatch.h"

#include <numeric>

#include "r2tm/r2tm_ostream.h"

namespace r2tm
{
	StopWatch::StopWatch() :
		mStartTime( std::chrono::nanoseconds::duration( 0 ) )
		, mEndTime( std::chrono::nanoseconds::duration( 0 ) )

		, mMaxTime( 0ll )
		, mMinTime( std::numeric_limits<long long>::max() )

		, mAccumulateTime( 0ll )
		, mAccumulateCount( 0ll )
	{}

	void StopWatch::Reset()
	{
		mEndTime = mStartTime = std::chrono::steady_clock::time_point( std::chrono::nanoseconds::duration( 0 ) );

		mMaxTime = 0ll;
		mMinTime = std::numeric_limits<long long>::max();

		mAccumulateTime = 0ll;
		mAccumulateCount = 0ll;
	}
	void StopWatch::Start()
	{
		mEndTime = mStartTime = std::chrono::high_resolution_clock::now();
	}
	void StopWatch::Stop()
	{
		mEndTime = std::chrono::high_resolution_clock::now();

		const auto current_time = std::chrono::duration_cast<std::chrono::nanoseconds>( mEndTime - mStartTime ).count();
		if( current_time > mMaxTime )
		{
			mMaxTime = current_time;
		}
		if( current_time < mMinTime )
		{
			mMinTime = current_time;
		}

		mAccumulateTime += current_time;
		++mAccumulateCount;
	}

	long long StopWatch::GetMilliTime() const
	{
		return std::chrono::duration_cast<std::chrono::milliseconds>( mEndTime - mStartTime ).count();
	}
	long long StopWatch::GetMicroTime() const
	{
		return std::chrono::duration_cast<std::chrono::microseconds>( mEndTime - mStartTime ).count();
	}
	long long StopWatch::GetNanoTime() const
	{
		return std::chrono::duration_cast<std::chrono::nanoseconds>( mEndTime - mStartTime ).count();
	}

	void StopWatch::PrintElapsedTime_MilliSeconds()
	{
		std::cout << GetMilliTime() << "ms";
	}
	void StopWatch::PrintElapsedTime_MicroSeconds()
	{
		std::cout << GetMicroTime() << "��s";
	}
	void StopWatch::PrintElapsedTime_NanoSeconds()
	{
		std::cout << GetNanoTime() << "ns";
	}
	void StopWatch::PrintElapsedTime_All()
	{
		PrintElapsedTime_MilliSeconds();
		std::cout << "     ";
		PrintElapsedTime_MicroSeconds();
		std::cout << "     ";
		PrintElapsedTime_NanoSeconds();
	}

	void StopWatch::PrintMinAndMaxTime_MilliSeconds()
	{
		std::cout << "Min : " << std::chrono::duration_cast<std::chrono::milliseconds>( std::chrono::nanoseconds::duration( mMinTime ) ).count() << "ms";
		std::cout << "     ";
		std::cout << "Max : " << std::chrono::duration_cast<std::chrono::milliseconds>( std::chrono::nanoseconds::duration( mMaxTime ) ).count() << "ms";
	}
	void StopWatch::PrintMinAndMaxTime_MicroSeconds()
	{
		std::cout << "Min : " << std::chrono::duration_cast<std::chrono::microseconds>( std::chrono::nanoseconds::duration( mMinTime ) ).count() << "��s";
		std::cout << "     ";
		std::cout << "Max : " << std::chrono::duration_cast<std::chrono::microseconds>( std::chrono::nanoseconds::duration( mMaxTime ) ).count() << "��s";
	}
	void StopWatch::PrintMinAndMaxTime_NanoSeconds()
	{
		std::cout << "Min : " << mMinTime << "ns";
		std::cout << "     ";
		std::cout << "Max : " << mMaxTime << "ns";
	}

	void StopWatch::PrintAverageTime_MilliSeconds()
	{
		std::cout << "Avg : " << std::chrono::duration_cast<std::chrono::milliseconds>( std::chrono::nanoseconds::duration( GetAverageTime() ) ).count() << "ms";
	}
	void StopWatch::PrintAverageTime_MicroSeconds()
	{
		std::cout << "Avg : " << std::chrono::duration_cast<std::chrono::microseconds>( std::chrono::nanoseconds::duration( GetAverageTime() ) ).count() << "��s";
	}
	void StopWatch::PrintAverageTime_NanoSeconds()
	{
		std::cout << "Avg : " << GetAverageTime() << "ns";
	}
	void StopWatch::PrintAverageTime_All()
	{
		PrintAverageTime_MilliSeconds();
		std::cout << "     ";
		PrintAverageTime_MicroSeconds();
		std::cout << "     ";
		PrintAverageTime_NanoSeconds();
	}
}