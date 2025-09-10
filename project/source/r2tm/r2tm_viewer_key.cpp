#include "r2tm_viewer_key.hpp"

#include "r2tm_color_modifier.hpp"
#include "r2tm_inspector.hpp"
#include "r2tm_ostream.hpp"
#include "r2tm_windows_utility.hpp"

namespace r2tm_viewer
{
	r2tm::TitleFunctionT Key::GetTitleFunction() const
	{
		return []()->const char*
		{
			return "Viewer : Key";
		};
	}
	r2tm::DoFunctionT Key::GetDoFunction() const
	{
		return []()->r2tm::eDoLeaveAction
		{
			LS();

			{
				OUT_SUBJECT( "[   ESC   ] End" );
				OUT_SUBJECT( "[ Any Key ] ..." );
			}

			LS();

			{
				const auto start_point = r2tm::WindowsUtility::GetCursorPoint();
				const short line_limit = start_point.y + 25;

				r2tm::WindowsUtility::MoveCursorPoint( start_point.x, line_limit );
				LS();
				r2tm::WindowsUtility::MoveCursorPoint( start_point );

				int input = 0;
				do
				{

					input = GET_KEY;

					if( line_limit <= r2tm::WindowsUtility::GetCursorY() )
					{
						r2tm::WindowsUtility::MoveCursorPointWithClearBuffer( start_point );
					}

					std::cout << "> Key : " << clm( r2tm::eColor::FG_LightYellow ) << input << clm() << r2tm::linefeed;

				} while( 27 != input ); // ESC
			}

			return r2tm::eDoLeaveAction::Pause;
		};
	}
}