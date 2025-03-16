#include "test_cache_cleaner.h"

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
				OUTPUT_COMMENT( "ï¿½ï¿½ï¿½ï¿½ ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½ È£ï¿½ï¿½ ï¿½Øºï¿½ï¿½ï¿½." );
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
				OUTPUT_COMMENT( "¹®Á¦ ¾ø´ÂÁö È£Ãâ ÇØº»´Ù." );
			}

			LS();

			{
				DECLARATION_MAIN( int Buffer[10000] = {} );
				DECLARATION_MAIN( r2tm::CacheCleaner c );
				DECLARATION_MAIN( r2tm::StopWatch s );

				LF();

				c.Clean();

				OUTPUT_SUBJECT( "Å×½ºÆ® ÄÚµå ÀÛµ¿ + CacheCleaner X" );
				for( int i = 0; 10 > i; ++i )
				{
					s.Start();

					for( int buffer_index = 0; 10000 > buffer_index; ++buffer_index )
					{
						Buffer[buffer_index] = 1;
					}

					s.Stop();
					s.PrintElapsedTime_NanoSeconds();
					LF();
				}

				LF();

				OUTPUT_SUBJECT( "Å×½ºÆ® ÄÚµå ÀÛµ¿ + CacheCleaner O" );
				for( int i = 0; 10 > i; ++i )
				{
					//
					// Clear Cache
					//
					c.Clean();

					s.Start();

					for( int buffer_index = 0; 10000 > buffer_index; ++buffer_index )
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