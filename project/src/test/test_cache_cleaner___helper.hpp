#include <memory>

namespace test_cache_cleaner___helper
{
	class Test
	{
	private:
		const int BUFFER_SIZE = 2000;
		std::shared_ptr<int[]> BufferSp;
		int* Buffer;

	public:
		Test() : BufferSp( new int[BUFFER_SIZE] ), Buffer( BufferSp.get() )
		{}

		void Do()
		{
			for( int buffer_index = 0; BUFFER_SIZE > buffer_index; ++buffer_index )
			{
				Buffer[buffer_index] = buffer_index;
			}
		}
	};
}