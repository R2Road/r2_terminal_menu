#pragma once

#include "r2tm/r2tm_interface_item.hpp"

namespace viewer_window_size
{
	class Viewer : public r2tm::iItem
	{
	public:
		r2tm::TitleFunctionT GetTitleFunction() const override;
		r2tm::DoFunctionT GetDoFunction() const override;
	};
}