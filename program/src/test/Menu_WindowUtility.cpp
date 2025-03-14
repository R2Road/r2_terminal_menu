#include "Menu_WindowUtility.h"

#include "r2tm/r2tm_Director.h"
#include "r2tm/r2tm_ostream.h"

#include "test_window_utility.h"

#include "RootMenu.h"

r2tm::TitleFunctionT Menu_WindowUtility::GetTitleFunction() const
{
	return []()->const char*
	{
		return "Window Utility";
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
	return []( r2tm::MenuProcessor* ret )
	{
		ret->AddItem( '1', test_window_utility::CursorPointOperator() );

		ret->AddLineFeed();

		ret->AddItem( 'q', test_window_utility::MoveCursorWithClearBuffer() );

		ret->AddLineFeed();

		ret->AddItem( 'a', test_window_utility::FillColor() );
		ret->AddItem( 's', test_window_utility::FillCharacter() );
		ret->AddItem( 'd', test_window_utility::FillString_1() );
		ret->AddItem( 'f', test_window_utility::FillString_2() );



		ret->AddSplit();



		ret->AddMenu( 27, RootMenu() );
	};
}