#if defined( DEBUG ) || defined( _DEBUG )
	#include <vld.h>
#endif

#include "r2tm/r2tm_Director.h"
#include "r2tm/r2tm_VersionInfo.h"
#include "r2tm/r2tm_WindowUtility.h"

#include "RootMenu.h"

int main()
{
	//
	// Environment : Title
	//
	r2tm::WindowUtility::ChangeTitle( r2tm::VersionInfo.String4Version );

	//
	// Environment : Size
	//
	r2tm::WindowUtility::Resize( 1060, 960 );

	//
	// Environment : Position
	//
	r2tm::WindowUtility::Move( 0, 0 );

	//
	// Setup
	//
	r2tm::Director director;
	director.Setup( RootMenu() );

	//
	// Process
	//
	director.Run();

	return 0;
}
