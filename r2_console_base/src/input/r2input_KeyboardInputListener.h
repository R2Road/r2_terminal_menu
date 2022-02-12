#pragma once

#include <vector>

#include "r2input_Constant.h"

namespace r2input
{
	class KeyboardInputListener
	{
	public:
		enum class eKeyStatus
		{
			Release,
			Push,
			Pressed,
		};

		KeyboardInputListener( std::initializer_list<uint8_t> list );

		//
		// Getter
		//
		bool IsPushed( const std::size_t key_index ) const
		{
			return ( eKeyStatus::Push == mKeyStatusContainer[key_index] );
		}
		bool HasInput( const std::size_t key_index ) const
		{
			return ( eKeyStatus::Release < mKeyStatusContainer[key_index] );
		}

		//
		//
		//
		void Update();

		std::vector<KeyCodeTypeT> mObservationKeyList;
		std::vector<bool> mKeyFlags;
		std::vector<eKeyStatus> mKeyStatusContainer;
	};
}