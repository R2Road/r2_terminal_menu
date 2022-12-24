#pragma once

namespace r2cm
{

	//
	// 2022.05.06 by R
	//
	// 무리하지 않고 즐겁게 작업을 이어나갈 수 있도록 모든 방안을 강구할 것.
	//

	static struct
	{

		const char VersionNumber_1 = '1';	// 규칙 : 아래 명시된 목표 목록을 모두 완성하면 1 증가
		const char VersionNumber_2 = '0';	// 규칙 : 아래 명시한 목표가 여러 단계로 나뉘어 있는데 한 묶음을 완성하면 1 증가
		const char VersionNumber_3 = '4';	// 규칙 : 자잘한 작업을 진행 했고 그 것이 사용자의 코드에 어떤 변화를 유발하는 수준이면 1 증가

		const char String4Version[14] = { 'r', '2', 'c', 'm', ' ', ':', ' ', 'v', VersionNumber_1, '.', VersionNumber_2, '.', VersionNumber_3, '\0' };



		const char* const String4Road2Version_1_0_5 =
			"### Road 2 Version 1.0.5 ###"
			"\n"
			"\n"	"[o] " "update inspector : EXPECT_GT, EXPECT_LT, EXPECT_GE, EXPECT_LE - 실패시 값 출력"
			"\n"	"[ ] " "Split Menu And Menu View"
		; 
		
		const char* const String4Road2Version_1_0_4 =
			"### Road 2 Version 1.0.4 ###"
			"\n"
			"\n"	"[o] " "update method : apply const - r2cm::iItem::GetDoFunction"
			"\n"	"[o] " "remove class : r2cm::SingleTon"
		; 
		
		const char* const String4Road2Version_1_0_3 =
			"### Road 2 Version 1.0.3 ###"
			"\n"
			"\n"	"[o] " "update inspector : EXPECT_EQ, EXPECT_NE - 실패시 값 출력"
			"\n"	"[o] " "update inspector : OUTPUT_BINARY - 가시성 개선"
			"\n"	"[o] " "update inspector : inspector 의 debug break ON/OFF 설정"
			"\n"	"[o] " "update inspector : Add - OUTPUT_NOTE"
			"\n"	"[o] " "update inspector : Add - OUTPUT_COMMENT"
			"\n"	"[o] " "update inspector : OUTPUT_FILE 에서 line index 출력"
			"\n"	"[o] " "update inspector : Add - OUTPUT_FILE_RANGE"
		; 
		
		const char* const String4Road2Version_1_0_2 =
			"### Road 2 Version 1.0.2 ###"
			"\n"
			"\n"	"[o] " "add method : r2cm::WindowUtility::ScrollBarVisible"
			"\n"	"[o] " "add method : r2cm::WindowUtility::MaximizeButtonEnable"
			"\n"	"[o] " "add method : r2cm::WindowUtility::ResizingByDraggingEnable"
			"\n"	"[o] " "add method : r2cm::WindowUtility::QuickEditEnable"
		; 
		
		const char* const String4Road2Version_1_0_1 =
			"### Road 2 Version 1.0.1 ###"
			"\n"
			"\n"	"[o] " "add class : r2cm::StopWatch"
			"\n"	"[o] " "update method : r2cm::Menu::AddItem - Item 제목에 컬러 적용"
			"\n"	"[o] " "update method : r2cm::Menu::Do - 메뉴 제목의 # 을 사용자가 입력하지 않아도 되도록 조정"
		;

		const char* const String4Road2Version_1_0_0 =
					"### Road 2 Version 1.0.0 ###"
			"\n"
			"\n"	"[o] " "Director, Menu, Item"
			"\n"	"[o] " "Inspector"
			"\n"	"[o] " "Window Utility"
			"\n"	"[o] " "Color Modifier"
		;

	} VersionInfo;
}