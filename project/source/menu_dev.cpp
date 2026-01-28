#include "menu_dev.hpp"

#include <string>

#include "r2tm/r2tm_director.hpp"
#include "r2tm/r2tm_ostream.hpp"
#include "r2tm/r2tm_version_info.hpp"
#include "r2tm/r2tm_viewer_key.hpp"
#include "r2tm/r2tm_viewer_version.hpp"
#include "r2tm/r2tm_viewer_window_size.hpp"

#include "test/menu_cache_cleaner.hpp"
#include "test/menu_color_modifier.hpp"
#include "test/menu_inspector.hpp"
#include "test/menu_inspector_demo.hpp"
#include "test/menu_inspector_file.hpp"
#include "test/menu_leave_action.hpp"
#include "test/menu_stop_watch.hpp"
#include "test/menu_windows_utility.hpp"

#include "tutorial/menu_tutorial.hpp"

#include "menu_portfolio.hpp"

r2tm::eStatus Menu_Dev::GetStatus() const
{
	return r2tm::eStatus::None;
}
r2tm::TitleFunctionT Menu_Dev::GetTitleFunction() const
{
	return []()->const char*
	{
		static const std::string ret =
			std::string()

			+ "Development Menu"
			  " : "	"<"   "C++17" + ">"
			  ", "	"<"   "MS C/C++ : " + std::to_string( _MSC_VER ) + ">"
			  ", "	"<" + r2tm::VersionInfo.String4Version + ">"
			;
		return ret.c_str();
	};
}
r2tm::DescriptionFunctionT Menu_Dev::GetDescriptionFunction() const
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
r2tm::WriteFunctionT Menu_Dev::GetWriteFunction() const
{
	return []( r2tm::MenuProcessor* mp )
	{
		mp->AddMenu( '1', Menu_Tutorial() );
		mp->AddMenu( '2', Menu_Demo() );



		mp->AddLineFeed();



		mp->AddMenu( 'q', Menu_Inspector() );
		mp->AddMenu( 'w', Menu_Inspector_File() );
		mp->AddMenu( 'e', Menu_LeaveAction() );
		mp->AddMenu( 'r', Menu_ColorModifier() );



		mp->AddLineFeed();



		mp->AddMenu( 'a', Menu_StopWatch() );
		mp->AddMenu( 's', Menu_WindowsUtility() );
		mp->AddMenu( 'd', Menu_CacheCleaner() );



		mp->AddLineFeed();


		mp->AddItem( 'z', r2tm_viewer::Key() );
		mp->AddItem( 'x', r2tm_viewer::Version( r2tm::VersionInfo.VersionHistory, r2tm::VersionInfo.VERSION_HISTORY_COUNT ) );
		mp->AddItem( 'c', r2tm_viewer::WindowSize() );



		mp->AddSplit();



		mp->AddMenu( 27, Menu_Portfolio() );
	};
}