#if defined( DEBUG ) || defined( _DEBUG )
	#include <vld.h>
#endif

#include "r2cm/r2cm_Director.h"
#include "r2cm/r2cm_VersionInfo.h"
#include "r2cm/r2cm_WindowUtility.h"

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
	r2tm::WindowUtility::Resize( 860, 960 );

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
