#pragma once

#include <iostream>

#include "r2tm_Color.h"

namespace r2tm
{
	//
	// REF : https://stackoverflow.com/questions/2616906/how-do-i-output-coloured-text-to-a-linux-terminal
	// 1과 2를 생각해 놓고 위 REF에 있는 3에 도달하지 못했다. Link를 남기는 것이 어떤 의미로는 굴욕이구만. - 2022.05.24 by R2Road
	//
	class ColorModifier
	{
	public:
		static const eColor DEFAULT_COLOR = eColor::None;

		ColorModifier() : mColor( DEFAULT_COLOR )
		{}
		explicit ColorModifier( const eColor color ) : mColor( color )
		{}

		eColor GetColor() const
		{
			return mColor;
		}

		friend std::ostream& operator<<( std::ostream& os, const ColorModifier& color_modifier )
		{
			//
			// 2022.07.10 by R
			// - std::hex 등이 쓰이면 " << color_modifier.GetColor()" 가 정상작동하지 않는다.
			// - 문자 변환해서 기록하면 해결되지만 성능이 신경쓰이므로 방치하기로 하자.
			//

			static const char* header = "\033[";
			static const char* tail = "m";
			return os << header << static_cast<int>( color_modifier.GetColor() ) << tail;
		}

	private:
		eColor mColor;
	};
}

using clm = r2tm::ColorModifier;