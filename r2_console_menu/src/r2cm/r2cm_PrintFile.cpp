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
			while( !feof( fp ) )
			{
				fgets( buffer, sizeof( buffer ), fp );
				printf( "\t" "%s", buffer );
			}
			printf( "\n" );
		}

		fclose( fp );

		printf( "\x1B[90m" "[/FILE]" "\033[0m" "\n" );
	}
}