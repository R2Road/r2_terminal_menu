#pragma once

#include "base/r2_iTest.h"
#include "base/r2_Singleton.h"

namespace base_test
{
	class None : public r2::iTest, public r2::SingleTon<None>
	{
	public:
		TitleFunc GetTitleFunction() const override;
		DoFunc GetDoFunction() override;
	};

	class Pause : public r2::iTest, public r2::SingleTon<Pause>
	{
	public:
		TitleFunc GetTitleFunction() const override;
		DoFunc GetDoFunction() override;
	};
}