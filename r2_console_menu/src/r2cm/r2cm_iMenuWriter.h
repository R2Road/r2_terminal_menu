#pragma once

#include <functional>

namespace r2cm
{
	class Menu;

	class iMenuWriter
	{
	public:
		using TitleFunctionT = std::function<const char*()>;
		using DescriptionFunctionT = std::function<const char*()>;
		using WriteFunctionT = std::function<void(Menu*)>;

		virtual ~iMenuWriter() {}

		virtual TitleFunctionT GetTitleFunction() const = 0;
		virtual DescriptionFunctionT GetDescriptionFunction() const = 0;
		virtual WriteFunctionT GetWriteFunction() const = 0;
	};
}