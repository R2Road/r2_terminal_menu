#include "InspectorMenu.h"

#include "r2cm/r2cm_Director.h"
#include "r2cm/r2cm_ostream.h"

#include "item/test_inspector_binary.h"
#include "item/test_inspector_file.h"
#include "item/test_inspector_demo.h"
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
	return []( r2cm::MenuProcessor* ret )
	{
		ret->AddItem( '1', inspector_test::Basic() );
		ret->AddItem( '2', inspector_test::Expect() );
		ret->AddItem( '3', inspector_test::Size() );
		ret->AddItem( '4', inspector_test::Code() );
		ret->AddItem( '5', inspector_test::Note() );



		ret->AddLineFeed();



		ret->AddItem( 'q', test_inspector_binary::Binary() );
		ret->AddItem( 'w', test_inspector_binary::Binaries() );



		ret->AddLineFeed();



		ret->AddItem( 'a', test_inspector_file::File() );
		ret->AddItem( 's', test_inspector_file::FileRange() );



		ret->AddLineFeed();



		ret->AddItem( 32, test_inspector_demo::Demo() );



		ret->AddSplit();



		ret->AddMenu( 27, RootMenu() );
	};
}