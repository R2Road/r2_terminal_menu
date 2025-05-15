#include "Menu_CacheCleaner.h"

#include "r2tm/r2tm_MenuProcessor.h"

#include "test/test_cache_cleaner.h"

#include "menu_root.h"

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



		mp->AddMenu( 27, MenuRoot() );
	};
}