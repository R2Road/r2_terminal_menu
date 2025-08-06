#include "test_empty.hpp"

#include "r2tm/r2tm_ostream.h"

namespace test_empty
{
	r2tm::TitleFunctionT Basic::GetTitleFunction() const
	{
		return []()->const char*
		{
			return "Empty Test";
		};
	}
	r2tm::DoFunctionT Basic::GetDoFunction() const
	{
		return []()->r2tm::eDoLeaveAction
		{
			LS();

			std::cout << r2tm::tab2 << "Do Something" << r2tm::linefeed;

			LS();

			return r2tm::eDoLeaveAction::Pause;
		};
	}
}