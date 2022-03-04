#include "pch.h"
#include "base_test.h"

#include <conio.h> // _getch

#include "base/r2_eTestEndAction.h"

namespace base_test
{
	r2::iItem::TitleFunc TestEndAction_None::GetTitleFunction() const
	{
		return []()->const char*
		{
			return "Base : TestEndAction_None";
		};
	}
	r2::iItem::DoFunc TestEndAction_None::GetDoFunction()
	{
		return []()->r2::eTestEndAction
		{
			std::cout << "# " << GetInstance().GetTitleFunction()( ) << " #" << r2::linefeed2;

			std::cout << r2::split;

			std::cout << r2::tab2 << "Press [ESC] Key" << r2::linefeed;

			do
			{
			} while( 27 != _getch() );

			std::cout << r2::split;

			return r2::eTestEndAction::None;
		};
	}



	r2::iItem::TitleFunc TestEndAction_Pause::GetTitleFunction() const
	{
		return []()->const char*
		{
			return "Base : TestEndAction_Pause";
		};
	}
	r2::iItem::DoFunc TestEndAction_Pause::GetDoFunction()
	{
		return []()->r2::eTestEndAction
		{
			std::cout << "# " << GetInstance().GetTitleFunction()( ) << " #" << r2::linefeed2;

			std::cout << r2::split;

			std::cout << r2::tab2 << "Press [ESC] Key" << r2::linefeed;

			do
			{
			} while( 27 != _getch() );

			std::cout << r2::split;

			return r2::eTestEndAction::Pause;
		};
	}



	r2::iItem::TitleFunc TestEndAction_Exit::GetTitleFunction() const
	{
		return []()->const char*
		{
			return "Base : TestEndAction_Exit";
		};
	}
	r2::iItem::DoFunc TestEndAction_Exit::GetDoFunction()
	{
		return []()->r2::eTestEndAction
		{
			std::cout << "# " << GetInstance().GetTitleFunction()( ) << " #" << r2::linefeed2;

			std::cout << r2::split;

			std::cout << r2::tab2 << "Press [ESC] Key" << r2::linefeed;

			do
			{
			} while( 27 != _getch() );

			std::cout << r2::split;

			return r2::eTestEndAction::Exit;
		};
	}
}