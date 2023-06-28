#pragma once

namespace r2tm
{
	class FileUtility
	{
	private:
		FileUtility() = delete;

	public:
		static bool isEnableWin32DirectoryOpen();
		static void DirectoryOpen( const char* utf8_path );
	};
}
