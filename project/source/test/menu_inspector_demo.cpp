#include "menu_inspector_demo.hpp"

#include "r2tm/r2tm_menu_processor.hpp"

#include "test_inspector_demo.hpp"

#include "menu_dev.hpp"

r2tm::TitleFunctionT Menu_Inspector_Demo::GetTitleFunction() const
{
	return []()->const char*
	{
		return "Demo";
	};
}
r2tm::DescriptionFunctionT Menu_Inspector_Demo::GetDescriptionFunction() const
{
	return []()->const char*
	{
		return "";
	};
}
r2tm::WriteFunctionT Menu_Inspector_Demo::GetWriteFunction() const
{
	return []( r2tm::MenuProcessor* mp )
	{
		mp->AddItem( '1', test_inspector_demo::Demo_1() );
		mp->AddItem( '2', test_inspector_demo::Demo_2() );



		mp->AddSplit();



		mp->AddMenu( 27, Menu_Dev() );
	};
}