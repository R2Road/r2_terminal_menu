#include "pch.h"
#include "base_test.h"

#include <conio.h> // _getch

#include "base/r2_eTestResult.h"

namespace base_test
{
	r2::iTest::TitleFunc Pause::GetTitleFunction() const
	{
		return []()->const char*
		{
			return "Base : Pause";
		};
	}
	r2::iTest::DoFunc Pause::GetDoFunction()
	{
		return []()->r2::eTestEndAction
		{
			std::cout << "# " << GetInstance().GetTitleFunction()( ) << " #" << r2::linefeed2;
			std::cout << "[ESC] End" << r2::linefeed;

			std::cout << r2::split;

			do
			{
			} while( 27 != _getch() );

			std::cout << r2::split;

			return r2::eTestEndAction::Pause;
		};
	}



	r2::iTest::TitleFunc None::GetTitleFunction() const
	{
		return []()->const char*
		{
			return "Base : None";
		};
	}
	r2::iTest::DoFunc None::GetDoFunction()
	{
		return []()->r2::eTestEndAction
		{
			std::cout << "# " << GetInstance().GetTitleFunction()() << " #" << r2::linefeed2;
			std::cout << "[ESC] End" << r2::linefeed;

			std::cout << r2::split;

			do
			{
			} while( 27 != _getch() );

			std::cout << r2::split;

			return r2::eTestEndAction::None;
		};
	}
}