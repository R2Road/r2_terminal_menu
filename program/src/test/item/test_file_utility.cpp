#include "test_file_utility.h"

#include <conio.h> // _kbhit(), _getch()

#include "r2tm/r2tm_Inspector.h"
#include "r2tm/r2tm_ostream.h"
#include "r2tm/r2tm_FileUtility.h"

namespace test_file_utility
{
	r2tm::TitleFunctionT Open::GetTitleFunction() const
	{
		return []()->const char*
		{
			return "File Utility : Open";
		};
	}
	r2tm::DoFunctionT Open::GetDoFunction() const
	{
		return []()->r2tm::eDoLeaveAction
		{
			LS();

			std::cout << "[Any Key] Move Cursor with Clear Buffer";
			_getch();

			PROCESS_MAIN( r2tm::FileUtility::DirectoryOpen( "" ) );

			std::cout << "[Any Key] End";
			_getch();

			return r2tm::eDoLeaveAction::None;
		};
	}
}