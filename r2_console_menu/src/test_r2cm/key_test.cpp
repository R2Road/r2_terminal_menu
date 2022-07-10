#include "key_test.h"

#include <conio.h> // _getch

#include "r2cm/r2cm_ostream.h"

namespace key_test
{
	r2cm::iItem::TitleFunctionT Basic::GetTitleFunction() const
	{
		return []()->const char*
		{
			return "Key : Basic";
		};
	}
	r2cm::iItem::DoFunctionT Basic::GetDoFunction()
	{
		return []()->r2cm::eItemLeaveAction
		{
			std::cout << "# " << GetInstance().GetTitleFunction()() << " #" << r2cm::linefeed2;
			std::cout << "[ESC] End" << r2cm::linefeed;
			std::cout << "[Any Key] ..." << r2cm::linefeed;

			std::cout << r2cm::split;

			bool process = true;
			int input = 0;
			do
			{
				input = _getch();

				std::cout << "Key : " << input << r2cm::linefeed;

				process = ( 27 != input ); // ESC
			} while( process );

			std::cout << r2cm::split;

			return r2cm::eItemLeaveAction::Pause;
		};
	}
}