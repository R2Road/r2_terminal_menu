/*######################################################
#
# + Summary
#   > Cache ũ�� ��ŭ�� �޸𸮿� ���� ����.
#   > L1, L2, L3 ĳ���� ���ǹ��� �����ͷ� ä���.
#
######################################################*/

#pragma once

namespace r2tm
{
	class CacheCleaner
	{
	public:
		using BufferT = unsigned long long;

		CacheCleaner( const int buffer_scale = 1 );
		CacheCleaner( const CacheCleaner& c );
		~CacheCleaner();

		//
		//
		//
		CacheCleaner& operator=( const CacheCleaner& ) = delete;

		//
		//
		//
		int GetBufferScale() const
		{
			return mBufferScale;
		}
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
		const int mBufferScale;
		int mCacheByteSize;
		int mBufferSize;
		BufferT* mBuffer;
	};
}
