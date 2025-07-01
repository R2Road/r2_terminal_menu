#include "test_inspector_input.h"

#include <conio.h>

#include "r2tm/r2tm_Inspector.h"
#include "r2tm/r2tm_ostream.h"

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
}