#pragma once

#include <functional>

#include "r2cm_DoLeaveAction.h"

namespace r2cm
{
	class iItem
	{
	public:
		using TitleFunctionT = std::function<const char*()>;
		using DoFunctionT = std::function<eDoLeaveAction()>;

		virtual ~iItem() {}

		virtual TitleFunctionT GetTitleFunction() const = 0;
		virtual DoFunctionT GetDoFunction() const = 0;
	};
}