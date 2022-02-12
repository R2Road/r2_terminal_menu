#include "pch.h"
#include "input/r2input_Constant.h"

#include <Windows.h>

namespace r2input
{
	int GetKeyState( const KeyCodeTypeT key_code )
	{
		return GetAsyncKeyState( key_code );
	}
}