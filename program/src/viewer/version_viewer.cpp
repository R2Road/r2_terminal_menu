#include "version_viewer.hpp"

#include "r2tm/r2tm_inspector.hpp"
#include "r2tm/r2tm_ostream.hpp"
#include "r2tm/r2tm_WindowsUtility.h"

#include "r2tm/r2tm_VersionInfo.h"

namespace version_viewer
{
	r2tm::TitleFunctionT Viewer::GetTitleFunction() const
	{
		return []()->const char*
		{
			return "Version View";
		};
	}
	r2tm::DoFunctionT Viewer::GetDoFunction() const
	{
		return []()->r2tm::eDoLeaveAction
		{
			LS();

			OUTPUT_SUBJECT( "[Q] Version Up" );
			OUTPUT_SUBJECT( "[E] Version Down" );
			OUTPUT_SUBJECT( "[ESC] Exit" );

			LS();

			{
				const auto pivot_cursor = r2tm::WindowsUtility::GetCursorPoint();

				int i = r2tm::VersionInfo.VERSION_HISTORY_COUNT - 1;
				int key = 0;

				do
				{
					r2tm::WindowsUtility::MoveCursorPointWithClearBuffer( pivot_cursor );

					OUTPUT_STRING( r2tm::VersionInfo.VersionHistory[i] );

					LS();

					key = GET_KEY;

					switch( key )
					{
					case 'q':
						++i;
						i = ( r2tm::VersionInfo.VERSION_HISTORY_COUNT > i ? i : r2tm::VersionInfo.VERSION_HISTORY_COUNT - 1 );
						break;
					case 'e':
						--i;
						i = ( 0 <= i ? i : 0 );
						break;
					}

				} while( 27 != key );
			}

			return r2tm::eDoLeaveAction::None;
		};
	}
}