#include "test_inspector_input.hpp"

#include <chrono>

#include "r2tm/r2tm_inspector.hpp"
#include "r2tm/r2tm_ostream.hpp"
#include "r2tm/r2tm_windows_utility.hpp"

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



	r2tm::TitleFunctionT ClearInput::GetTitleFunction() const
	{
		return []()->const char*
		{
			return "Input : CLEAR_INPUT";
		};
	}
	r2tm::DoFunctionT ClearInput::GetDoFunction() const
	{
		return []()->r2tm::eDoLeaveAction
		{
			LS();

			OUTPUT_SUBJECT( "_kbhit 로 테스트를 끝내는 경우" );
			OUTPUT_SUBJECT( "_getch 를 사용해 input buffer 를 비워주지 않으면" );
			OUTPUT_SUBJECT( "menu에 돌아갔을 때 키가 작동 해버린다." );

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

					if( spf < std::chrono::duration_cast< std::chrono::milliseconds >( current_time - last_time ).count() )
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

			CLEAR_INPUT;

			LS();

			return r2tm::eDoLeaveAction::None;
		};
	}
}