#include "menu_stop_watch.hpp"

#include "r2tm/r2tm_MenuProcessor.h"

#include "test_stop_watch.hpp"

#include "menu_root.hpp"

r2tm::TitleFunctionT Menu_StopWatch::GetTitleFunction() const
{
	return []()->const char*
	{
		return "Menu : StopWatch";
	};
}
r2tm::DescriptionFunctionT Menu_StopWatch::GetDescriptionFunction() const
{
	return []()->const char*
	{
		return "";
	};
}
r2tm::WriteFunctionT Menu_StopWatch::GetWriteFunction() const
{
	return []( r2tm::MenuProcessor* mp )
	{
		mp->AddItem( '1', test_stop_watch::Declaration() );
		mp->AddItem( '2', test_stop_watch::Basic() );
		mp->AddItem( '3', test_stop_watch::Accumulate() );
		mp->AddItem( '4', test_stop_watch::Reset() );



		mp->AddSplit();



		mp->AddMenu( 27, Menu_Root() );
	};
}