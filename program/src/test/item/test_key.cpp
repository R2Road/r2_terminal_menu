#include "test_key.h"

#include <conio.h> // _getch

#include "r2tm/r2tm_ostream.h"

namespace test_key
{
	r2tm::TitleFunctionT View::GetTitleFunction() const
	{
		return []()->const char*
		{
			return "Key Code View";
		};
	}
	r2tm::DoFunctionT View::GetDoFunction() const
	{
		return []()->r2tm::eDoLeaveAction
		{
			LS(); 
			
			std::cout << "[ESC] End" << r2tm::linefeed;
			std::cout << "[Any Key] ..." << r2tm::linefeed;

			LS();

			bool process = true;
			int input = 0;
			do
			{
				input = _getch();

				std::cout << "Key : " << input << r2tm::linefeed;

				process = ( 27 != input ); // ESC
			} while( process );

			LS();

			return r2tm::eDoLeaveAction::Pause;
		};
	}
}