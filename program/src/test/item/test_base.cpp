#include "test_base.h"

#include <conio.h> // _getch

#include "r2cm/r2cm_ostream.h"

namespace test_base
{
	r2tm::TitleFunctionT TestEndAction_None::GetTitleFunction() const
	{
		return []()->const char*
		{
			return "Base : TestEndAction_None";
		};
	}
	r2tm::DoFunctionT TestEndAction_None::GetDoFunction() const
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



	r2tm::TitleFunctionT TestEndAction_Pause::GetTitleFunction() const
	{
		return []()->const char*
		{
			return "Base : TestEndAction_Pause";
		};
	}
	r2tm::DoFunctionT TestEndAction_Pause::GetDoFunction() const
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



	r2tm::TitleFunctionT TestEndAction_Exit::GetTitleFunction() const
	{
		return []()->const char*
		{
			return "Base : TestEndAction_Exit";
		};
	}
	r2tm::DoFunctionT TestEndAction_Exit::GetDoFunction() const
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