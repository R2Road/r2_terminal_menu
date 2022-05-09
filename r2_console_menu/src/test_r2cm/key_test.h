#pragma once

#include "r2/r2_Singleton.h"
#include "r2cm/r2cm_iItem.h"

namespace key_test
{
	class Basic : public r2cm::iItem, public r2::SingleTon<Basic>
	{
	public:
		TitleFuncT GetTitleFunction() const override;
		DoFuncT GetDoFunction() override;
	};
}