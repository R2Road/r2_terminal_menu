#pragma once

#include "base/r2_iTest.h"
#include "base/r2_Singleton.h"

namespace base_test
{
	class RunTest_Without_Pause : public r2::iTest, public r2::SingleTon<RunTest_Without_Pause>
	{
	public:
		TitleFunc GetTitleFunction() const override;
		DoFunc GetDoFunction() override;
	};
}