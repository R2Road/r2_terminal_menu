#pragma once

#include <functional>

namespace r2cm
{
	class Menu;

	enum class eDoLeaveAction
	{
		None,
		Pause,
		Exit,
	};

	using TitleFunctionT = std::function<const char*( )>;

	using DoFunctionT = std::function<eDoLeaveAction()>;

	using DescriptionFunctionT = std::function<const char*( )>;
	using WriteFunctionT = std::function<void( Menu* )>;
}