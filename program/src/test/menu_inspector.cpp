#include "menu_inspector.h"

#include "r2tm/r2tm_MenuProcessor.h"

#include "test_inspector_base.h"
#include "test_inspector_binary.h"
#include "test_inspector_demo.h"
#include "test_inspector_file.h"
#include "test_inspector_input.h"
#include "test_inspector_source.h"

#include "menu_root.h"

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
	return []( r2tm::MenuProcessor* mp )
	{
		mp->AddItem( '1', test_inspector_base::Basic() );
		mp->AddItem( '2', test_inspector_base::Expect_1() );
		mp->AddItem( '3', test_inspector_base::Expect_2() );
		mp->AddItem( '4', test_inspector_base::Size() );
		mp->AddItem( '5', test_inspector_base::Code() );
		mp->AddItem( '6', test_inspector_base::Address() );
		mp->AddItem( '7', test_inspector_base::String_Note_Subject_Comment() );



		mp->AddLineFeed();



		mp->AddItem( 'q', test_inspector_binary::Binary() );
		mp->AddItem( 'w', test_inspector_binary::Binaries_1() );
		mp->AddItem( 'e', test_inspector_binary::Binaries_2() );
		mp->AddItem( 'r', test_inspector_input::Wait_Any_Key() );
		mp->AddItem( 't', test_inspector_input::GetKey() );
		mp->AddItem( 'y', test_inspector_input::Keyboard_Hit() );



		mp->AddLineFeed();



		mp->AddItem( 'a', test_inspector_file::File_1() );
		mp->AddItem( 's', test_inspector_file::File_2() );
		mp->AddItem( 'd', test_inspector_file::FileRange_1() );
		mp->AddItem( 'f', test_inspector_file::FileRange_2() );
		mp->AddItem( 'g', test_inspector_file::FileRange_3() );
		mp->AddItem( 'h', test_inspector_source::Basic() );



		mp->AddLineFeed();



		mp->AddItem( 'z', test_inspector_demo::Demo_1());
		mp->AddItem( 'x', test_inspector_demo::Demo_2());



		mp->AddSplit();



		mp->AddMenu( 27, Menu_Root() );
	};
}