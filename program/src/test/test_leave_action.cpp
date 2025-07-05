#include "test_leave_action.h"

#include "r2tm/r2tm_ostream.h"
#include "r2tm/r2tm_Inspector.h"

namespace test_leave_action
{
	r2tm::TitleFunctionT eDoLeaveAction_None::GetTitleFunction() const
	{
		return []()->const char*
		{
			return "Base : eDoLeaveAction_None";
		};
	}
	r2tm::DoFunctionT eDoLeaveAction_None::GetDoFunction() const
	{
		return []()->r2tm::eDoLeaveAction
		{
			LS();

			OUTPUT_SUBJECT( "Action이 반환되면 바로 메뉴 화면으로 복귀" );

			LS();

			OUTPUT_COMMENT( "Press [ESC] Key" );

			do
			{
			} while( 27 != GET_KEY );

			LS();

			return r2tm::eDoLeaveAction::None;
		};
	}



	r2tm::TitleFunctionT eDoLeaveAction_Pause::GetTitleFunction() const
	{
		return []()->const char*
		{
			return "Base : eDoLeaveAction_Pause";
		};
	}
	r2tm::DoFunctionT eDoLeaveAction_Pause::GetDoFunction() const
	{
		return []()->r2tm::eDoLeaveAction
		{
			LS();

			OUTPUT_SUBJECT( "Action이 반환되면 현재 화면에서 대기" );
			OUTPUT_SUBJECT( "키를 입력하면 메뉴 화면으로 복귀" );

			LS();

			OUTPUT_COMMENT( "Press [ESC] Key" );

			do
			{
			} while( 27 != GET_KEY );

			LS();

			return r2tm::eDoLeaveAction::Pause;
		};
	}



	r2tm::TitleFunctionT eDoLeaveAction_Exit::GetTitleFunction() const
	{
		return []()->const char*
		{
			return "Base : eDoLeaveAction_Exit";
		};
	}
	r2tm::DoFunctionT eDoLeaveAction_Exit::GetDoFunction() const
	{
		return []()->r2tm::eDoLeaveAction
		{
			LS();

			OUTPUT_SUBJECT( "Action이 반환되면 프로그램 종료" );

			LS();

			OUTPUT_COMMENT( "Press [ESC] Key" );

			do
			{
			} while( 27 != GET_KEY );

			LS();

			return r2tm::eDoLeaveAction::Exit;
		};
	}
}