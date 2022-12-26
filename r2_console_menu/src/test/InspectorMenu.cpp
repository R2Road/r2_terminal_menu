#include "InspectorMenu.h"

#include "r2cm/r2cm_Director.h"
#include "r2cm/r2cm_ostream.h"

#include "item/inspector_binary_test.h"
#include "item/inspector_file_test.h"
#include "item/inspector_test.h"

#include "RootMenu.h"

r2cm::TitleFunctionT InspectorMenu::GetTitleFunction() const
{
	return []()->const char*
	{
		return "Inspector Menu";
	};
}
r2cm::DescriptionFunctionT InspectorMenu::GetDescriptionFunction() const
{
	return []()->const char*
	{
		return "";
	};
}
r2cm::WriteFunctionT InspectorMenu::GetWriteFunction() const
{
	return []( r2cm::Menu* ret )
	{
		ret->AddItem( '1', inspector_test::Basic() );
		ret->AddItem( '2', inspector_test::Expect() );
		ret->AddItem( '3', inspector_test::Code() );
		ret->AddItem( '4', inspector_test::Note() );



		ret->AddLineFeed();



		ret->AddItem( 'q', inspector_binary_test::Binary() );
		ret->AddItem( 'w', inspector_binary_test::Binaries() );



		ret->AddLineFeed();



		ret->AddItem( 'a', inspector_file_test::File() );
		ret->AddItem( 's', inspector_file_test::FileRange() );



		ret->AddSplit();



		ret->AddMenu( 27, RootMenu() );
	};
}