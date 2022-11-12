#include "InspectorMenu.h"

#include "r2cm/r2cm_Director.h"
#include "r2cm/r2cm_ostream.h"

#include "RootMenu.h"

#include "test_r2cm/inspector_test.h"

r2cm::MenuUp InspectorMenu::Create( r2cm::Director& director )
{
	r2cm::MenuUp ret( new ( std::nothrow ) r2cm::Menu(
		director
		, GetTitle()
	) );

	{
		ret->AddItem( 'a', inspector_test::Basic::GetInstance() );
		ret->AddItem( 's', inspector_test::Value::GetInstance() );
		ret->AddItem( 'd', inspector_test::Binary::GetInstance() );
		ret->AddItem( 'f', inspector_test::Binaries::GetInstance() );
		ret->AddItem( 'g', inspector_test::ShowFile::GetInstance() );



		ret->AddSplit();



		ret->AddMenu<RootMenu>( 27 );
	}

	return ret;
}