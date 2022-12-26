#pragma once

#include "r2cm/r2cm_iMenuWriter.h"

class InspectorMenu : public r2cm::iMenuWriter
{
public:
	r2cm::TitleFunctionT GetTitleFunction() const override;
	r2cm::DescriptionFunctionT GetDescriptionFunction() const override;
	r2cm::WriteFunctionT GetWriteFunction() const override;
};