/*######################################################
#
# + Summary
#   > Cache 크기 만큼의 메모리에 강제 접근.
#   > L1, L2, L3 캐쉬를 무의미한 데이터로 채운다.
#
######################################################*/

#pragma once

namespace r2tm
{
	class CacheCleaner
	{
	public:
		using BufferT = unsigned long long;

		CacheCleaner();
		~CacheCleaner();

		//
		//
		//
		int GetCacheByteSize() const
		{
			return mCacheByteSize;
		}
		int GetBufferSize() const
		{
			return mBufferSize;
		}

		//
		//
		//
		void Clean();

	private:
		int mCacheByteSize;
		int mBufferSize;
		BufferT* mBuffer;
	};
}
