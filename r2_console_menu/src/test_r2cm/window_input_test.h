#pragma once

#include "r2/r2_Singleton.h"
#include "r2cm/r2cm_iItem.h"

namespace window_input_test
{
	class TestKeyboardInputCollector : public r2cm::iItem, public r2::SingleTon<TestKeyboardInputCollector>
	{
	public:
		TitleFuncT GetTitleFunction() const override;
		DoFuncT GetDoFunction() override;
	};
}