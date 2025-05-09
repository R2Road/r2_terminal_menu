#include "Menu_CacheCleaner.h"

#include "r2tm/r2tm_MenuProcessor.h"

#include "test/test_cache_cleaner.h"

#include "RootMenu.h"

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
	return []( r2tm::MenuProcessor* ret )
	{
		ret->AddItem( '1', test_cache_cleaner::Basic() );
		ret->AddItem( '2', test_cache_cleaner::Size() );
		ret->AddItem( '3', test_cache_cleaner::Test() );
		ret->AddItem( '4', test_cache_cleaner::Test_Accumulate() );



		ret->AddSplit();



		ret->AddMenu( 27, RootMenu() );
	};
}