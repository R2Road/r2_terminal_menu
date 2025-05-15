#if defined( DEBUG ) || defined( _DEBUG )
	#include <vld.h>
#endif

#include "r2tm/r2tm_Director.h"
#include "r2tm/r2tm_VersionInfo.h"
#include "r2tm/r2tm_WindowsUtility.h"

#include "menu_root.h"

int main()
{
	//
	// Environment : Title
	//
	r2tm::WindowsUtility::ChangeTitle( r2tm::VersionInfo.String4Version );

	//
	// Environment : Size
	//
	r2tm::WindowsUtility::Resize( 1060, 960 );

	//
	// Environment : Position
	//
	r2tm::WindowsUtility::Move( 0, 0 );

	//
	// Setup
	//
	r2tm::Director director;
	director.Setup( MenuRoot() );

	//
	// Process
	//
	director.Run();

	return 0;
}
