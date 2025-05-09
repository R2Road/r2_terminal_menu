#include "AnotherMenu.h"

#include "r2tm/r2tm_MenuProcessor.h"

#include "RootMenu.h"

#include "test_empty.h"

r2tm::TitleFunctionT AnotherMenu::GetTitleFunction() const
{
	return []()->const char*
	{
		return "Another Menu";
	};
}
r2tm::DescriptionFunctionT AnotherMenu::GetDescriptionFunction() const
{
	return []()->const char*
	{
		return "";
	};
}
r2tm::WriteFunctionT AnotherMenu::GetWriteFunction() const
{
	return []( r2tm::MenuProcessor* ret )
	{
		ret->AddItem( '1', test_empty::Basic() );
		ret->AddItem( '2', test_empty::Basic() );



		ret->AddSplit();



		ret->AddMenu( 27, RootMenu() );
	};
}