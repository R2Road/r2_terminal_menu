#include "pch.h"
#include "RootMenu.h"

#include "base/r2_Director.h"
#include "base/r2_eTestEndAction.h"

#include "menu/InputMenu.h"

#include "test/base_test.h"
#include "test/empty_test.h"
#include "test/inspector_test.h"
#include "test/key_test.h"

r2::MenuUp RootMenu::Create( r2::Director& director )
{
	r2::MenuUp ret( new ( std::nothrow ) r2::Menu(
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
			, []()->const char* { return InputMenu::GetTitle(); }
			, [&director]()->r2::eTestEndAction
			{
				director.Setup( InputMenu::Create( director ) );
				return r2::eTestEndAction::None;
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
			, []()->r2::eTestEndAction { return r2::eTestEndAction::Exit; }
		);
	}

	return ret;
}