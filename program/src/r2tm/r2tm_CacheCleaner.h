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
		using BufferT = char;

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
		void Do();

	private:
		int mCacheByteSize;
		int mBufferSize;
		BufferT* mBuffer;
	};
}
