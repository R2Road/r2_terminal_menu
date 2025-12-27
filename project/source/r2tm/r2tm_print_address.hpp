#pragma once

#include <stdio.h>
#include <type_traits>

namespace r2tm
{
	template<typename T>
	void PrintAddress( const T& value )
	{
		printf( "%p", &value );
	}

	template<typename ReturnT, typename ... ArgsT >
	void PrintAddress( ReturnT( * const value )( ArgsT ... ) )
	{
		printf( "%p", ( void* )value );
	}

	template<typename ReturnT, typename OwnerT, typename ... ArgsT >
	void PrintAddress( ReturnT( OwnerT::* const value )( ArgsT ... ) )
	{
		printf( "%p", ( void*& )value );
	}
	template<typename ReturnT, typename OwnerT, typename ... ArgsT >
	void PrintAddress( ReturnT( OwnerT::* const value )( ArgsT ... ) const )
	{
		printf( "%p", ( void*& )value );
	}


	
	template<typename T>
	typename std::enable_if<!std::is_function_v<T>, void* >::type Convert2VoidPointer( const T* value )
	{
		return ( void* )value;
	}

	template<typename ReturnT, typename ... ArgsT >
	void* Convert2VoidPointer( ReturnT( * const value )( ArgsT ... ) )
	{
		return ( void* )value;
	}

	template<typename ReturnT, typename OwnerT, typename ... ArgsT >
	void* Convert2VoidPointer( ReturnT( OwnerT::* const value )( ArgsT ... ) )
	{
		return ( void*& )value;
	}
	template<typename ReturnT, typename OwnerT, typename ... ArgsT >
	void* Convert2VoidPointer( ReturnT( OwnerT::* const value )( ArgsT ... ) const )
	{
		return ( void*& )value;
	}
}