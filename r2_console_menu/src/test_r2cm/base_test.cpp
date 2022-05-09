#include "pch.h"
#include "base_test.h"

#include <conio.h> // _getch

#include "r2cm/r2cm_constant.h"

namespace base_test
{
	r2cm::iItem::TitleFuncT TestEndAction_None::GetTitleFunction() const
	{
		return []()->const char*
		{
			return "Base : TestEndAction_None";
		};
	}
	r2cm::iItem::DoFuncT TestEndAction_None::GetDoFunction()
	{
		return []()->r2cm::eTestEndAction
		{
			std::cout << "# " << GetInstance().GetTitleFunction()( ) << " #" << r2::linefeed2;

			std::cout << r2::split;

			std::cout << r2::tab2 << "Press [ESC] Key" << r2::linefeed;

			do
			{
			} while( 27 != _getch() );

			std::cout << r2::split;

			return r2cm::eTestEndAction::None;
		};
	}



	r2cm::iItem::TitleFuncT TestEndAction_Pause::GetTitleFunction() const
	{
		return []()->const char*
		{
			return "Base : TestEndAction_Pause";
		};
	}
	r2cm::iItem::DoFuncT TestEndAction_Pause::GetDoFunction()
	{
		return []()->r2cm::eTestEndAction
		{
			std::cout << "# " << GetInstance().GetTitleFunction()( ) << " #" << r2::linefeed2;

			std::cout << r2::split;

			std::cout << r2::tab2 << "Press [ESC] Key" << r2::linefeed;

			do
			{
			} while( 27 != _getch() );

			std::cout << r2::split;

			return r2cm::eTestEndAction::Pause;
		};
	}



	r2cm::iItem::TitleFuncT TestEndAction_Exit::GetTitleFunction() const
	{
		return []()->const char*
		{
			return "Base : TestEndAction_Exit";
		};
	}
	r2cm::iItem::DoFuncT TestEndAction_Exit::GetDoFunction()
	{
		return []()->r2cm::eTestEndAction
		{
			std::cout << "# " << GetInstance().GetTitleFunction()( ) << " #" << r2::linefeed2;

			std::cout << r2::split;

			std::cout << r2::tab2 << "Press [ESC] Key" << r2::linefeed;

			do
			{
			} while( 27 != _getch() );

			std::cout << r2::split;

			return r2cm::eTestEndAction::Exit;
		};
	}
}