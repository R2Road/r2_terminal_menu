#pragma once

#include "r2tm_interface_item.hpp"

namespace r2tm_viewer
{
	class Key : public r2tm::iItem
	{
	public:
		r2tm::TitleFunctionT GetTitleFunction() const override;
		r2tm::DoFunctionT GetDoFunction() const override;
	};
}