#include "RootMenu.h"

#include <string>

#include "r2cm/r2cm_Director.h"
#include "r2cm/r2cm_ostream.h"
#include "r2cm/r2cm_VersionInfo.h"

#include "test/item/base_test.h"
#include "test/item/color_modifier_test.h"
#include "test/item/empty_test.h"
#include "test/item/key_test.h"
#include "test/item/window_utility_test.h"

#include "test/AnotherMenu.h"
#include "test/InspectorMenu.h"

r2cm::TitleFunctionT RootMenu::GetTitleFunction() const
{
	return []()->const char*
	{
		static const std::string ret =
			std::string( "Root Menu" )

			+ " : "	"<" + "C++17" + ">"
			+ ", "	"<" + "MS C/C++ : " + std::to_string( _MSC_VER ) + ">"
			+ ", "	"<" + r2cm::VersionInfo.String4Version + ">"
			;
		return ret.c_str();
	};
}
r2cm::DescriptionFunctionT RootMenu::GetDescriptionFunction() const
{
	return []()->const char*
	{
		return r2cm::VersionInfo.String4Road2Version_1_0_5;
	};
}
r2cm::WriteFunctionT RootMenu::GetWriteFunction() const
{
	return []( r2cm::Menu* ret )
	{
		ret->AddItem( '1', empty_test::Basic() );
		ret->AddItem( '2', empty_test::Basic() );
		ret->AddItem(
			'3'
			, []()->const char* { return "Show Title With Lambda"; }
			, []()->r2cm::eDoLeaveAction
			{
				std::cout << r2cm::split;

				std::cout << r2cm::linefeed2 << "##### Show Title With Lambda #####" << r2cm::linefeed3;

				std::cout << r2cm::split;

				return r2cm::eDoLeaveAction::Pause;
			}
		);



		ret->AddLineFeed();



		ret->AddMenu( '6', AnotherMenu() );



		ret->AddLineFeed();



		ret->AddItem( 'q', key_test::Basic() );
		ret->AddItem( 'w', color_modifier_test::Basic() );



		ret->AddLineFeed();



		ret->AddMenu( 'a', InspectorMenu() );



		ret->AddLineFeed();



		ret->AddItem( 'z', base_test::TestEndAction_None() );
		ret->AddItem( 'x', base_test::TestEndAction_Pause() );
		ret->AddItem( 'c', base_test::TestEndAction_Exit() );



		ret->AddLineFeed();



		ret->AddItem( 'b', window_utility_test::MoveCursorWithClearBuffer() );
		ret->AddItem( 'n', window_utility_test::FillColor() );



		ret->AddSplit();



		ret->AddItem(
			27
			, r2cm::eColor::BG_Purple
			, []()->const char* { return "Exit"; }
		, []()->r2cm::eDoLeaveAction { return r2cm::eDoLeaveAction::Exit; }
		);
	};
}