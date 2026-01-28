#pragma once

#include "r2tm/r2tm_interface_item.hpp"

namespace test_windows_utility_cursor_buffer
{
	class MoveCursorWithClearBuffer : public r2tm::iItem
	{
	public:
		r2tm::eStatus GetStatus() const override;
		r2tm::TitleFunctionT GetTitleFunction() const override;
		r2tm::DoFunctionT GetDoFunction() const override;
	};
}