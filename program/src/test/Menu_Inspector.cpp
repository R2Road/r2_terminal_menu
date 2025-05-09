#include "Menu_Inspector.h"

#include "r2tm/r2tm_MenuProcessor.h"

#include "test_inspector_base.h"
#include "test_inspector_binary.h"
#include "test_inspector_demo.h"
#include "test_inspector_file.h"
#include "test_inspector_source.h"

#include "RootMenu.h"

r2tm::TitleFunctionT Menu_Inspector::GetTitleFunction() const
{
	return []()->const char*
	{
		return "Menu : Inspector";
	};
}
r2tm::DescriptionFunctionT Menu_Inspector::GetDescriptionFunction() const
{
	return []()->const char*
	{
		return "";
	};
}
r2tm::WriteFunctionT Menu_Inspector::GetWriteFunction() const
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
		ret->AddItem( 'w', test_inspector_binary::Binaries_1() );
		ret->AddItem( 'e', test_inspector_binary::Binaries_2() );



		ret->AddLineFeed();



		ret->AddItem( 'a', test_inspector_file::File() );
		ret->AddItem( 's', test_inspector_file::FileRange_1() );
		ret->AddItem( 'd', test_inspector_file::FileRange_2() );
		ret->AddItem( 'f', test_inspector_source::Basic() );
		ret->AddItem( 'g', test_inspector_source::Warning() );



		ret->AddLineFeed();



		ret->AddItem( 32, test_inspector_demo::Demo() );



		ret->AddSplit();



		ret->AddMenu( 27, RootMenu() );
	};
}