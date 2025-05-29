#include "test_key.h"

#include <conio.h> // _getch

#include "r2tm/r2tm_ColorModifier.h"
#include "r2tm/r2tm_Inspector.h"
#include "r2tm/r2tm_ostream.h"
#include "r2tm/r2tm_WindowsUtility.h"

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
			
			{
				OUTPUT_SUBJECT( "[   ESC   ] End" );
				OUTPUT_SUBJECT( "[ Any Key ] ..." );
			}

			LS();

			{
				const auto start_point = r2tm::WindowsUtility::GetCursorPoint();
				r2tm::WindowsUtility::CursorPoint current_point;

				const short line_limit = start_point.y + 30;

				int input = 0;
				do
				{

					current_point = r2tm::WindowsUtility::GetCursorPoint();
					if( line_limit < current_point.y )
					{
						r2tm::WindowsUtility::MoveCursorPointWithClearBuffer( start_point );
					}

					std::cout << "> ";

					input = _getch();

					std::cout << "Key : " << clm( r2tm::eColor::FG_LightYellow ) << input << clm() << r2tm::linefeed;

				} while( 27 != input ); // ESC
			}

			LS();

			return r2tm::eDoLeaveAction::Pause;
		};
	}
}