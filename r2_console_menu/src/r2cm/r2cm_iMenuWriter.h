#pragma once

#include "r2cm_MenuConstant.h"

namespace r2cm
{
	class iMenuWriter
	{
	public:
		virtual ~iMenuWriter() {}

		virtual TitleFunctionT GetTitleFunction() const = 0;
		virtual DescriptionFunctionT GetDescriptionFunction() const = 0;
		virtual WriteFunctionT GetWriteFunction() const = 0;
	};
}