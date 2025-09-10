#include "r2tm_viewer_version.hpp"

#include "r2tm_inspector.hpp"
#include "r2tm_ostream.hpp"
#include "r2tm_windows_utility.hpp"

namespace r2tm_viewer
{
	Version::Version( const char* const* version_history_string_list, const int version_history_count) :
		  mVersionHistoryStringList( version_history_string_list )
		, mVersionHistoryCount( version_history_count )
	{}

	r2tm::TitleFunctionT Version::GetTitleFunction() const
	{
		return []()->const char*
		{
			return "Viewer : Version";
		};
	}
	r2tm::DoFunctionT Version::GetDoFunction() const
	{
		return [version_history_string_list = mVersionHistoryStringList, version_history_count = mVersionHistoryCount]()->r2tm::eDoLeaveAction
		{
			LS();

			OUT_SUBJECT( "[Q] Version Up" );
			OUT_SUBJECT( "[E] Version Down" );
			OUT_SUBJECT( "[ESC] Exit" );

			LS();

			{
				const auto pivot_cursor = r2tm::WindowsUtility::GetCursorPoint();

				int i = version_history_count - 1;
				int key = 0;

				do
				{
					r2tm::WindowsUtility::MoveCursorPointWithClearBuffer( pivot_cursor );

					OUT_STRING( version_history_string_list[i] );

					LS();

					key = GET_KEY;

					switch( key )
					{
					case 'q':
						++i;
						i = ( version_history_count > i ? i : version_history_count - 1 );
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