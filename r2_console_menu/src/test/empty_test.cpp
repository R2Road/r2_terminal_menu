#include "pch.h"
#include "empty_test.h"

#include <conio.h> // _getch

#include "base/r2_eTestEndAction.h"

namespace empty_test
{
	r2::iItem::TitleFunc Basic::GetTitleFunction() const
	{
		return []()->const char*
		{
			return "Empty Test";
		};
	}
	r2::iItem::DoFunc Basic::GetDoFunction()
	{
		return []()->r2::eTestEndAction
		{
			std::cout << "# " << GetInstance().GetTitleFunction()( ) << " #" << r2::linefeed2;

			std::cout << r2::tab2 << "Do Something" << r2::linefeed;

			return r2::eTestEndAction::Pause;
		};
	}
}