#include "pch.h"
#include "base_test.h"

#include <conio.h> // _getch

#include "base/r2_eTestResult.h"

namespace base_test
{
	r2::iTest::TitleFunc RunTest_Without_Pause::GetTitleFunction() const
	{
		return []()->const char*
		{
			return "Base : RunTest_Without_Pause";
		};
	}
	r2::iTest::DoFunc RunTest_Without_Pause::GetDoFunction()
	{
		return []()->r2::eTestResult
		{
			std::cout << "# " << GetInstance().GetTitleFunction()() << " #" << r2::linefeed2;
			std::cout << "[ESC] End" << r2::linefeed;

			std::cout << r2::split;

			do
			{
			} while( 27 != _getch() );

			std::cout << r2::split;

			return r2::eTestResult::RunTest_Without_Pause;
		};
	}
}