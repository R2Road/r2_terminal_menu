#include "InspectorMenu.h"

#include "r2cm/r2cm_Director.h"
#include "r2cm/r2cm_ostream.h"

#include "item/inspector_binary_test.h"
#include "item/inspector_file_test.h"
#include "item/inspector_test.h"

#include "RootMenu.h"

r2cm::MenuUp InspectorMenu::Create( r2cm::Director& director )
{
	r2cm::MenuUp ret( new ( std::nothrow ) r2cm::Menu(
		director
		, GetTitle()
	) );

	{
		ret->AddItem( '1', inspector_test::Basic::GetInstance() );
		ret->AddItem( '2', inspector_test::Value::GetInstance() );
		ret->AddItem( '3', inspector_test::Note::GetInstance() );



		ret->AddLineFeed();



		ret->AddItem( 'q', inspector_binary_test::Binary::GetInstance() );
		ret->AddItem( 'w', inspector_binary_test::Binaries::GetInstance() );



		ret->AddLineFeed();



		ret->AddItem( 'a', inspector_file_test::File::GetInstance() );



		ret->AddSplit();



		ret->AddMenu<RootMenu>( 27 );
	}

	return ret;
}