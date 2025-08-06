#include "menu_test.hpp"

#include "r2tm/r2tm_MenuProcessor.h"

#include "menu_root.hpp"

#include "test_empty.hpp"

r2tm::TitleFunctionT Menu_Test::GetTitleFunction() const
{
	return []()->const char*
	{
		return "Menu : Test";
	};
}
r2tm::DescriptionFunctionT Menu_Test::GetDescriptionFunction() const
{
	return []()->const char*
	{
		return "";
	};
}
r2tm::WriteFunctionT Menu_Test::GetWriteFunction() const
{
	return []( r2tm::MenuProcessor* mp )
	{
		mp->AddItem( '1', test_empty::Basic() );
		mp->AddItem( '2', test_empty::Basic() );



		mp->AddSplit();



		mp->AddMenu( 27, Menu_Root() );
	};
}