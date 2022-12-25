#pragma once

#include "r2cm/r2cm_iMenuWriter.h"

class InspectorMenu : public r2cm::iMenuWriter
{
public:
	TitleFunctionT GetTitleFunction() const override;
	DescriptionFunctionT GetDescriptionFunction() const override;
	WriteFunctionT GetWriteFunction() const override;
};