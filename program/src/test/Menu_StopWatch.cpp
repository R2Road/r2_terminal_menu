#include "Menu_StopWatch.h"

#include "r2tm/r2tm_MenuProcessor.h"

#include "test_stop_watch.h"

#include "RootMenu.h"

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



		mp->AddMenu( 27, RootMenu() );
	};
}