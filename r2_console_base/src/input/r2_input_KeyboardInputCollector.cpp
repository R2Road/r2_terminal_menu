#include "pch.h"
#include "input/r2_input_KeyboardInputCollector.h"

#include <numeric>

#include "r2_input_KeyboardInputListener.h"

namespace r2_input
{
	KeyboardInputCollector::KeyboardInputCollector() : mKeyboardInputListener( nullptr )
	{}

	void KeyboardInputCollector::Collect()
	{
		if( nullptr == mKeyboardInputListener )
		{
			return;
		}

		int key_value = 0;

		for( std::size_t i = 0, end = mKeyboardInputListener->mObservationKeyList.size(); end > i; ++i )
		{
			key_value = GetKeyState( mKeyboardInputListener->mObservationKeyList[i] );
			mKeyboardInputListener->mKeyFlags[i] = key_value & 0x8000;
		}
	}
}