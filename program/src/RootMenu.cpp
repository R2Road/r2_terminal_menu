#include "RootMenu.h"

#include <string>

#include "r2tm/r2tm_Director.h"
#include "r2tm/r2tm_ostream.h"
#include "r2tm/r2tm_VersionInfo.h"

#include "test/item/test_base.h"
#include "test/item/test_color_modifier.h"
#include "test/item/test_empty.h"
#include "test/item/test_key.h"
#include "test/item/test_stop_watch.h"
#include "test/item/test_window_utility.h"

#include "test/AnotherMenu.h"
#include "test/InspectorMenu.h"

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



		ret->AddItem( 'q', test_key::View() );
		ret->AddItem( 'w', test_color_modifier::Basic() );
		ret->AddItem( 'e', test_stop_watch::Basic() );



		ret->AddLineFeed();



		ret->AddMenu( 'a', InspectorMenu() );



		ret->AddLineFeed();



		ret->AddMessage( "# Test의 끝에 반환하는 r2tm::eDoLeaveAction 의 효과", r2tm::eColor::FG_White, r2tm::eColor::BG_LightBlue );
		ret->AddItem( 'z', test_base::eDoLeaveAction_None() );
		ret->AddItem( 'x', test_base::eDoLeaveAction_Pause() );
		ret->AddItem( 'c', test_base::eDoLeaveAction_Exit() );



		ret->AddLineFeed();



		ret->AddItem( 'b', test_window_utility::MoveCursorWithClearBuffer() );
		ret->AddItem( 'n', test_window_utility::FillCharacter() );
		ret->AddItem( 'm', test_window_utility::FillColor() );
		ret->AddItem( ',', test_window_utility::FillString() );



		ret->AddSplit();



		ret->AddExit( 27 );
	};
}