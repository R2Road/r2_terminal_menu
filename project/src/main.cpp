#if defined( DEBUG ) || defined( _DEBUG )
	#include <vld.h>
#endif

#include "r2tm/r2tm_director.hpp"
#include "r2tm/r2tm_version_info.hpp"
#include "r2tm/r2tm_windows_utility.hpp"

#include "menu_root.hpp"

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
	director.Setup( Menu_Root() );

	//
	// Process
	//
	director.Run();

	return 0;
}
