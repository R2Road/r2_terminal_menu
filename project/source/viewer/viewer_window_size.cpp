#include "viewer_window_size.hpp"

#include <iomanip>
#include <string>
#include <Windows.h>

#include "r2tm/r2tm_inspector.hpp"
#include "r2tm/r2tm_ostream.hpp"
#include "r2tm/r2tm_windows_utility.hpp"

#include "r2tm/r2tm_version_info.hpp"

namespace viewer_window_size
{
	r2tm::TitleFunctionT Viewer::GetTitleFunction() const
	{
		return []()->const char*
		{
			static std::string s;
			if( s.empty() )
			{
				HANDLE hStdout = GetStdHandle( STD_OUTPUT_HANDLE );
				CONSOLE_SCREEN_BUFFER_INFO csbi;
				GetConsoleScreenBufferInfo( hStdout, &csbi );

				s = "Viewer : Window Size";
				s += " | ";
				s += "width : " + std::to_string( csbi.srWindow.Right );
				s += "  , ";
				s += "height : " + std::to_string( csbi.srWindow.Bottom );
			}

			return s.c_str();
		};
	}
	r2tm::DoFunctionT Viewer::GetDoFunction() const
	{
		return []()->r2tm::eDoLeaveAction
		{
			HANDLE hStdout = GetStdHandle( STD_OUTPUT_HANDLE );
			CONSOLE_SCREEN_BUFFER_INFO csbi;
			GetConsoleScreenBufferInfo( hStdout, &csbi );

			//
			// ���ڿ� ����
			//  > ���� : 1         2         3         4         5         6         7         8         9
			//
			std::string s( csbi.srWindow.Right - 10, ' ' );
			{
				const decltype( s.size() ) mark_count = s.size() / 10u;
				char n = '1';
				for( decltype( s.size() ) i = 0; i < mark_count; ++i, ++n )
				{
					n = ( n > '9' ) ? '0' : n;
					s[( i * 10 )] = n;
				}
			}

			//
			// ���
			//  > �տ� 10ĭ�� ���� ��	ȣ ����� ���� ���
			//  > ���� 10 ������ �� ��ȣ ���
			//
			for( decltype( csbi.srWindow.Bottom ) i = 0; i < csbi.srWindow.Bottom - 1; i++ )
			{
				std::cout << std::left << std::setw( 10 ) << i << s;
				
				LF();
			}

			return r2tm::eDoLeaveAction::Pause;
		};
	}
}