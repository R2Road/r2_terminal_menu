#include "Menu_ColorModifier.h"

#include "r2tm/r2tm_MenuProcessor.h"

#include "RootMenu.h"

#include "test_color_modifier.h"

r2tm::TitleFunctionT Menu_ColorModifier::GetTitleFunction() const
{
	return []()->const char*
	{
		return "Menu : ColorModifier";
	};
}
r2tm::DescriptionFunctionT Menu_ColorModifier::GetDescriptionFunction() const
{
	return []()->const char*
	{
		return "";
	};
}
r2tm::WriteFunctionT Menu_ColorModifier::GetWriteFunction() const
{
	return []( r2tm::MenuProcessor* ret )
	{
		ret->AddItem( '1', test_color_modifier::Declaration() );
		ret->AddItem( '2', test_color_modifier::Test() );



		ret->AddSplit();



		ret->AddMenu( 27, RootMenu() );
	};
}