#pragma once

namespace r2tm
{
	void PrintFile( const char* path, const char* file_name_n_extension );
	void PrintFile( const char* const path );

	void PrintFile( const char* const path, const unsigned int min, const unsigned int max );
}