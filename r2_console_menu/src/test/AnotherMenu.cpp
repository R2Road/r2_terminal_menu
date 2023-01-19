#include "AnotherMenu.h"

#include "r2cm/r2cm_Director.h"
#include "r2cm/r2cm_ostream.h"

#include "RootMenu.h"

#include "item/test_empty.h"

r2cm::TitleFunctionT AnotherMenu::GetTitleFunction() const
{
	return []()->const char*
	{
		return "Another Menu";
	};
}
r2cm::DescriptionFunctionT AnotherMenu::GetDescriptionFunction() const
{
	return []()->const char*
	{
		return "";
	};
}
r2cm::WriteFunctionT AnotherMenu::GetWriteFunction() const
{
	return []( r2cm::MenuProcessor* ret )
	{
		ret->AddItem( '5', test_empty::Basic() );
		ret->AddItem( '6', test_empty::Basic() );



		ret->AddSplit();



		ret->AddMenu( 27, RootMenu() );
	};
}