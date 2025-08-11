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
				OUTPUT_SUBJECT( "�ƹ� Ű�� �����ÿ�." );

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
				OUTPUT_SUBJECT( "�ƹ� Ű�� �����ÿ�." );

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
				OUTPUT_SUBJECT( "�ƹ� Ű�� �����ÿ�." );

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

			OUTPUT_SUBJECT( "_kbhit �� �׽�Ʈ�� ������ ���" );
			OUTPUT_SUBJECT( "_getch �� ����� input buffer �� ������� ������" );
			OUTPUT_SUBJECT( "menu�� ���ư��� �� Ű�� �۵� �ع�����." );

			LS();

			{
				OUTPUT_SUBJECT( "�ƹ� Ű�� �����ÿ�." );

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