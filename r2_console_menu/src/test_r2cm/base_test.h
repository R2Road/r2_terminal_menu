#pragma once

#include "r2cm/r2cm_Singleton.h"
#include "r2cm/r2cm_iItem.h"

namespace base_test
{
	class TestEndAction_None : public r2cm::iItem, public r2cm::SingleTon<TestEndAction_None>
	{
	public:
		TitleFunctionT GetTitleFunction() const override;
		DoFunctionT GetDoFunction() override;
	};

	class TestEndAction_Pause : public r2cm::iItem, public r2cm::SingleTon<TestEndAction_Pause>
	{
	public:
		TitleFunctionT GetTitleFunction() const override;
		DoFunctionT GetDoFunction() override;
	};

	class TestEndAction_Exit : public r2cm::iItem, public r2cm::SingleTon<TestEndAction_Exit>
	{
	public:
		TitleFunctionT GetTitleFunction() const override;
		DoFunctionT GetDoFunction() override;
	};
}