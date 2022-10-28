#pragma once

#ifndef BINARY_PRINT
#define BINARY_PRINT

#include <stdint.h>
#include <stdio.h>

template<typename T>
void SHOW_BINARY( const T value );

template<typename T>
void SHOW_BINARY( const T value )
{
	const int32_t size = sizeof( value ) - 1;
	const uint8_t* up = reinterpret_cast<const uint8_t*>( &value );

	const int32_t linefeed_limit = 10;

	for( int32_t position = 0; size >= position; ++position )
	{
		if( ( 0 == position % linefeed_limit ) && ( 0 != position ) )
		{
			printf( "\n\t> " );
		}

		SHOW_BINARY( *( up + ( size - position ) ) );
		printf( " " );
	}
}


template<>
void SHOW_BINARY<uint8_t>( const uint8_t value );


template<typename T>
void SHOW_BINARY( const T* p, const uint64_t size )
{
	const uint64_t fixed_limit = sizeof( T ) * size;
	const uint8_t* fixed_p = reinterpret_cast<const uint8_t*>( p );

	const uint64_t tab_limit = sizeof( T );
	uint64_t count_4_linefeed = 0;
	for( uint64_t i = 0; fixed_limit > i; ++i )
	{
		if( 0 == count_4_linefeed )
		{
			printf( "\t> " );
		}

		SHOW_BINARY( fixed_p[i] );

		++count_4_linefeed;
		if( 8 == count_4_linefeed && fixed_limit > ( i + 1 ) )
		{
			count_4_linefeed = 0;
			printf( "\n" );
		}
		else if( 0 < count_4_linefeed && 0 == count_4_linefeed % tab_limit )
		{
			printf( "   " );
		}
		else
		{
			printf( " " );
		}
	}
}

#endif
