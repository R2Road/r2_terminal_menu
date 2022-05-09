#pragma once

#include "r2/r2_Singleton.h"
#include "r2cm/r2cm_iItem.h"

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