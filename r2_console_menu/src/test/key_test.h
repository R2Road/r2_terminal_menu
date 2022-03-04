#pragma once

#include "base/r2_iItem.h"
#include "base/r2_Singleton.h"

namespace key_test
{
	class Basic : public r2cm::iItem, public r2::SingleTon<Basic>
	{
	public:
		TitleFuncT GetTitleFunction() const override;
		DoFuncT GetDoFunction() override;
	};
}