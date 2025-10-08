#include "r2tm_print_file.hpp"

#include <filesystem>
#include <stdio.h>

namespace r2tm
{
	FILE* OpenFile( const char* const path )
	{
		FILE* fp = nullptr;

		if( 0 != fopen_s( &fp, path, "rb" ) )
		{
			__debugbreak();
		}

		return fp;
	}

	void CloseFile( FILE* fp )
	{
		if( nullptr != fp )
		{
			fclose( fp );
		}
	}

	const char* GetLine( FILE* fp )
	{
		static char buffer[400];
		fgets( buffer, sizeof( buffer ), fp );

		return buffer;
	}

	void PrintFile( const char* file_path, const char* file_name_n_extension )
	{
		std::filesystem::path p( file_path );
		p.replace_filename( file_name_n_extension );

		PrintFile( p.string().c_str() );
	}

	void PrintFile( const char* const path )
	{
		printf( "\x1B[90m" "[FILE]" " %s" "\033[0m" "\n", path );

		FILE* fp = OpenFile( path );
		if( fp )
		{
			unsigned int cur = 1;
			while( !feof( fp ) )
			{
				printf( "%4d | " " " "%s", cur, GetLine( fp ) );

				++cur;
			}
			printf( "\n" );
		}

		CloseFile( fp );

		printf( "\x1B[90m" "[/FILE]" "\033[0m" "\n" );
	}

	void PrintFile( const char* const path, const unsigned int min, const unsigned int max )
	{
		printf( "\x1B[90m" "[FILE]" " %s" " : %d ~ %d" "\033[0m" "\n", path, min, max );

		FILE* fp = OpenFile( path );
		if( fp )
		{
			unsigned int cur = 1;
			const char* str = nullptr;
			while( !feof( fp ) )
			{
				str = GetLine( fp );

				if( min <= cur )
				{
					printf( "%4d | " " " "%s", cur, str );
				}

				++cur;
				if( cur > max )
				{
					break;
				}
			}

			if( feof( fp ) )
			{
				printf( "\n" );
			}
		}

		CloseFile( fp );

		printf( "\x1B[90m" "[/FILE]" "\033[0m" "\n" );
	}
}