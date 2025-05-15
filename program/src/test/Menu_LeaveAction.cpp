#include "Menu_LeaveAction.h"

#include "r2tm/r2tm_MenuProcessor.h"

#include "menu_root.h"

#include "test_leave_action.h"

r2tm::TitleFunctionT Menu_LeaveAction::GetTitleFunction() const
{
	return []()->const char*
	{
		return "Menu : Leave Action";
	};
}
r2tm::DescriptionFunctionT Menu_LeaveAction::GetDescriptionFunction() const
{
	return []()->const char*
	{
		return "";
	};
}
r2tm::WriteFunctionT Menu_LeaveAction::GetWriteFunction() const
{
	return []( r2tm::MenuProcessor* mp )
	{
		mp->AddMessage( "# Test 끝에 반환하는 r2tm::eDoLeaveAction 의 효과", r2tm::eColor::FG_Green );



		mp->AddLineFeed();



		mp->AddItem( '1', test_leave_action::eDoLeaveAction_None() );
		mp->AddItem( '2', test_leave_action::eDoLeaveAction_Pause() );
		mp->AddItem( '3', test_leave_action::eDoLeaveAction_Exit() );



		mp->AddSplit();



		mp->AddMenu( 27, MenuRoot() );
	};
}