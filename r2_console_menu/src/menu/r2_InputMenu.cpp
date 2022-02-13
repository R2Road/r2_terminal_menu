#include "pch.h"
#include "r2_InputMenu.h"

#include "base/r2_Director.h"
#include "base/r2_eTestEndAction.h"

#include "RootMenu.h"

#include "test/window_input_test.h"

namespace r2
{
	MenuUp InputMenu::Create( Director& director )
	{
		MenuUp ret( new ( std::nothrow ) Menu(
			director
			, GetTitle()
		) );

		{
			ret->AddChild( '1', window_input_test::TestKeyboardInputCollector::GetInstance() );


			ret->AddSplit();


			ret->AddChild(
				27
				, []()->const char* { return "Return To Root"; }
				, [&director]()->eTestEndAction
				{
					director.Setup( RootMenu::Create( director ) );
					return eTestEndAction::None;
				}
			);
		}

		return ret;
	}
}