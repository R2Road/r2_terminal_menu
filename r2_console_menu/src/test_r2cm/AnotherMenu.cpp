#include "AnotherMenu.h"

#include "r2cm/r2cm_Director.h"
#include "r2cm/r2cm_ostream.h"

#include "RootMenu.h"

#include "test_r2cm/empty_test.h"

r2cm::MenuUp AnotherMenu::Create( r2cm::Director& director )
{
	r2cm::MenuUp ret( new ( std::nothrow ) r2cm::Menu(
		director
		, GetTitle()
	) );

	{
		ret->AddItem( '1', empty_test::Basic::GetInstance() );
		ret->AddItem( '2', empty_test::Basic::GetInstance() );



		ret->AddSplit();



		ret->AddMenu<RootMenu>( 27 );
	}

	return ret;
}