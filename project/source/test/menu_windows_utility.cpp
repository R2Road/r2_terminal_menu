#include "menu_windows_utility.hpp"

#include "r2tm/r2tm_menu_processor.hpp"

#include "test_windows_utility_base.hpp"
#include "test_windows_utility_cursor_buffer.hpp"
#include "test_windows_utility_fill.hpp"

#include "menu_dev.hpp"

r2tm::eStatus Menu_WindowsUtility::GetStatus() const
{
	return r2tm::eStatus::Complete;
}
r2tm::TitleFunctionT Menu_WindowsUtility::GetTitleFunction() const
{
	return []()->const char*
	{
		return "Menu : Windows Utility";
	};
}
r2tm::DescriptionFunctionT Menu_WindowsUtility::GetDescriptionFunction() const
{
	return []()->const char*
	{
		return "";
	};
}
r2tm::WriteFunctionT Menu_WindowsUtility::GetWriteFunction() const
{
	return []( r2tm::MenuProcessor* mp )
	{
		mp->AddItem( '1', test_windows_utility_base::CursorPointDeclaration() );
		mp->AddItem( '2', test_windows_utility_base::CursorPointOperator() );

		mp->AddLineFeed();

		mp->AddItem( 'q', test_windows_utility_cursor_buffer::MoveCursorWithClearBuffer() );

		mp->AddLineFeed();

		mp->AddItem( 'a', test_windows_utility_fill::FillColor() );
		mp->AddItem( 's', test_windows_utility_fill::FillCharacter() );
		mp->AddItem( 'd', test_windows_utility_fill::FillString_1() );
		mp->AddItem( 'f', test_windows_utility_fill::FillString_2() );



		mp->AddSplit();



		mp->AddMenu( 27, Menu_Dev() );
	};
}