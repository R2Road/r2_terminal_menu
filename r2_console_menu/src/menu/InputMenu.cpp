#include "pch.h"
#include "InputMenu.h"

#include "base/r2_Director.h"
#include "base/r2_eTestEndAction.h"

#include "RootMenu.h"

#include "test/window_input_test.h"

r2::MenuUp InputMenu::Create( r2::Director& director )
{
	r2::MenuUp ret( new ( std::nothrow ) r2::Menu(
		director
		, GetTitle()
	) );

	{
		ret->AddChild( '1', window_input_test::TestKeyboardInputCollector::GetInstance() );


		ret->AddSplit();


		ret->AddChild(
			27
			, []()->const char* { return "Return To Root"; }
			, [&director]()->r2::eTestEndAction
			{
				director.Setup( RootMenu::Create( director ) );
				return r2::eTestEndAction::None;
			}
		);
	}

	return ret;
}