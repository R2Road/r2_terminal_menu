#include "test_cache_cleaner.hpp"

#include <memory>

#include "r2tm/r2tm_Inspector.h"
#include "r2tm/r2tm_ostream.h"

#include "r2tm/r2tm_CacheCleaner.h"
#include "r2tm/r2tm_StopWatch.h"
#include "r2tm/r2tm_WindowsUtility.h"

namespace test_cache_cleaner
{
	r2tm::TitleFunctionT Basic::GetTitleFunction() const
	{
		return []()->const char*
		{
			return "Cache Cleaner : Basic";
		};
	}
	r2tm::DoFunctionT Basic::GetDoFunction() const
	{
		return []()->r2tm::eDoLeaveAction
		{
			LS();

			{
				DECL_MAIN( r2tm::CacheCleaner c );

				LF();

				EXPECT_EQ( 1, c.GetBufferScale() );
				OUTPUT_VALUE( c.GetBufferScale() );

				LF();

				EXPECT_EQ( r2tm::WindowsUtility::GetCPUCacheSize(), c.GetCacheByteSize() );
				OUTPUT_VALUE( c.GetCacheByteSize() );

				LF();

				EXPECT_EQ( r2tm::WindowsUtility::GetCPUCacheSize(), c.GetBufferSize() * sizeof( r2tm::CacheCleaner::BufferT ) / c.GetBufferScale() );
				OUTPUT_VALUE( c.GetBufferSize() );
				OUTPUT_VALUE( sizeof( r2tm::CacheCleaner::BufferT ) );

				LF();

				PROC_MAIN( c.Clean() );
				OUTPUT_COMMENT( "���� ������ ȣ�� �غ���." );
			}

			LS();

			{
				DECL_MAIN( r2tm::CacheCleaner c( 2 ) );

				LF();

				EXPECT_EQ( 2, c.GetBufferScale() );
				OUTPUT_VALUE( c.GetBufferScale() );

				LF();

				EXPECT_EQ( r2tm::WindowsUtility::GetCPUCacheSize(), c.GetCacheByteSize() );
				OUTPUT_VALUE( c.GetCacheByteSize() );

				LF();

				EXPECT_EQ( r2tm::WindowsUtility::GetCPUCacheSize(), c.GetBufferSize() * sizeof( r2tm::CacheCleaner::BufferT ) / c.GetBufferScale() );
				OUTPUT_VALUE( c.GetBufferSize() );
				OUTPUT_VALUE( sizeof( r2tm::CacheCleaner::BufferT ) );

				LF();

				PROC_MAIN( c.Clean() );
				OUTPUT_COMMENT( "���� ������ ȣ�� �غ���." );
			}

			LS();

			return r2tm::eDoLeaveAction::Pause;
		};
	}



	r2tm::TitleFunctionT Size::GetTitleFunction() const
	{
		return []()->const char*
		{
			return "Cache Cleaner : Size";
		};
	}
	r2tm::DoFunctionT Size::GetDoFunction() const
	{
		return []()->r2tm::eDoLeaveAction
		{
			LS();

			DECL_MAIN( r2tm::CacheCleaner c );

			LF();

			OUTPUT_SIZE( c );

			LF();

			OUTPUT_BINARY( c );

			SS();

			OUTPUT_SIZE( c.GetBufferScale() );
			OUTPUT_BINARY( c.GetBufferScale() );

			LF();

			OUTPUT_SIZE( c.GetCacheByteSize() );
			OUTPUT_BINARY( c.GetCacheByteSize() );

			LF();

			OUTPUT_SIZE( c.GetBufferSize() );
			OUTPUT_BINARY( c.GetBufferSize() );

			LS();

			return r2tm::eDoLeaveAction::Pause;
		};
	}



