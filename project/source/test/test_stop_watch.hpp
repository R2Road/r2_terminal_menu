#pragma once

#include "r2tm/r2tm_interface_item.hpp"

namespace test_stop_watch
{
	class Declaration : public r2tm::iItem
	{
	public:
		r2tm::eStatus GetStatus() const override;
		r2tm::TitleFunctionT GetTitleFunction() const override;
		r2tm::DoFunctionT GetDoFunction() const override;
	};

	class Basic : public r2tm::iItem
	{
	public:
		r2tm::eStatus GetStatus() const override;
		r2tm::TitleFunctionT GetTitleFunction() const override;
		r2tm::DoFunctionT GetDoFunction() const override;
	};

	class Min_Max : public r2tm::iItem
	{
	public:
		r2tm::eStatus GetStatus() const override;
		r2tm::TitleFunctionT GetTitleFunction() const override;
		r2tm::DoFunctionT GetDoFunction() const override;
	};

	class Accumulate : public r2tm::iItem
	{
	public:
		r2tm::eStatus GetStatus() const override;
		r2tm::TitleFunctionT GetTitleFunction() const override;
		r2tm::DoFunctionT GetDoFunction() const override;
	};

	class Reset: public r2tm::iItem
	{
	public:
		r2tm::eStatus GetStatus() const override;
		r2tm::TitleFunctionT GetTitleFunction() const override;
		r2tm::DoFunctionT GetDoFunction() const override;
	};
}