#include "menu_inspector_demo.hpp"

#include "r2tm/r2tm_menu_processor.hpp"

#include "test_inspector_demo.hpp"

#include "menu_dev.hpp"

r2tm::eStatus Menu_Demo::GetStatus() const
{
	return r2tm::eStatus::Complete;
}
r2tm::TitleFunctionT Menu_Demo::GetTitleFunction() const
{
	return []()->const char*
	{
		return "Menu : Demo";
	};
}
r2tm::DescriptionFunctionT Menu_Demo::GetDescriptionFunction() const
{
	return []()->const char*
	{
		return "";
	};
}
r2tm::WriteFunctionT Menu_Demo::GetWriteFunction() const
{
	return []( r2tm::MenuProcessor* mp )
	{
		mp->AddMessage( "Message Demo");



		mp->AddLineFeed();



		mp->AddMessage( "Status Demo", r2tm::eColor::FG_LightAqua );
		mp->AddStatus( r2tm::eStatus::None );
		mp->AddStatus( r2tm::eStatus::Ready );
		mp->AddStatus( r2tm::eStatus::Play );
		mp->AddStatus( r2tm::eStatus::Pause );
		mp->AddStatus( r2tm::eStatus::Stop );
		mp->AddStatus( r2tm::eStatus::Complete );
		mp->AddStatus( r2tm::eStatus() );



		mp->AddLineFeed();



		mp->AddMessage( "Inspector Demo", r2tm::eColor::FG_Blue, r2tm::eColor::BG_Gray );
		mp->AddItem( '1', test_inspector_demo::Demo_1() );
		mp->AddItem( '2', test_inspector_demo::Demo_2() );



		mp->AddLineFeed();



		mp->AddMessage( "Item Status", r2tm::eColor::FG_Blue, r2tm::eColor::BG_Gray );
		mp->AddItem( '1', r2tm::eStatus::None,		[]() { return ""; }, []() { return r2tm::eDoLeaveAction::None; } );
		mp->AddItem( '2', r2tm::eStatus::Ready,		[]() { return ""; }, []() { return r2tm::eDoLeaveAction::None; } );
		mp->AddItem( '3', r2tm::eStatus::Play,		[]() { return ""; }, []() { return r2tm::eDoLeaveAction::None; } );
		mp->AddItem( '4', r2tm::eStatus::Pause,		[]() { return ""; }, []() { return r2tm::eDoLeaveAction::None; } );
		mp->AddItem( '5', r2tm::eStatus::Stop,		[]() { return ""; }, []() { return r2tm::eDoLeaveAction::None; } );
		mp->AddItem( '6', r2tm::eStatus::Complete,	[]() { return ""; }, []() { return r2tm::eDoLeaveAction::None; } );
		mp->AddItem( '7', r2tm::eStatus(),			[]() { return ""; }, []() { return r2tm::eDoLeaveAction::None; } );

		

		mp->AddSplit();



		mp->AddMenu( 27, Menu_Dev() );
	};
}