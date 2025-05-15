#include "menu_root.h"

#include <string>

#include "r2tm/r2tm_Director.h"
#include "r2tm/r2tm_ostream.h"
#include "r2tm/r2tm_VersionInfo.h"

#include "test/test_empty.h"
#include "test/test_key.h"
#include "test/test_stop_watch.h"

#include "test/menu_test.h"
#include "test/menu_cache_cleaner.h"
#include "test/menu_color_modifier.h"
#include "test/menu_inspector.h"
#include "test/menu_leave_action.h"
#include "test/menu_stop_watch.h"
#include "test/menu_windows_utility.h"

#include "version_viewer.h"

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
		mp->AddMessage( "# Test를 r2tm::iItem을 사용해 만들기", r2tm::eColor::FG_LightRed );
		mp->AddItem( '1', test_empty::Basic() );
		mp->AddMessage( "# 동일한 Test를 여러 키에 할당 해보기", r2tm::eColor::FG_LightRed );
		mp->AddItem( '2', test_empty::Basic() );



		mp->AddLineFeed();



		mp->AddMessage( "# Test를 r2tm::iItem 안쓰고 만들기", r2tm::eColor::FG_LightRed );
		mp->AddItem(
			'3'
			, []()->const char*
			{
				return "Show Title With Lambda";
			}
			, []()->r2tm::eDoLeaveAction
			{
				LS();

				std::cout << r2tm::linefeed2 << "##### Show Title With Lambda #####" << r2tm::linefeed3;

				LS();

				return r2tm::eDoLeaveAction::Pause;
			}
		);



		mp->AddLineFeed();



		mp->AddMessage( "# Test를 r2tm::iMenu 객체로 묶어보기", r2tm::eColor::FG_LightRed );
		mp->AddMenu( '6', Menu_Test() );



		mp->AddLineFeed();



		mp->AddMenu( 'q', Menu_LeaveAction() );
		mp->AddMenu( 'w', Menu_ColorModifier() );
		mp->AddMenu( 'e', Menu_StopWatch() );
		mp->AddMenu( 'r', Menu_Inspector() );



		mp->AddLineFeed();



		mp->AddMenu( 'a', Menu_WindowsUtility() );
		mp->AddMenu( 's', Menu_CacheCleaner() );



		mp->AddLineFeed();



		mp->AddItem( 'z', test_key::View() );
		mp->AddItem( 'x', version_viewer::Viewer() );
		



		mp->AddSplit();



		mp->AddExit( 27 );
	};
}