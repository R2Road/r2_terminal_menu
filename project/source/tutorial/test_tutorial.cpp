#include "test_tutorial.hpp"

#include "r2tm/r2tm_inspector.hpp"
#include "r2tm/r2tm_ostream.hpp"

namespace test_tutorial
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

			OUT_SUBJECT( "아래 파일 참조." );

			LF();

			OUT_STRING( "   > " __FILE__ );

			LS();

			return r2tm::eDoLeaveAction::Pause;
		};
	}
}