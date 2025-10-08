#pragma once

#include <iostream>

#include "r2tm_file.hpp"
#include "r2tm_input.hpp"
#include "r2tm_print_binary.hpp"
#include "r2tm_print_file.hpp"

#define R2TM_ENABLE_DEBUG_BREAK 0

#if defined( R2TM_ENABLE_DEBUG_BREAK ) && R2TM_ENABLE_DEBUG_BREAK == 1
	#define R2TM_DEBUG_BREAK ( __debugbreak() )
#else
	#define R2TM_DEBUG_BREAK
#endif // R2TM_ENABLE_DEBUG_BREAK



//
//
//
#define	EXPECT_TRUE( condition )																\
do {																							\
	if( ( condition ) )																			\
	{																							\
		printf( "\x1B[92m" "[PASS]" "\033[0m" " EXPECT_TRUE( %s )\n", #condition );				\
	}																							\
	else																						\
	{																							\
		R2TM_DEBUG_BREAK;																		\
		printf( "\x1B[91m" "[FAIL]" "\033[0m" " EXPECT_TRUE( %s )\n", #condition );			\
	}																							\
} while( false )

#define	EXPECT_FALSE( condition )																\
do {																							\
	if( !( condition ) )																		\
	{																							\
		printf( "\x1B[94m" "[PASS]" "\033[0m" " EXPECT_FALSE( %s )\n", #condition );			\
	}																							\
	else																						\
	{																							\
		R2TM_DEBUG_BREAK;																		\
		printf( "\x1B[91m" "[FAIL]" "\033[0m" " EXPECT_FALSE( %s )\n", #condition );			\
	}																							\
} while( false )

#define	EXPECT_EQ( condition_1, condition_2 )																	\
do {																											\
	if( ( condition_1 ) == ( condition_2 ) )																	\
	{																											\
		printf( "\x1B[92m" "[PASS]" "\033[0m" " EXPECT_EQ( %s == %s )\n", #condition_1, #condition_2 );			\
	}																											\
	else																										\
	{																											\
		R2TM_DEBUG_BREAK;																						\
		printf( "\x1B[91m" "[FAIL]" "\033[0m" " EXPECT_EQ( %s == %s )\n", #condition_1, #condition_2 );		\
		OUT_VALUE( ( condition_1 ) );																		\
		OUT_VALUE( ( condition_2 ) );																		\
	}																											\
} while( false )

#define	EXPECT_NE( condition_1, condition_2 )																	\
do {																											\
	if( ( condition_1 ) != ( condition_2 ) )																	\
	{																											\
		printf( "\x1B[94m" "[PASS]" "\033[0m" " EXPECT_NE( %s != %s )\n", #condition_1, #condition_2 );			\
	}																											\
	else																										\
	{																											\
		R2TM_DEBUG_BREAK;																						\
		printf( "\x1B[91m" "[FAIL]" "\033[0m" " EXPECT_NE( %s != %s )\n", #condition_1, #condition_2 );		\
		OUT_VALUE( ( condition_1 ) );																		\
		OUT_VALUE( ( condition_2 ) );																		\
	}																											\
} while( false )

#define	EXPECT_GT( condition_1, condition_2 )																	\
do {																											\
	if( ( condition_1 ) > ( condition_2 ) )																		\
	{																											\
		printf( "\x1B[92m" "[PASS]" "\033[0m" " EXPECT_GT( %s > %s )\n", #condition_1, #condition_2 );			\
	}																											\
	else																										\
	{																											\
		R2TM_DEBUG_BREAK;																						\
		printf( "\x1B[91m" "[FAIL]" "\033[0m" " EXPECT_GT( %s > %s )\n", #condition_1, #condition_2 );		\
		OUT_VALUE( ( condition_1 ) );																		\
		OUT_VALUE( ( condition_2 ) );																		\
	}																											\
} while( false )

#define	EXPECT_LT( condition_1, condition_2 )																	\
do {																											\
	if( ( condition_1 ) < ( condition_2 ) )																		\
	{																											\
		printf( "\x1B[92m" "[PASS]" "\033[0m" " EXPECT_LT( %s < %s )\n", #condition_1, #condition_2 );			\
	}																											\
	else																										\
	{																											\
		R2TM_DEBUG_BREAK;																						\
		printf( "\x1B[91m" "[FAIL]" "\033[0m" " EXPECT_LT( %s < %s )\n", #condition_1, #condition_2 );		\
		OUT_VALUE( ( condition_1 ) );																		\
		OUT_VALUE( ( condition_2 ) );																		\
	}																											\
} while( false )

#define	EXPECT_GE( condition_1, condition_2 )																	\
do {																											\
	if( ( condition_1 ) >= ( condition_2 ) )																	\
	{																											\
		printf( "\x1B[92m" "[PASS]" "\033[0m" " EXPECT_GE( %s >= %s )\n", #condition_1, #condition_2 );			\
	}																											\
	else																										\
	{																											\
		R2TM_DEBUG_BREAK;																						\
		printf( "\x1B[91m" "[FAIL]" "\033[0m" " EXPECT_GE( %s >= %s )\n", #condition_1, #condition_2 );		\
		OUT_VALUE( ( condition_1 ) );																		\
		OUT_VALUE( ( condition_2 ) );																		\
	}																											\
} while( false )

#define	EXPECT_LE( condition_1, condition_2 )																	\
do {																											\
	if( ( condition_1 ) <= ( condition_2 ) )																	\
	{																											\
		printf( "\x1B[92m" "[PASS]" "\033[0m" " EXPECT_LE( %s <= %s )\n", #condition_1, #condition_2 );			\
	}																											\
	else																										\
	{																											\
		R2TM_DEBUG_BREAK;																						\
		printf( "\x1B[91m" "[FAIL]" "\033[0m" " EXPECT_LE( %s <= %s )\n", #condition_1, #condition_2 );		\
		OUT_VALUE( ( condition_1 ) );																		\
		OUT_VALUE( ( condition_2 ) );																		\
	}																											\
} while( false )




//
// Epsilon EQ
//
constexpr float r2tm_epsilon_float = 0.00001f;
inline bool epsilon_equal( const float v1, const float v2 )
{
	return ( r2tm_epsilon_float > std::abs( v1 - v2 ) );
}

constexpr double r2tm_epsilon_double = 0.0000000001;
inline bool epsilon_equal( const double v1, const double v2 )
{
	return ( r2tm_epsilon_double > std::abs( v1 - v2 ) );
}

#define	EXPECT_EP_EQ( condition_1, condition_2 )																\
do {																											\
	if( epsilon_equal( condition_1, condition_2 ) )																\
	{																											\
		printf( "\x1B[92m" "[PASS]" "\033[0m" " EXPECT_EP_EQ( %s == %s )\n", #condition_1, #condition_2 );		\
	}																											\
	else																										\
	{																											\
		R2TM_DEBUG_BREAK;																						\
		printf( "\x1B[91m" "[FAIL]" "\033[0m" " EXPECT_EP_EQ( %s == %s )\n", #condition_1, #condition_2 );	\
		OUT_VALUE( ( condition_1 ) );																		\
		OUT_VALUE( ( condition_2 ) );																		\
	}																											\
} while( false )

#define	EXPECT_EP_NE( condition_1, condition_2 )																\
do {																											\
	if( !epsilon_equal( condition_1, condition_2 ) )															\
	{																											\
		printf( "\x1B[94m" "[PASS]" "\033[0m" " EXPECT_EP_NE( %s != %s )\n", #condition_1, #condition_2 );		\
	}																											\
	else																										\
	{																											\
		R2TM_DEBUG_BREAK;																						\
		printf( "\x1B[91m" "[FAIL]" "\033[0m" " EXPECT_EP_NE( %s != %s )\n", #condition_1, #condition_2 );	\
		OUT_VALUE( ( condition_1 ) );																		\
		OUT_VALUE( ( condition_2 ) );																		\
	}																											\
} while( false )




//
// Important Process Code
//
#define	PROC_MAIN( condition )															\
do {																						\
	printf( "\x1B[96m" "[PROC]" "\033[0m" " %s\n", #condition );							\
	{ condition; }																			\
} while( false )
//
// Sub Process Code
//
#define	PROC_SUB( condition )															\
do {																						\
	printf( "\x1B[90m" "[PROC]" " %s" "\033[0m" "\n", #condition );						\
	{ condition; }																			\
} while( false )




//
// Important Declaration Code
//
#define	DECL_MAIN( condition )														\
printf( "\x1B[93m" "[DECL]" "\033[0m" " %s\n", #condition );							\
condition;
//
// Sub Declaration Code
//
#define	DECL_SUB( condition )														\
printf( "\x1B[90m" "[DECL]" " %s" "\033[0m" "\n", #condition );						\
condition;




//
// Output Value
//
#define	OUT_VALUE( condition )															\
do {																						\
	printf( "[VALUE]" " %s" "\n", #condition );												\
	std::cout << "\t> " << condition << "\n";												\
} while( false )




//
// Output Address
//
#define	OUT_ADDRESS( condition )															\
do {																						\
	printf( "[ADDRESS]" " %s" "\n", #condition );											\
	std::cout << "\t> " << ( &condition ) << "\n";											\
} while( false )




//
// Output Binary
//
#define	OUT_BINARY( condition )															\
do {																						\
	printf( "[BINARY]" " %s", #condition );													\
	r2tm::PrintBinary( ( condition ) );														\
	printf( "\n" );																			\
} while( false )

//
// + example : int a[4];
// pointer : int*
// size : 4
//
#define	OUT_BINARIES( pointer, size )													\
do {																						\
	printf( "[BINARIES]" " %s" ", %s", #pointer, #size );									\
	r2tm::PrintBinary( ( pointer ), ( size ) );												\
	printf( "\n" );																			\
} while( false )




//
// Output Code
//
#define	OUT_CODE( condition )															\
do {																						\
	printf( "[CODE]"  "\x1B[90m"  " %s"  "\033[0m"  "\n", #condition );						\
} while( false )




//
// Output Size
//
#if _WIN64 == 1

#define	OUT_SIZE( condition )															\
do {																						\
	printf( "[SIZE]" " %s" "\n" "\t> %llu" " byte" "\n", #condition, sizeof( condition ) );	\
} while( false )

#else

#define	OUT_SIZE( condition )															\
do {																						\
	printf( "[SIZE]" " %s" "\n" "\t> %u" " byte" "\n", #condition, sizeof( condition ) );	\
} while( false )

#endif




//
// Output Align
//
#define	OUT_ALIGN( condition )															 \
do {																						 \
	printf( "[ALIGN]" " %s" "\n" "\t> %llu" " byte" "\n", #condition, alignof( condition ) ); \
} while( false )




//
// Output ETC
//
#define	OUT_STRING( str )																\
do {																						\
	printf( "%s"  "\n", str );																\
} while( false )

#define	OUT_NOTE( str )																	\
do {																						\
	printf( "\t"  "\x1B[91m"  "[ NOTE ] "  "%s"  "\033[0m"  "\n", str );					\
} while( false )

#define	OUT_SUBJECT( str )																\
do {																						\
	printf( "\t"  "\x1B[92m"  "# "  "%s"  "\033[0m"  "\n", str );							\
} while( false )

#define	OUT_COMMENT( str )																\
do {																						\
	printf( "\t"  "\x1B[93m"  "> " "%s"  "\033[0m"  "\n", str );							\
} while( false )




//
// File
//
#define OUT_FILE( file_path )															\
do {																						\
	r2tm::PrintFile( file_path );															\
} while( false )

#define OUT_FILE_CUR_DIR( file_path )														\
do {																						\
	r2tm::PrintFile( __FILE__, file_path );													\
} while( false )

#define OUT_FILE_RANGE( file_path, min, max )											\
do {																						\
	r2tm::PrintFile( file_path, min, max );													\
} while( false )

#define OUT_SOURCE_READY		int src_begin, src_end = -1
#define OUT_SOURCE_BEGIN		do { src_begin = __LINE__ + 1; } while( false )
#define OUT_SOURCE_END		do { src_end = __LINE__ - 1; r2tm::PrintFile( __FILE__, src_begin, src_end ); } while( false )

#define OUT_SOURCE_READY_N_BEGIN		OUT_SOURCE_READY; OUT_SOURCE_BEGIN

#define DIR_OPEN( file_path )															\
do {																						\
	r2tm::DirectoryOpen( file_path );															\
} while( false )




//
// INPUT
//
#define WAIT_ANY_KEY	  ( r2tm::WaitAnyKey() )

#define GET_KEY	          ( r2tm::GetKey() )

#define KB_HIT            ( r2tm::KeyboardHit() )

#define CLEAR_INPUT       ( r2tm::ClearInput() )