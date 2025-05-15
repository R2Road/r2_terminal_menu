#include "menu_color_modifier.h"

#include "r2tm/r2tm_MenuProcessor.h"

#include "menu_root.h"

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
	return []( r2tm::MenuProcessor* mp )
	{
		mp->AddItem( '1', test_color_modifier::Declaration() );
		mp->AddItem( '2', test_color_modifier::Test() );



		mp->AddSplit();



		mp->AddMenu( 27, Menu_Root() );
	};
}