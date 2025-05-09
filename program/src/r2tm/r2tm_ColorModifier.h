#pragma once

#include <iostream>

#include "r2tm_Color.h"

namespace r2tm
{
	//
	// REF : https://stackoverflow.com/questions/2616906/how-do-i-output-coloured-text-to-a-linux-terminal
	// 1�� 2�� ������ ���� �� REF�� �ִ� 3�� �������� ���ߴ�. Link�� ����� ���� � �ǹ̷δ� �����̱���. - 2022.05.24 by R2Road
	//
	class ColorModifier
	{
	public:
		ColorModifier() : mColor( eColor::None ) {}
		ColorModifier( const eColor color ) : mColor( color ) {}

		friend std::ostream& operator<<( std::ostream& os, const ColorModifier& color_modifier )
		{
			//
			// 2022.07.10 by R
			// - std::hex ���� ���̸� " << mf.mColor " �� �����۵����� �ʴ´�.
			// - ���� ��ȯ�ؼ� ����ϸ� �ذ������ ������ �Ű澲�̹Ƿ� ��ġ�ϱ�� ����.
			//

			static const char* header = "\033[";
			static const char* tail = "m";
			return os << header << color_modifier.mColor << tail;
		}

	private:
		eColor mColor;
	};
}

using clm = r2tm::ColorModifier;