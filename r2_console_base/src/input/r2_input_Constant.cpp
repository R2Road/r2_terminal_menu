#include "pch.h"
#include "input/r2_input_Constant.h"

#include <Windows.h>

namespace r2_input
{
	int GetKeyState( const KeyCodeTypeT key_code )
	{
		return GetAsyncKeyState( key_code );
	}
}