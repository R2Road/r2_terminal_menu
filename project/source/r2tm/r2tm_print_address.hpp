#pragma once

#include <stdio.h>

namespace r2tm
{
	template<typename T>
	void PrintAddress( const T& value )
	{
		printf( "\t> %p \n", &value );
	}
}