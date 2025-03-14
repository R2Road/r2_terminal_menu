#include "test_base.h"

#include <conio.h> // _getch

#include "r2tm/r2tm_ostream.h"

namespace test_base
{
	r2tm::TitleFunctionT eDoLeaveAction_None::GetTitleFunction() const
	{
		return []()->const char*
		{
			return "Base : eDoLeaveAction_None";
		};
	}
	r2tm::DoFunctionT eDoLeaveAction_None::GetDoFunction() const
	{
		return []()->r2tm::eDoLeaveAction
		{
			LS();

			std::cout << r2tm::tab2 << "Press [ESC] Key" << r2tm::linefeed;

			do
			{
			} while( 27 != _getch() );

			LS();

			return r2tm::eDoLeaveAction::None;
		};
	}



	r2tm::TitleFunctionT eDoLeaveAction_Pause::GetTitleFunction() const
	{
		return []()->const char*
		{
			return "Base : eDoLeaveAction_Pause";
		};
	}
	r2tm::DoFunctionT eDoLeaveAction_Pause::GetDoFunction() const
	{
		return []()->r2tm::eDoLeaveAction
		{
			LS();

			std::cout << r2tm::tab2 << "Press [ESC] Key" << r2tm::linefeed;

			do
			{
			} while( 27 != _getch() );

			LS();

			return r2tm::eDoLeaveAction::Pause;
		};
	}



	r2tm::TitleFunctionT eDoLeaveAction_Exit::GetTitleFunction() const
	{
		return []()->const char*
		{
			return "Base : eDoLeaveAction_Exit";
		};
	}
	r2tm::DoFunctionT eDoLeaveAction_Exit::GetDoFunction() const
	{
		return []()->r2tm::eDoLeaveAction
		{
			LS();

			std::cout << r2tm::tab2 << "Press [ESC] Key" << r2tm::linefeed;

			do
			{
			} while( 27 != _getch() );

			LS();

			return r2tm::eDoLeaveAction::Exit;
		};
	}
}