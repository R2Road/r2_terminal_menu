#include "Menu_WindowUtility.h"

#include "r2tm/r2tm_MenuProcessor.h"

#include "test_window_utility_base.h"
#include "test_window_utility_cursor_buffer.h"
#include "test_window_utility_fill.h"

#include "RootMenu.h"

r2tm::TitleFunctionT Menu_WindowUtility::GetTitleFunction() const
{
	return []()->const char*
	{
		return "Menu : Window Utility";
	};
}
r2tm::DescriptionFunctionT Menu_WindowUtility::GetDescriptionFunction() const
{
	return []()->const char*
	{
		return "";
	};
}
r2tm::WriteFunctionT Menu_WindowUtility::GetWriteFunction() const
{
	return []( r2tm::MenuProcessor* mp )
	{
		mp->AddItem( '1', test_window_utility_base::CursorPointOperator() );

		mp->AddLineFeed();

		mp->AddItem( 'q', test_window_utility_cursor_buffer::MoveCursorWithClearBuffer() );

		mp->AddLineFeed();

		mp->AddItem( 'a', test_window_utility_fill::FillColor() );
		mp->AddItem( 's', test_window_utility_fill::FillCharacter() );
		mp->AddItem( 'd', test_window_utility_fill::FillString_1() );
		mp->AddItem( 'f', test_window_utility_fill::FillString_2() );



		mp->AddSplit();



		mp->AddMenu( 27, RootMenu() );
	};
}