#include "r2cm_PrintFile.h"

#include <stdio.h>

namespace r2cm
{
	void PrintFile( const char* const path )
	{
		printf( "\x1B[90m" "[FILE]" " %s" "\033[0m" "\n", path );

		FILE* fp = nullptr;
		if( 0 == fopen_s( &fp, path, "rb" ) )
		{
			static char buffer[100];
			int cur = 1;
			while( !feof( fp ) )
			{
				fgets( buffer, sizeof( buffer ), fp );
				printf( "%4d | " " " "%s", cur, buffer );

				++cur;
			}
			printf( "\n" );
		}

		fclose( fp );

		printf( "\x1B[90m" "[/FILE]" "\033[0m" "\n" );
	}

	void PrintFile( const char* const path, const unsigned int min, const unsigned int max )
	{
		printf( "\x1B[90m" "[FILE]" " %s" " : %d ~ %d" "\033[0m" "\n", path, min, max );

		FILE* fp = nullptr;
		if( 0 == fopen_s( &fp, path, "rb" ) )
		{
			static char buffer[100];
			for( int cur = 1; !feof( fp ) && cur <= max; ++cur )
			{
				fgets( buffer, sizeof( buffer ), fp );

				if( min > cur )
				{
					continue;
				}

				printf( "%4d | " " " "%s", cur, buffer );
			}
			printf( "\n" );
		}

		fclose( fp );

		printf( "\x1B[90m" "[/FILE]" "\033[0m" "\n" );
	}
}