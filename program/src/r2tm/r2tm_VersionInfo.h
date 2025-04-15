#pragma once

namespace r2tm
{

	//
	// 2022.05.06 by R
	//
	// �������� �ʰ� ��̰� �۾��� �̾�� �� �ֵ��� ��� ����� ������ ��.
	//

	constexpr struct
	{

		const char* const String4VersionRule =
					"### Version Rule ###"
			"\n"
			"\n"	"> " "1.0.0.0.0"  " : "  "�ϼ�?"
			"\n"	"> " "0.1.0.0.0"  " : "  "Road �Ϸ�"
			"\n"	"> " "0.0.1.0.0"  " : "  "Road �۾� ��� 1�� �Ϸ�"
			"\n"	"> " "0.0.0.1.0"  " : "  "���� ����.���� ��� ����"
			"\n"	"> " "0.0.0.0.1"  " : "  "����ڰ� ���� ������ ���� �Ǵ� ��ȭ"
		;



		const char VersionNumber_1 = '1';
		const char VersionNumber_2 = '7';
		const char VersionNumber_3 = '1';
		const char VersionNumber_4 = '3';
		const char VersionNumber_5 = '1';

		const char String4Version[18] = { 'r', '2', 't', 'm', ' ', ':', ' ', 'v', VersionNumber_1, '.', VersionNumber_2, '.', VersionNumber_3, '.', VersionNumber_4, '.', VersionNumber_5, '\0' };



		const char* const String4Road2Version_1_8_0_0_0 =
					"### Road 2 Version 1.8.0.0.0 ###"
			"\n"
			"\n"	"[o] " "update    function   : r2tm::Inspector - OUTPUT_NOTE"
			"\n"	"[o] " "update    struct     : r2tm::WindowsUtility::CursorPoint - ������ �߰�, ������ +, += �߰�"
			"\n"	"[o] " "update    inspector  : Add - OUTPUT_SOURCE_READY, OUTPUT_SOURCE_BEGIN, OUTPUT_SOURCE_END"
			"\n"	"[o] " "update    inspector  : Add - OUTPUT_SOURCE_READY_N_BEGIN"
			"\n"	"[o] " "update    inspector  : DECLARATION_MAIN, DECLARATION_SUB - ���� ����� ���� �ϰ� �ڵ� ����"
			"\n"	"[o] " "update    inspector  : EXPECT_FALSE, EXPECT_NE - ���� �� ���̴� �������� ����"
			"\n"	"[o] " "add class            : r2tm::CacheCleaner"
			"\n"	"[o] " "add method           : r2tm::SwtopWatch > Reset"
			"\n"	"[o] " "add method           : r2tm::SwtopWatch > PrintAverageTime_MilliSeconds, MicroSeconds, NanoSeconds, All"
			"\n"	"[o] " "update class         : r2tm::CacheCleaner : Add > ���� ������ �߰�, ���� ������ ����"
			"\n"	"[o] " "update inspector     : OUTPUT_SUBJECT: ��� ���� ����  '+' > '#'"
			"\n"	"[ ] " "..."
		;

		const char* const String4Road2Version_1_7_0_0_0 =
					"### Road 2 Version 1.7.0.0.0 ###"
			"\n"
			"\n"	"[o] " "add method           : r2tm::WindowsUtility::FillString"
			"\n"	"[o] " "update inspector     : Add - OUTPUT_STRING"
			"\n"	"[o] " "update inspector     : OUTPUT_SIZE - ũ�� �ڿ� byte ���ڿ� ���"
			"\n"	"[o] " "rename method        : r2tm::StopWatch - PrintMinAndMaxTime_NanoSeconds"
			"\n"	"[o] " "add    method        : r2tm::StopWatch - PrintMinAndMaxTime_MilliSeconds"
			"\n"	"[o] " "add    method        : r2tm::StopWatch - PrintMinAndMaxTime_MicroSeconds"
			"\n"	"[o] " "update menuprocessor : Ű, �޼��� �ؽ�Ʈ�� ��׶��� ���� ����"
			"\n"	"[o] " "overload    method   : r2tm::WindowsUtility - FillString"
			"\n"	"[o] " "overload    method   : r2tm::WindowsUtility - MoveCursorPoint"
			"\n"	"[o] " "overload    method   : r2tm::WindowsUtility - FillCharacter"
			"\n"	"[o] " "overload    method   : r2tm::WindowsUtility - FillColor"
			"\n"	"[o] " "overload    method   : r2tm::WindowsUtility - MoveCursorPointWithClearBuffer"
		;

		const char* const String4Road2Version_1_6_0_0_0 =
					"### Road 2 Version 1.6.0.0.0 ###"
			"\n"
			"\n"	"[o] " "update inspector : Add - OUTPUT_SUBJECT"
			"\n"	"[o] " "update inspector : Add - OUTPUT_SIZE"
			"\n"	"[o] " "update ostream : Add - LF(), LF2(), LF3(), LS()"
			"\n"	"[o] " "update menuprocessor : Add - AddExit"
			"\n"	"[o] " "update inspector : Apply Color - OUTPUT_NOTE, OUTPUT_SUBJECT, OUTPUT_COMMENT, OUTPUT_CODE"
		;

		const char* const String4Road2Version_1_5_0_0_0 =
					"### Road 2 Version 1.5.0.0.0 ###"
			"\n"
			"\n"	"[o] " "update inspector : EXPECT_GT, EXPECT_LT, EXPECT_GE, EXPECT_LE - ���н� �� ���"
			"\n"	"[o] " "Split Menu And MenuProcessor"
		;
		
		const char* const String4Road2Version_1_4_0_0_0 =
					"### Road 2 Version 1.4.0.0.0 ###"
			"\n"
			"\n"	"[o] " "update method : apply const - r2tm::iItem::GetDoFunction"
			"\n"	"[o] " "remove class : r2tm::SingleTon"
		;
		
		const char* const String4Road2Version_1_3_0_0_0 =
					"### Road 2 Version 1.3.0.0.0 ###"
			"\n"
			"\n"	"[o] " "update inspector : EXPECT_EQ, EXPECT_NE - ���н� �� ���"
			"\n"	"[o] " "update inspector : OUTPUT_BINARY - ���ü� ����"
			"\n"	"[o] " "update inspector : inspector �� debug break ON/OFF ����"
			"\n"	"[o] " "update inspector : Add - OUTPUT_NOTE"
			"\n"	"[o] " "update inspector : Add - OUTPUT_COMMENT"
			"\n"	"[o] " "update inspector : OUTPUT_FILE ���� line index ���"
			"\n"	"[o] " "update inspector : Add - OUTPUT_FILE_RANGE"
		;
		
		const char* const String4Road2Version_1_2_0_0_0 =
					"### Road 2 Version 1.2.0.0.0 ###"
			"\n"
			"\n"	"[o] " "add method : r2tm::WindowsUtility::ScrollBarVisible"
			"\n"	"[o] " "add method : r2tm::WindowsUtility::MaximizeButtonEnable"
			"\n"	"[o] " "add method : r2tm::WindowsUtility::ResizingByDraggingEnable"
			"\n"	"[o] " "add method : r2tm::WindowsUtility::QuickEditEnable"
		;
		
		const char* const String4Road2Version_1_1_0_0_0 =
					"### Road 2 Version 1.1.0.0.0 ###"
			"\n"
			"\n"	"[o] " "add class : r2tm::StopWatch"
			"\n"	"[o] " "update method : r2tm::Menu::AddItem - Item ���� �÷� ����"
			"\n"	"[o] " "update method : r2tm::Menu::Do - �޴� ������ # �� ����ڰ� �Է����� �ʾƵ� �ǵ��� ����"
		;

		const char* const String4Road2Version_1_0_0_0_0 =
					"### Road 2 Version 1.0.0.0.0 ###"
			"\n"
			"\n"	"[o] " "Director, Menu, Item"
			"\n"	"[o] " "Inspector"
			"\n"	"[o] " "Window Utility"
			"\n"	"[o] " "Color Modifier"
		;



		const char* const String4Road2NextVersion = String4Road2Version_1_8_0_0_0;

	} VersionInfo;
}