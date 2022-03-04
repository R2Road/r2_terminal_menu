#pragma once

#include "base/r2_iTest.h"
#include "base/r2_Singleton.h"

namespace base_test
{
	class TestEndAction_None : public r2::iItem, public r2::SingleTon<TestEndAction_None>
	{
	public:
		TitleFunc GetTitleFunction() const override;
		DoFunc GetDoFunction() override;
	};

	class TestEndAction_Pause : public r2::iItem, public r2::SingleTon<TestEndAction_Pause>
	{
	public:
		TitleFunc GetTitleFunction() const override;
		DoFunc GetDoFunction() override;
	};

	class TestEndAction_Exit : public r2::iItem, public r2::SingleTon<TestEndAction_Exit>
	{
	public:
		TitleFunc GetTitleFunction() const override;
		DoFunc GetDoFunction() override;
	};
}