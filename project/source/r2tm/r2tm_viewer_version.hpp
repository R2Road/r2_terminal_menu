#pragma once

#include "r2tm_interface_item.hpp"

namespace r2tm_viewer
{
	class Version : public r2tm::iItem
	{
	public:
		Version( const char* const* version_history_string_list, const int version_history_count);

		r2tm::TitleFunctionT GetTitleFunction() const override;
		r2tm::DoFunctionT GetDoFunction() const override;

	private:
		const char* const* mVersionHistoryStringList;
		const int mVersionHistoryCount;
	};
}