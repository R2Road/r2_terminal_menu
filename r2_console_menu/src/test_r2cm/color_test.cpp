#include "color_test.h"

#include <conio.h> // _getch

#include "r2cm/r2cm_constant.h"

namespace color_test
{
	r2cm::iItem::TitleFuncT Basic::GetTitleFunction() const
	{
		return []()->const char*
		{
			return "Color Test";
		};
	}
	r2cm::iItem::DoFuncT Basic::GetDoFunction()
	{
		return []()->r2cm::eItemLeaveAction
		{
			std::cout << "# " << GetInstance().GetTitleFunction()( ) << " #" << r2cm::linefeed2;

			std::cout << r2cm::split;

			{
				std::cout << r2cm::tab2 << r2cm::ColorModifier( r2cm::eColor::FG_Red ) << "Do Something" << r2cm::ColorModifier() << r2cm::linefeed;

				std::cout << r2cm::linefeed;

				std::cout << r2cm::tab2 << r2cm::clm( r2cm::eColor::BG_Red ) << r2cm::clm( r2cm::eColor::FG_Blue ) << "Do Something" << r2cm::clm() << r2cm::linefeed;
			}

			std::cout << r2cm::split;

			return r2cm::eItemLeaveAction::Pause;
		};
	}
}