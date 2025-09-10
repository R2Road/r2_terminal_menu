#include "r2tm_viewer_window_size.hpp"

#include <iomanip>
#include <iostream>
#include <string>
#include <Windows.h>

namespace r2tm_viewer
{
	r2tm::TitleFunctionT WindowSize::GetTitleFunction() const
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
	r2tm::DoFunctionT WindowSize::GetDoFunction() const
	{
		return []()->r2tm::eDoLeaveAction
		{
			//
			// ��� ����
			// #   12345678901234567890123456789012345678901234567890
			// 
			// 1 | 1         1         2         3         ...
			// 2 | 2         1         2         3         ...
			// 3 | 3         1         2         3         ...
			// 4 | 4         1         2         3         ...
			// .
			// .
			// .
			// 
			// > ���� 10ĭ�� ���� ��ȣ ����� ���� ���
			// > ���� 10ĭ ���� �� ��ȣ ���
			//

			const HANDLE hStdout = GetStdHandle( STD_OUTPUT_HANDLE );
			CONSOLE_SCREEN_BUFFER_INFO csbi;
			GetConsoleScreenBufferInfo( hStdout, &csbi );

			//
			// �� ���� ���ڿ� ����
			//  > ���� : 1         2         3         4         5         6         7         8         9         0        1 ...
			//
			std::string s( csbi.srWindow.Right - 10, ' ' );
			{
				char n = '1';
				const decltype( s.size() ) mark_count = s.size() / 10u;
				for( decltype( s.size() ) i = 0; i < mark_count; ++i )
				{
					++n;
					n = ( n > '9' ) ? '0' : n;

					s[( i * 10 )] = n;
				}
			}

			//
			// ���
			//
			for( decltype( csbi.srWindow.Bottom ) i = 0; i < csbi.srWindow.Bottom - 1; i++ )
			{
				std::cout
					<< std::left << std::setw( 10 ) << i    // ���� ��ȣ ���
					<< s                                    // �� ��ȣ ���
					<< "\n";
			}

			return r2tm::eDoLeaveAction::Pause;
		};
	}
}