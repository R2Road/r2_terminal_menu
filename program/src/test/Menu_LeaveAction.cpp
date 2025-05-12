#include "Menu_LeaveAction.h"

#include "r2tm/r2tm_MenuProcessor.h"

#include "RootMenu.h"

#include "test_base.h"

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
	return []( r2tm::MenuProcessor* ret )
	{
		ret->AddMessage( "# Test 끝에 반환하는 r2tm::eDoLeaveAction 의 효과", r2tm::eColor::FG_Green );



		ret->AddLineFeed();



		ret->AddItem( '1', test_base::eDoLeaveAction_None() );
		ret->AddItem( '2', test_base::eDoLeaveAction_Pause() );
		ret->AddItem( '3', test_base::eDoLeaveAction_Exit() );



		ret->AddSplit();



		ret->AddMenu( 27, RootMenu() );
	};
}