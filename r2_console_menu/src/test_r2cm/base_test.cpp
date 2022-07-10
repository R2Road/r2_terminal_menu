#include "base_test.h"

#include <conio.h> // _getch

#include "r2cm/r2cm_ostream.h"

namespace base_test
{
	r2cm::iItem::TitleFunctionT TestEndAction_None::GetTitleFunction() const
	{
		return []()->const char*
		{
			return "Base : TestEndAction_None";
		};
	}
	r2cm::iItem::DoFunctionT TestEndAction_None::GetDoFunction()
	{
		return []()->r2cm::eItemLeaveAction
		{
			std::cout << "# " << GetInstance().GetTitleFunction()( ) << " #" << r2cm::linefeed2;

			std::cout << r2cm::split;

			std::cout << r2cm::tab2 << "Press [ESC] Key" << r2cm::linefeed;

			do
			{
			} while( 27 != _getch() );

			std::cout << r2cm::split;

			return r2cm::eItemLeaveAction::None;
		};
	}



	r2cm::iItem::TitleFunctionT TestEndAction_Pause::GetTitleFunction() const
	{
		return []()->const char*
		{
			return "Base : TestEndAction_Pause";
		};
	}
	r2cm::iItem::DoFunctionT TestEndAction_Pause::GetDoFunction()
	{
		return []()->r2cm::eItemLeaveAction
		{
			std::cout << "# " << GetInstance().GetTitleFunction()( ) << " #" << r2cm::linefeed2;

			std::cout << r2cm::split;

			std::cout << r2cm::tab2 << "Press [ESC] Key" << r2cm::linefeed;

			do
			{
			} while( 27 != _getch() );

			std::cout << r2cm::split;

			return r2cm::eItemLeaveAction::Pause;
		};
	}



	r2cm::iItem::TitleFunctionT TestEndAction_Exit::GetTitleFunction() const
	{
		return []()->const char*
		{
			return "Base : TestEndAction_Exit";
		};
	}
	r2cm::iItem::DoFunctionT TestEndAction_Exit::GetDoFunction()
	{
		return []()->r2cm::eItemLeaveAction
		{
			std::cout << "# " << GetInstance().GetTitleFunction()( ) << " #" << r2cm::linefeed2;

			std::cout << r2cm::split;

			std::cout << r2cm::tab2 << "Press [ESC] Key" << r2cm::linefeed;

			do
			{
			} while( 27 != _getch() );

			std::cout << r2cm::split;

			return r2cm::eItemLeaveAction::Exit;
		};
	}
}