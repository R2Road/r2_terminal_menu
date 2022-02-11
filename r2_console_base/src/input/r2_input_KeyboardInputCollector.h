#pragma once

#include <vector>

#include "r2_input_Constant.h"

namespace r2_input
{
	class KeyboardInputListener;

	class KeyboardInputCollector
	{
	public:
		KeyboardInputCollector();

		//
		//
		//
		void Collect();

		//
		//
		//
		void ClearListener()
		{
			mKeyboardInputListener = nullptr;
		}
		void AddListener( KeyboardInputListener* listener )
		{
			mKeyboardInputListener = listener;
		}

	private:
		KeyboardInputListener* mKeyboardInputListener;
	};
}