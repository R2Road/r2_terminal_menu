#include "Menu_StopWatch.h"

#include "r2tm/r2tm_Director.h"

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
	return []( r2tm::MenuProcessor* ret )
	{
		ret->AddItem( '1', test_stop_watch::Basic() );
		ret->AddItem( '2', test_stop_watch::Accumulate() );



		ret->AddSplit();



		ret->AddMenu( 27, RootMenu() );
	};
}