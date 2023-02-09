#include "RootMenu.h"

#include <string>

#include "r2cm/r2cm_Director.h"
#include "r2cm/r2cm_ostream.h"
#include "r2cm/r2cm_VersionInfo.h"

#include "test/item/test_base.h"
#include "test/item/test_color_modifier.h"
#include "test/item/test_empty.h"
#include "test/item/test_key.h"
#include "test/item/test_window_utility.h"

#include "test/AnotherMenu.h"
#include "test/InspectorMenu.h"

r2cm::TitleFunctionT RootMenu::GetTitleFunction() const
{
	return []()->const char*
	{
		static const std::string ret =
			std::string()

			+ "Root Menu"
			  " : "	"<"   "C++17" + ">"
			  ", "	"<"   "MS C/C++ : " + std::to_string( _MSC_VER ) + ">"
			  ", "	"<" + r2cm::VersionInfo.String4Version + ">"
			;
		return ret.c_str();
	};
}
r2cm::DescriptionFunctionT RootMenu::GetDescriptionFunction() const
{
	return []()->const char*
	{
		static const std::string ret =
			std::string()

			+ r2cm::VersionInfo.String4VersionRule
			+ "\n"
			  "\n"
			  "\n"
			+ r2cm::VersionInfo.String4Road2Version_1_0_7
		;
		return ret.c_str();
	};
}
r2cm::WriteFunctionT RootMenu::GetWriteFunction() const
{
	return []( r2cm::MenuProcessor* ret )
	{
		ret->AddItem( '1', test_empty::Basic() );
		ret->AddItem( '2', test_empty::Basic() );
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



		ret->AddItem( 'q', test_key::Basic() );
		ret->AddItem( 'w', test_color_modifier::Basic() );



		ret->AddLineFeed();



		ret->AddMenu( 'a', InspectorMenu() );



		ret->AddLineFeed();



		ret->AddItem( 'z', test_base::TestEndAction_None() );
		ret->AddItem( 'x', test_base::TestEndAction_Pause() );
		ret->AddItem( 'c', test_base::TestEndAction_Exit() );



		ret->AddLineFeed();



		ret->AddItem( 'b', test_window_utility::MoveCursorWithClearBuffer() );
		ret->AddItem( 'n', test_window_utility::FillColor() );



		ret->AddSplit();



		ret->AddExit( 27 );
	};
}