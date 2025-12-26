#pragma once

#include <stdio.h>

namespace r2tm
{
	template<typename T>
	void PrintAddress( const T& value )
	{
		printf( "%p", &value );
	}

	template<typename ReturnT, typename OwnerT, typename ... ArgsT >
	void PrintAddress( ReturnT( OwnerT::* const value )( ArgsT ... ) )
	{
		printf( "%p", ( void*& )value );
	}

	// const
	template<typename ReturnT, typename OwnerT, typename ... ArgsT >
	void PrintAddress( ReturnT( OwnerT::* const value )( ArgsT ... ) const )
	{
		printf( "%p", ( void*& )value );
	}
}