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
		if( 0 == ( position % linefeed_limit ) )
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
void SHOW_BINARY( const T* array, const int64_t array_size )
{
	const int64_t size = sizeof( T );

	const int32_t line_per_value = ( 8 / size );
	int32_t value_print_count = 0;

	int32_t u8_print_count = 0;

	printf( "\n\t> " );

	for( int64_t array_index = 0; array_size > array_index; ++array_index )
	{
		const uint8_t* cp = reinterpret_cast<const uint8_t*>( array + array_index );

		for( int64_t u8_index = 0, fixed_size = size - 1; fixed_size >= u8_index; ++u8_index )
		{
			if( ( 8 <= u8_print_count ) && ( fixed_size > u8_index ) )
			{
				u8_print_count = 0;
				printf( "\n\t~ " );
			}

			SHOW_BINARY( *( cp + ( fixed_size - u8_index ) ) );
			printf( " " );

			++u8_print_count;
		}

		++value_print_count;
		if( ( line_per_value <= value_print_count ) && ( array_size - 1 > array_index ) )
		{
			value_print_count = 0;
			u8_print_count = 0;
			printf( "\n\t> " );
		}
		else
		{
			printf( "  " );
		}
	}
}

#endif
