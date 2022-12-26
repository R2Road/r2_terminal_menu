#pragma once

#include <functional>

namespace r2cm
{
	enum class eDoLeaveAction
	{
		None,
		Pause,
		Exit,
	};

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