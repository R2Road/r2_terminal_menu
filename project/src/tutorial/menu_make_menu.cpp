#include "menu_make_menu.hpp"

#include "r2tm/r2tm_menu_processor.hpp"

#include "menu_tutorial.hpp"

#include "test_empty.hpp"

r2tm::TitleFunctionT Menu_MakeMenu::GetTitleFunction() const
{
	return []()->const char*
	{
		return "Menu : Make Menu";
	};
}
r2tm::DescriptionFunctionT Menu_MakeMenu::GetDescriptionFunction() const
{
	return []()->const char*
	{
		return "";
	};
}
r2tm::WriteFunctionT Menu_MakeMenu::GetWriteFunction() const
{
	return []( r2tm::MenuProcessor* mp )
	{
		mp->AddItem( '1', test_empty::Basic() );
		mp->AddItem( '2', test_empty::Basic() );



		mp->AddSplit();



		mp->AddMenu( 27, Menu_Tutorial() );
	};
}