#pragma once

#include <functional>

namespace r2tm
{
	class MenuProcessor;

	enum class eDoLeaveAction
	{
		None,
		Pause,
		Exit,
	};

	using TitleFunctionT = std::function<const char*( )>;
	using DescriptionFunctionT = std::function<const char*( )>;
	using DoFunctionT = std::function<eDoLeaveAction()>;

	using WriteFunctionT = std::function<void( MenuProcessor* )>;
}