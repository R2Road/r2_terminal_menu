#pragma once

#include "base/r2cm_iItem.h"
#include "base/r2_Singleton.h"

namespace base_test
{
	class TestEndAction_None : public r2cm::iItem, public r2::SingleTon<TestEndAction_None>
	{
	public:
		TitleFuncT GetTitleFunction() const override;
		DoFuncT GetDoFunction() override;
	};

	class TestEndAction_Pause : public r2cm::iItem, public r2::SingleTon<TestEndAction_Pause>
	{
	public:
		TitleFuncT GetTitleFunction() const override;
		DoFuncT GetDoFunction() override;
	};

	class TestEndAction_Exit : public r2cm::iItem, public r2::SingleTon<TestEndAction_Exit>
	{
	public:
		TitleFuncT GetTitleFunction() const override;
		DoFuncT GetDoFunction() override;
	};
}