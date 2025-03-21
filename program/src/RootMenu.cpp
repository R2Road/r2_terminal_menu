#include "RootMenu.h"

#include <string>

#include "r2tm/r2tm_Director.h"
#include "r2tm/r2tm_ostream.h"
#include "r2tm/r2tm_VersionInfo.h"

#include "test/test_base.h"
#include "test/test_color_modifier.h"
#include "test/test_empty.h"
#include "test/test_key.h"
#include "test/test_stop_watch.h"

#include "test/AnotherMenu.h"
#include "test/Menu_CacheCleaner.h"
#include "test/Menu_Inspector.h"
#include "test/Menu_StopWatch.h"
#include "test/Menu_WindowUtility.h"

r2tm::TitleFunctionT RootMenu::GetTitleFunction() const
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
r2tm::DescriptionFunctionT RootMenu::GetDescriptionFunction() const
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
r2tm::WriteFunctionT RootMenu::GetWriteFunction() const
{
	return []( r2tm::MenuProcessor* ret )
	{
		ret->AddMessage( "# Test를 r2tm::iItem을 사용해 만들기", r2tm::eColor::FG_LightRed );
		ret->AddItem( '1', test_empty::Basic() );
		ret->AddMessage( "# 동일한 Test를 여러 키에 할당 해보기", r2tm::eColor::FG_LightRed );
		ret->AddItem( '2', test_empty::Basic() );



		ret->AddLineFeed();



		ret->AddMessage( "# Test를 r2tm::iItem 안쓰고 만들기", r2tm::eColor::FG_LightRed );
		ret->AddItem(
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



		ret->AddLineFeed();



		ret->AddMessage( "# Test를 r2tm::iMenu 객체로 묶어보기", r2tm::eColor::FG_LightRed );
		ret->AddMenu( '6', AnotherMenu() );



		ret->AddLineFeed();



		ret->AddMessage( "# Test의 끝에 반환하는 r2tm::eDoLeaveAction 의 효과", r2tm::eColor::FG_White, r2tm::eColor::BG_LightBlue );
		ret->AddItem( 'q', test_base::eDoLeaveAction_None() );
		ret->AddItem( 'w', test_base::eDoLeaveAction_Pause() );
		ret->AddItem( 'e', test_base::eDoLeaveAction_Exit() );



		ret->AddLineFeed();



		ret->AddItem( 'a', test_key::View() );
		ret->AddItem( 's', test_color_modifier::Basic() );
		ret->AddMenu( 'd', Menu_StopWatch() );
		ret->AddMenu( 'f', Menu_Inspector() );



		ret->AddLineFeed();



		ret->AddMenu( 'z', Menu_WindowUtility() );
		ret->AddMenu( 'x', Menu_CacheCleaner() );
		



		ret->AddSplit();



		ret->AddExit( 27 );
	};
}