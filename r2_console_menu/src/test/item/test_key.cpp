#include "test_key.h"

#include <conio.h> // _getch

#include "r2cm/r2cm_ostream.h"

namespace test_key
{
	r2cm::TitleFunctionT View::GetTitleFunction() const
	{
		return []()->const char*
		{
			return "Key View";
		};
	}
	r2cm::DoFunctionT View::GetDoFunction() const
	{
		return []()->r2cm::eDoLeaveAction
		{
			LS(); 
			
			std::cout << "[ESC] End" << r2cm::linefeed;
			std::cout << "[Any Key] ..." << r2cm::linefeed;

			LS();

			bool process = true;
			int input = 0;
			do
			{
				input = _getch();

				std::cout << "Key : " << input << r2cm::linefeed;

				process = ( 27 != input ); // ESC
			} while( process );

			LS();

			return r2cm::eDoLeaveAction::Pause;
		};
	}
}