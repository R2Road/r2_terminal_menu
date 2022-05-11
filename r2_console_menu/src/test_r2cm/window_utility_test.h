#pragma once

#include "r2cm/r2cm_iItem.h"
#include "r2cm/r2cm_Singleton.h"

namespace window_utility_test
{
	class MoveCursorWithClearBuffer : public r2cm::iItem, public r2cm::SingleTon<MoveCursorWithClearBuffer>
	{
	public:
		TitleFuncT GetTitleFunction() const override;
		DoFuncT GetDoFunction() override;
	};
}