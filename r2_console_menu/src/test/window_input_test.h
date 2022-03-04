#pragma once

#include "base/r2cm_iItem.h"
#include "r2/r2_Singleton.h"

namespace window_input_test
{
	class TestKeyboardInputCollector : public r2cm::iItem, public r2::SingleTon<TestKeyboardInputCollector>
	{
	public:
		TitleFuncT GetTitleFunction() const override;
		DoFuncT GetDoFunction() override;
	};
}