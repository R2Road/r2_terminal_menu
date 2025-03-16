#include "test_cache_cleaner.h"

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
			return "Cache Cleaner";
		};
	}
	r2tm::DoFunctionT Basic::GetDoFunction() const
	{
		return []()->r2tm::eDoLeaveAction
		{
			LS();

			{
				DECLARATION_MAIN( r2tm::CacheCleaner c );

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

				PROCESS_MAIN( c.Clean() );
				OUTPUT_COMMENT( "문제 없는지 호출 해본다." );
			}

			LS();

			{
				DECLARATION_MAIN( r2tm::CacheCleaner c( 2 ) );

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

				PROCESS_MAIN( c.Clean() );
				OUTPUT_COMMENT( "문제 없는지 호출 해본다." );
			}

			LS();

			{
				DECLARATION_MAIN( const int BUFFER_SIZE = 4 * 250 * 32 );
				DECLARATION_MAIN( std::shared_ptr<int[]> BufferSp( new int [BUFFER_SIZE] ) );
				DECLARATION_MAIN( int* Buffer = BufferSp.get() );
				DECLARATION_MAIN( r2tm::CacheCleaner c( 2 ) );
				DECLARATION_MAIN( r2tm::StopWatch s );

				LF();

				c.Clean();

				OUTPUT_SUBJECT( "테스트 코드 작동 + CacheCleaner X" );
				for( int i = 0; 10 > i; ++i )
				{
					s.Start();

					for( int buffer_index = 0; BUFFER_SIZE > buffer_index; ++buffer_index )
					{
						Buffer[buffer_index] = 1;
					}

					s.Stop();
					s.PrintElapsedTime_NanoSeconds();
					LF();
				}

				LF();

				OUTPUT_SUBJECT( "테스트 코드 작동 + CacheCleaner O" );
				for( int i = 0; 10 > i; ++i )
				{
					//
					// Clear Cache
					//
					c.Clean();

					s.Start();

					for( int buffer_index = 0; BUFFER_SIZE > buffer_index; ++buffer_index )
					{
						Buffer[buffer_index] = 1;
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
}