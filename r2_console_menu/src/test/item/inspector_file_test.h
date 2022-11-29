#pragma once

#include "r2cm/r2cm_iItem.h"
#include "r2cm/r2cm_Singleton.h"

namespace inspector_file_test
{
	class File : public r2cm::iItem, public r2cm::SingleTon<File>
	{
	public:
		TitleFunctionT GetTitleFunction() const override;
		DoFunctionT GetDoFunction() const override;
	};

	class FileRange : public r2cm::iItem, public r2cm::SingleTon<FileRange>
	{
	public:
		TitleFunctionT GetTitleFunction() const override;
		DoFunctionT GetDoFunction() const override;
	};
}