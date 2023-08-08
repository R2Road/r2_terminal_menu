#include "InspectorMenu.h"

#include "r2tm/r2tm_Director.h"
#include "r2tm/r2tm_ostream.h"

#include "item/test_inspector_base.h"
#include "item/test_inspector_binary.h"
#include "item/test_inspector_demo.h"
#include "item/test_inspector_file.h"
#include "item/test_inspector_source.h"

#include "RootMenu.h"

r2tm::TitleFunctionT InspectorMenu::GetTitleFunction() const
{
	return []()->const char*
	{
		return "Inspector Menu";
	};
}
r2tm::DescriptionFunctionT InspectorMenu::GetDescriptionFunction() const
{
	return []()->const char*
	{
		return "";
	};
}
r2tm::WriteFunctionT InspectorMenu::GetWriteFunction() const
{
	return []( r2tm::MenuProcessor* ret )
	{
		ret->AddItem( '1', test_inspector_base::Basic() );
		ret->AddItem( '2', test_inspector_base::Expect() );
		ret->AddItem( '3', test_inspector_base::Size() );
		ret->AddItem( '4', test_inspector_base::Code() );
		ret->AddItem( '5', test_inspector_base::String_Note_Subject_Comment() );



		ret->AddLineFeed();



		ret->AddItem( 'q', test_inspector_binary::Binary() );
		ret->AddItem( 'w', test_inspector_binary::Binaries() );



		ret->AddLineFeed();



		ret->AddItem( 'a', test_inspector_file::File() );
		ret->AddItem( 's', test_inspector_file::FileRange() );
		ret->AddItem( 'd', test_inspector_source::Basic() );



		ret->AddLineFeed();



		ret->AddItem( 32, test_inspector_demo::Demo() );



		ret->AddSplit();



		ret->AddMenu( 27, RootMenu() );
	};
}