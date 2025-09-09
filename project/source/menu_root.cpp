#include "menu_root.hpp"

#include <string>

#include "r2tm/r2tm_director.hpp"
#include "r2tm/r2tm_ostream.hpp"
#include "r2tm/r2tm_version_info.hpp"

#include "test/test_stop_watch.hpp"

#include "test/menu_cache_cleaner.hpp"
#include "test/menu_color_modifier.hpp"
#include "test/menu_inspector.hpp"
#include "test/menu_leave_action.hpp"
#include "test/menu_stop_watch.hpp"
#include "test/menu_windows_utility.hpp"

#include "tutorial/menu_tutorial.hpp"

#include "viewer/viewer_key.hpp"
#include "viewer/viewer_version.hpp"
#include "viewer/viewer_window_size.hpp"

#include "menu_portfolio.hpp"

r2tm::TitleFunctionT Menu_Root::GetTitleFunction() const
{
	return []()->const char*
	{
		static const std::string ret =
			std::string()

			+ "Root Menu"
			  " : "	"<"   "C++17" + ">"
			  ", "	"<"   "MS C/C++ : " + std::to_string( _MSC_VER ) + ">"
			  ", "	"<" + r2tm::VersionInfo.String4Version + ">"
			;
		return ret.c_str();
	};
}
r2tm::DescriptionFunctionT Menu_Root::GetDescriptionFunction() const
{
	return []()->const char*
	{
		static const std::string ret =
			std::string()

			+ r2tm::VersionInfo.String4VersionRule
			+ "\n"
			  "\n"
			  "\n"
			+ r2tm::VersionInfo.String4Road2NextVersion
		;
		return ret.c_str();
	};
}
r2tm::WriteFunctionT Menu_Root::GetWriteFunction() const
{
	return []( r2tm::MenuProcessor* mp )
	{
		mp->AddMenu( '1', Menu_Tutorial() );



		mp->AddLineFeed();



		mp->AddMenu( 'q', Menu_Inspector() );
		mp->AddMenu( 'w', Menu_LeaveAction() );
		mp->AddMenu( 'e', Menu_ColorModifier() );
		mp->AddMenu( 'r', Menu_StopWatch() );



		mp->AddLineFeed();



		mp->AddMenu( 'a', Menu_WindowsUtility() );
		mp->AddMenu( 's', Menu_CacheCleaner() );



		mp->AddLineFeed();



		mp->AddItem( 'z', viewer_key::View() );
		mp->AddItem( 'x', viewer_version::Viewer() );
		mp->AddItem( 'c', viewer_window_size::Viewer() );



		mp->AddSplit();



		mp->AddMenu( 27, Menu_Portfolio() );
	};
}