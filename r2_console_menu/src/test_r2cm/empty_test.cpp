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
	r2cm::iItem::DoFunctionT Basic::GetDoFunction()
	{
		return []()->r2cm::eItemLeaveAction
		{
			std::cout << "# " << GetInstance().GetTitleFunction()( ) << " #" << r2cm::linefeed2;

			std::cout << r2cm::tab2 << "Do Something" << r2cm::linefeed;

			return r2cm::eItemLeaveAction::Pause;
		};
	}
}