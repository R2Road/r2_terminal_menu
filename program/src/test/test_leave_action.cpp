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

			OUTPUT_SUBJECT( "Action�� ��ȯ�Ǹ� �ٷ� �޴� ȭ������ ����" );

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

			OUTPUT_SUBJECT( "Action�� ��ȯ�Ǹ� ���� ȭ�鿡�� ���" );
			OUTPUT_SUBJECT( "Ű�� �Է��ϸ� �޴� ȭ������ ����" );

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

			OUTPUT_SUBJECT( "Action�� ��ȯ�Ǹ� ���α׷� ����" );

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