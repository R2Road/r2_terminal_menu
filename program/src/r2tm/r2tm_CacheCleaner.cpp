#include "r2tm_CacheCleaner.h"

#include <cstring>

#include "r2tm_WindowsUtility.h"

namespace r2tm
{
	CacheCleaner::CacheCleaner() : mCacheByteSize( 0 ), mBufferSize( 0 ), mBuffer( nullptr )
	{
		mCacheByteSize = r2tm::WindowsUtility::GetCPUCacheSize();
		mBufferSize = ( mCacheByteSize / sizeof( BufferT ) );
		mBuffer = new BufferT[mBufferSize];

		std::memset( mBuffer, 0, mCacheByteSize );
	}

	CacheCleaner::~CacheCleaner()
	{
		delete[] mBuffer;
	}

	void CacheCleaner::Do()
	{
		for( int i = 0; mBufferSize > i; ++i )
		{
			mBuffer[i] = 1;
		}
	}
}