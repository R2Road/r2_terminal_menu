#include "empty_test.h"

#include <conio.h> // _getch

#include "r2cm/r2cm_ostream.h"

namespace empty_test
{
	r2cm::iItem::TitleFunctionT Basic::GetTitleFunction() const
	{
		return []()->const char*
		{
			return "Empty Test";
		};
	}
	r2cm::iItem::DoFunctionT Basic::GetDoFunction() const
	{
		return []()->r2cm::eItemLeaveAction
		{
			std::cout << r2cm::split;

			std::cout << r2cm::tab2 << "Do Something" << r2cm::linefeed;

			std::cout << r2cm::split;

			return r2cm::eItemLeaveAction::Pause;
		};
	}
}