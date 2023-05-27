#pragma once

#include "r2cm/r2cm_iMenu.h"

class AnotherMenu : public r2tm::iMenu
{
public:
	r2tm::TitleFunctionT GetTitleFunction() const override;
	r2tm::DescriptionFunctionT GetDescriptionFunction() const override;
	r2tm::WriteFunctionT GetWriteFunction() const override;
};