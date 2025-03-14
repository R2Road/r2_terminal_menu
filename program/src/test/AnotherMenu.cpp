#include "AnotherMenu.h"

#include "r2tm/r2tm_Director.h"
#include "r2tm/r2tm_ostream.h"

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
		ret->AddItem( '5', test_empty::Basic() );
		ret->AddItem( '6', test_empty::Basic() );



		ret->AddSplit();



		ret->AddMenu( 27, RootMenu() );
	};
}