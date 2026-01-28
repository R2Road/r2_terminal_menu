#include "menu_inspector.hpp"

#include "r2tm/r2tm_menu_processor.hpp"

#include "test_inspector_address.hpp"
#include "test_inspector_base.hpp"
#include "test_inspector_binary.hpp"
#include "test_inspector_demo.hpp"
#include "test_inspector_file.hpp"
#include "test_inspector_input.hpp"
#include "test_inspector_source.hpp"

#include "menu_dev.hpp"

r2tm::eStatus Menu_Inspector::GetStatus() const
{
	return r2tm::eStatus::Complete;
}
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
		mp->AddItem( '4', test_inspector_base::Expect_Epsilon_Float() );
		mp->AddItem( '5', test_inspector_base::Expect_Epsilon_Double() );
		mp->AddItem( '6', test_inspector_base::Size() );
		mp->AddItem( '7', test_inspector_base::Align() );
		mp->AddItem( '8', test_inspector_base::Code() );
		mp->AddItem( '9', test_inspector_base::String_Note_Subject_Comment() );



		mp->AddLineFeed();



		mp->AddItem( 'q', test_inspector_address::Value() );
		mp->AddItem( 'w', test_inspector_address::Function() );
		mp->AddItem( 'e', test_inspector_address::Member_Function() );
		mp->AddItem( 'r', test_inspector_address::Convert2VoidPointer());
		mp->AddItem( 't', test_inspector_binary::Binary() );
		mp->AddItem( 'y', test_inspector_binary::Binaries_1() );
		mp->AddItem( 'u', test_inspector_binary::Binaries_2() );
		mp->AddItem( 'i', test_inspector_binary::Binaries_With_Array() );



		mp->AddLineFeed();



		mp->AddItem( 'a', test_inspector_input::Wait_Any_Key() );
		mp->AddItem( 's', test_inspector_input::GetKey() );
		mp->AddItem( 'd', test_inspector_input::Keyboard_Hit() );
		mp->AddItem( 'f', test_inspector_input::ClearInput() );



		mp->AddSplit();



		mp->AddMenu( 27, Menu_Dev() );
	};
}