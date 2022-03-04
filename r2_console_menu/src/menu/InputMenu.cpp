#include "pch.h"
#include "InputMenu.h"

#include "base/r2_Director.h"
#include "base/r2_eTestEndAction.h"

#include "RootMenu.h"

#include "test/window_input_test.h"

r2cm::MenuUp InputMenu::Create( r2cm::Director& director )
{
	r2cm::MenuUp ret( new ( std::nothrow ) r2cm::Menu(
		director
		, GetTitle()
	) );

	{
		ret->AddItem( '1', window_input_test::TestKeyboardInputCollector::GetInstance() );


		ret->AddSplit();


		ret->AddItem(
			27
			, []()->const char* { return "Return To Root"; }
			, [&director]()->r2cm::eTestEndAction
			{
				director.Setup( RootMenu::Create( director ) );
				return r2cm::eTestEndAction::None;
			}
		);
	}

	return ret;
}