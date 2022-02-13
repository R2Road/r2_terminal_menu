#include "pch.h"
#include "r2_RootMenu.h"

#include "base/r2_Director.h"
#include "base/r2_eTestEndAction.h"

#include "menu/r2_InputMenu.h"

#include "test/base_test.h"
#include "test/empty_test.h"
#include "test/inspector_test.h"
#include "test/key_test.h"

namespace r2
{
	MenuUp RootMenu::Create( Director& director )
	{
		MenuUp ret( new ( std::nothrow ) Menu(
			director
			, GetTitle(),
					"> Inprogress : BlaBla"
			"\n"	"> To do : BlaBla"
			"\n"	"> To do : BlaBla"
			"\n"	"> To do : BlaBla"
		) );

		{
			ret->AddChild( '1', empty_test::Basic::GetInstance() );
			ret->AddChild( '2', empty_test::Basic::GetInstance() );
			ret->AddChild( '3', empty_test::Basic::GetInstance() );

			ret->AddLineFeed();

			ret->AddChild( 'q', key_test::Basic::GetInstance() );
			ret->AddChild(
				'w'
				, []()->const char* { return r2::InputMenu::GetTitle(); }
				, [&director]()->eTestEndAction
				{
					director.Setup( r2::InputMenu::Create( director ) );
					return eTestEndAction::None;
				}
			);

			ret->AddLineFeed();

			ret->AddChild( 'a', inspector_test::Basic::GetInstance() );

			ret->AddLineFeed();

			ret->AddChild( 'z', base_test::TestEndAction_None::GetInstance() );
			ret->AddChild( 'x', base_test::TestEndAction_Pause::GetInstance() );
			ret->AddChild( 'c', base_test::TestEndAction_Exit::GetInstance() );


			ret->AddSplit();


			ret->AddChild(
				27
				, []()->const char* { return "Exit"; }
				, []()->eTestEndAction { return eTestEndAction::Exit; }
			);
		}

		return ret;
	}
}