#include "pch.h"
#include "input/r2input_KeyboardInputListener.h"

namespace r2input
{
	KeyboardInputListener::KeyboardInputListener( std::initializer_list<uint8_t> list ) :
		mObservationKeyList( list )
		, mKeyFlags( mObservationKeyList.size(), 0 )
		, mKeyStatusContainer( mObservationKeyList.size(), eKeyStatus::Release )
	{}

	void KeyboardInputListener::Update()
	{
		for( std::size_t i = 0u; mKeyFlags.size() > i; ++i )
		{
			if( mKeyFlags[i] )
			{
				switch( mKeyStatusContainer[i] )
				{
				case eKeyStatus::Push:
					mKeyStatusContainer[i] = eKeyStatus::Pressed;
					break;

				//case eKeyStatus::Pressed:
				//	break;

				case eKeyStatus::Release:
					mKeyStatusContainer[i] = eKeyStatus::Push;
					break;
				}
			}
			else
			{
				mKeyStatusContainer[i] = eKeyStatus::Release;
			}
		}
	}
}