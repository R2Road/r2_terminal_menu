#include "menu_cache_cleaner.hpp"

#include "r2tm/r2tm_menu_processor.hpp"

#include "test/test_cache_cleaner.hpp"

#include "menu_root.hpp"

r2tm::TitleFunctionT Menu_CacheCleaner::GetTitleFunction() const
{
	return []()->const char*
	{
		return "Menu : CacheCleaner";
	};
}
r2tm::DescriptionFunctionT Menu_CacheCleaner::GetDescriptionFunction() const
{
	return []()->const char*
	{
		return "";
	};
}
r2tm::WriteFunctionT Menu_CacheCleaner::GetWriteFunction() const
{
	return []( r2tm::MenuProcessor* mp )
	{
		mp->AddItem( '1', test_cache_cleaner::Basic() );
		mp->AddItem( '2', test_cache_cleaner::Size() );
		mp->AddItem( '3', test_cache_cleaner::Test() );
		mp->AddItem( '4', test_cache_cleaner::Test_Accumulate() );



		mp->AddSplit();



		mp->AddMenu( 27, Menu_Root() );
	};
}