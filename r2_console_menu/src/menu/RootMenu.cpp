#include "pch.h"
#include "RootMenu.h"

#include "base/r2cm_Director.h"
#include "base/r2cm_eTestEndAction.h"

#include "menu/InputMenu.h"

#include "test/base_test.h"
#include "test/empty_test.h"
#include "test/inspector_test.h"
#include "test/key_test.h"

r2cm::MenuUp RootMenu::Create( r2cm::Director& director )
{
	r2cm::MenuUp ret( new ( std::nothrow ) r2cm::Menu(
		director
		, GetTitle(),
				"> Inprogress : BlaBla"
		"\n"	"> To do : BlaBla"
		"\n"	"> To do : BlaBla"
		"\n"	"> To do : BlaBla"
	) );

	{
		ret->AddItem( '1', empty_test::Basic::GetInstance() );
		ret->AddItem( '2', empty_test::Basic::GetInstance() );
		ret->AddItem( '3', empty_test::Basic::GetInstance() );

		ret->AddLineFeed();

		ret->AddItem( 'q', key_test::Basic::GetInstance() );
		ret->AddItem(
			'w'
			, []()->const char* { return InputMenu::GetTitle(); }
			, [&director]()->r2cm::eTestEndAction
			{
				director.Setup( InputMenu::Create( director ) );
				return r2cm::eTestEndAction::None;
			}
		);

		ret->AddLineFeed();

		ret->AddItem( 'a', inspector_test::Basic::GetInstance() );

		ret->AddLineFeed();

		ret->AddItem( 'z', base_test::TestEndAction_None::GetInstance() );
		ret->AddItem( 'x', base_test::TestEndAction_Pause::GetInstance() );
		ret->AddItem( 'c', base_test::TestEndAction_Exit::GetInstance() );


		ret->AddSplit();


		ret->AddItem(
			27
			, []()->const char* { return "Exit"; }
			, []()->r2cm::eTestEndAction { return r2cm::eTestEndAction::Exit; }
		);
	}

	return ret;
}