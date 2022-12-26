#pragma once

#include "r2cm_DoLeaveAction.h"

namespace r2cm
{
	class iItem
	{
	public:
		virtual ~iItem() {}

		virtual TitleFunctionT GetTitleFunction() const = 0;
		virtual DoFunctionT GetDoFunction() const = 0;
	};
}