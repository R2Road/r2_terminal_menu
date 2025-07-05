#include "test_inspector_input.h"

#include <chrono>

#include "r2tm/r2tm_Inspector.h"
#include "r2tm/r2tm_ostream.h"
#include "r2tm/r2tm_WindowsUtility.h"

namespace test_inspector_input
{
	r2tm::TitleFunctionT Wait_Any_Key::GetTitleFunction() const
	{
		return []()->const char*
		{
			return "Input : Wait Any Key";
		};
	}
	r2tm::DoFunctionT Wait_Any_Key::GetDoFunction() const
	{
		return []()->r2tm::eDoLeaveAction
		{
			LS();

			{
				OUTPUT_SUBJECT( "아무 키나 누르시오." );

				WAIT_ANY_KEY;
			}

			LS();

			return r2tm::eDoLeaveAction::Pause;
		};
	}



	r2tm::TitleFunctionT GetKey::GetTitleFunction() const
	{
		return []()->const char*
		{
			return "Input : GET_KEY";
		};
	}
	r2tm::DoFunctionT GetKey::GetDoFunction() const
	{
		return []()->r2tm::eDoLeaveAction
		{
			LS();

			{
				OUTPUT_SUBJECT( "아무 키나 누르시오." );

				LF();

				OUTPUT_VALUE( GET_KEY );
			}

			LS();

			return r2tm::eDoLeaveAction::Pause;
		};
	}



	r2tm::TitleFunctionT Keyboard_Hit::GetTitleFunction() const
	{
		return []()->const char*
		{
			return "Input : KB_HIT";
		};
	}
	r2tm::DoFunctionT Keyboard_Hit::GetDoFunction() const
	{
		return []()->r2tm::eDoLeaveAction
		{
			LS();

			{
				OUTPUT_SUBJECT( "아무 키나 누르시오." );

				SS();

				const auto pivot = r2tm::WindowsUtility::GetCursorPoint();

				const int fps = 30;
				const int spf = 1000 / fps;
				auto last_time = std::chrono::high_resolution_clock::now();
				auto current_time = last_time;

				int frame_count = 0;
				do
				{
					current_time = std::chrono::high_resolution_clock::now();

					if( spf < std::chrono::duration_cast<std::chrono::milliseconds>( current_time - last_time ).count() )
					{
						last_time = current_time;
						++frame_count;

						if( 0 == ( frame_count % 5 ) )
						{
							OUTPUT_STRING( "." );
						}

						if( fps == frame_count )
						{
							frame_count = 0;
							r2tm::WindowsUtility::MoveCursorPointWithClearBuffer( pivot );
						}
					}

				} while( !KB_HIT );
			}

			LS();

			return r2tm::eDoLeaveAction::Pause;
		};
	}
}