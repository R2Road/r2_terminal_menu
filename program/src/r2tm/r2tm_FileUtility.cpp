#include "r2tm_FileUtility.h"

#include <cstring>
#include <locale>
#include <string>

#include <Windows.h>

namespace r2tm
{
	bool FileUtility::isEnableWin32DirectoryOpen()
	{
#if _WIN64 == 1 || _WIN32 == 1
		return true;
#elif
		return false;
#endif
	}

	void FileUtility::DirectoryOpen( const char* utf8_path )
	{
		//const auto utf8_path_length = strlen( utf8_path );

		//std::wstring_convert<std::codecvt_utf8<wchar_t>> conv;
		//const std::wstring temp = conv.from_bytes( utf8_path, utf8_path + utf8_path_length ); // nrvo?

		ShellExecuteW( NULL, L"open", L"F:\Work\0_Pragma\9_etcProject\r2_cpp\r2\source\r2", NULL, NULL, SW_SHOWNORMAL );
	}
}