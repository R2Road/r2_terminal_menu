#include "pch.h"
#include "key_test.h"

#include <conio.h> // _getch

#include "base/r2_eTestResult.h"

namespace key_test
{
	r2::iTest::TitleFunc Basic::GetTitleFunction() const
	{
		return []()->const char*
		{
			return "Key : Basic";
		};
	}
	r2::iTest::DoFunc Basic::GetDoFunction()
	{
		return []()->r2::eTestEndAction
		{
			std::cout << "# " << GetInstance().GetTitleFunction()() << " #" << r2::linefeed2;
			std::cout << "[ESC] End" << r2::linefeed;
			std::cout << "[Any Key] ..." << r2::linefeed;

			std::cout << r2::split;

			bool process = true;
			int input = 0;
			do
			{
				input = _getch();

				std::cout << "Key : " << input << r2::linefeed;

				process = ( 27 != input ); // ESC
			} while( process );

			std::cout << r2::split;

			return r2::eTestEndAction::Pause;
		};
	}
}