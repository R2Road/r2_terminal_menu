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
