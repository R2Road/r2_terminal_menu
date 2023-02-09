#pragma once

#include "r2cm/r2cm_iItem.h"

namespace test_key
{
	class View : public r2cm::iItem
	{
	public:
		r2cm::TitleFunctionT GetTitleFunction() const override;
		r2cm::DoFunctionT GetDoFunction() const override;
	};
}