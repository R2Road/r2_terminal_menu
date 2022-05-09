#pragma once

#include <functional>

namespace r2cm
{
	enum class eItemEndAction;

	class iItem
	{
	public:
		using TitleFuncT = std::function<const char*()>;
		using DoFuncT = std::function<eItemEndAction()>;

		virtual ~iItem() {}

		virtual TitleFuncT GetTitleFunction() const = 0;
		virtual DoFuncT GetDoFunction() = 0;
	};
}