	r2tm::TitleFunctionT Test::GetTitleFunction() const
	{
		return []()->const char*
		{
			return "Cache Cleaner : Test";
		};
	}
	r2tm::DoFunctionT Test::GetDoFunction() const
	{
		return []()->r2tm::eDoLeaveAction
		{
			LS();

			//
			// BUFFER_SIZE �� ����ġ�� Ŀ���� �������� �������.
			// > 16000 byte�� �׽�Ʈ ���� �� �׷���.
			// > �׽�Ʈ ȯ���� L3 ĳ�� ����� 16000 byte
			// > ��ǻ� ĳ���� ���ظ� �Ǵ� ȯ���̴�.
			//
			DECL_MAIN( const int BUFFER_SIZE = 2000 );
			DECL_MAIN( std::shared_ptr<int[]> BufferSp( new int[BUFFER_SIZE] ) );
			DECL_MAIN( int* Buffer = BufferSp.get() );
			DECL_MAIN( r2tm::CacheCleaner c( 2 ) );

			LS();

			DECL_MAIN( r2tm::StopWatch s );
			DECL_MAIN( const int attempt = 10 );

			LS();

			{
				c.Clean();

				OUTPUT_SUBJECT( "�׽�Ʈ �ڵ� �۵� + CacheCleaner X" );
				for( int i = 0; attempt > i; ++i )
				{
					s.Start();

					for( int buffer_index = 0; BUFFER_SIZE > buffer_index; ++buffer_index )
					{
						Buffer[buffer_index] = buffer_index;
					}

					s.Stop();
					s.PrintElapsedTime_NanoSeconds();
					LF();
				}

				SS();

				OUTPUT_SUBJECT( "�׽�Ʈ �ڵ� �۵� + CacheCleaner O" );
				for( int i = 0; attempt > i; ++i )
				{
					//
					// Clear Cache
					//
					c.Clean();

					s.Start();

					for( int buffer_index = 0; BUFFER_SIZE > buffer_index; ++buffer_index )
					{
						Buffer[buffer_index] = buffer_index;
					}

					s.Stop();
					s.PrintElapsedTime_NanoSeconds();

					LF();
				}
			}

			LS();

			return r2tm::eDoLeaveAction::Pause;
		};
	}



	r2tm::TitleFunctionT Test_Accumulate::GetTitleFunction() const
	{
		return []()->const char*
		{
			return "Cache Cleaner : Test Accumulate";
		};
	}
	r2tm::DoFunctionT Test_Accumulate::GetDoFunction() const
	{
		return []()->r2tm::eDoLeaveAction
		{
			LS();

			DECL_MAIN( const int BUFFER_SIZE = 2000 );
			DECL_MAIN( std::shared_ptr<int[]> BufferSp( new int[BUFFER_SIZE] ) );
			DECL_MAIN( int* Buffer = BufferSp.get() );
			DECL_MAIN( r2tm::CacheCleaner c( 2 ) );

			LS();

			DECL_MAIN( r2tm::StopWatch s );
			DECL_MAIN( const int attempt = 100 );

			LS();

			{
				c.Clean();

				OUTPUT_SUBJECT( "�׽�Ʈ �ڵ� �۵� + CacheCleaner X" );
				for( int i = 0; attempt > i; ++i )
				{
					s.Start();

					for( int buffer_index = 0; BUFFER_SIZE > buffer_index; ++buffer_index )
					{
						Buffer[buffer_index] = buffer_index;
					}

					s.Stop();
				}

				s.PrintAverageTime_NanoSeconds();
				LF();

				SS();

				s.Reset();

				OUTPUT_SUBJECT( "�׽�Ʈ �ڵ� �۵� + CacheCleaner O" );
				for( int i = 0; attempt > i; ++i )
				{
					//
					// Clear Cache
					//
					c.Clean();

					s.Start();

					for( int buffer_index = 0; BUFFER_SIZE > buffer_index; ++buffer_index )
					{
						Buffer[buffer_index] = buffer_index;
					}

					s.Stop();
				}

				s.PrintAverageTime_NanoSeconds();
				LF();
			}

			LS();

			return r2tm::eDoLeaveAction::Pause;
		};
	}
}