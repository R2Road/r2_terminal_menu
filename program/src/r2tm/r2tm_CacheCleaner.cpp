#include "r2tm_CacheCleaner.h"

#include <cstring>

#include "r2tm_WindowsUtility.h"

namespace r2tm
{
	CacheCleaner::CacheCleaner() : mCacheByteSize( r2tm::WindowsUtility::GetCPUCacheSize() ), mBufferSize( 0 ), mBuffer( nullptr ), mSum( 0 )
	{
		mCacheByteSize = r2tm::WindowsUtility::GetCPUCacheSize();
		mBufferSize = ( mCacheByteSize / sizeof( BufferT ) );
		mBuffer = new BufferT[mBufferSize];

		std::memset( mBuffer, 1, mCacheByteSize );
	}

	CacheCleaner::~CacheCleaner()
	{
		delete[] mBuffer;
	}

	void CacheCleaner::Do()
	{
		mSum = 0;
		for( int i = 0; mBufferSize > i; ++i )
		{
			mSum += mBuffer[i];
		}
	}
}