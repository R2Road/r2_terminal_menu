#include "RootMenu.h"

#include <string>

#include "r2tm/r2tm_Director.h"
#include "r2tm/r2tm_ostream.h"
#include "r2tm/r2tm_VersionInfo.h"

#include "test/test_base.h"
#include "test/test_empty.h"
#include "test/test_key.h"
#include "test/test_stop_watch.h"

#include "test/Menu_Test.h"
#include "test/Menu_CacheCleaner.h"
#include "test/Menu_ColorModifier.h"
#include "test/Menu_Inspector.h"
#include "test/Menu_LeaveAction.h"
#include "test/Menu_StopWatch.h"
#include "test/Menu_WindowUtility.h"

r2tm::TitleFunctionT RootMenu::GetTitleFunction() const
{
	return []()->const char*
	{
		static const std::string ret =
			std::string()

			+ "Root Menu"
			  " : "	"<"   "C++17" + ">"
			  ", "	"<"   "MS C/C++ : " + std::to_string( _MSC_VER ) + ">"
			  ", "	"<" + r2tm::VersionInfo.String4Version + ">"
			;
		return ret.c_str();
	};
}
r2tm::DescriptionFunctionT RootMenu::GetDescriptionFunction() const
{
	return []()->const char*
	{
		static const std::string ret =
			std::string()

			+ r2tm::VersionInfo.String4VersionRule
			+ "\n"
			  "\n"
			  "\n"
			+ r2tm::VersionInfo.String4Road2NextVersion
		;
		return ret.c_str();
	};
}
r2tm::WriteFunctionT RootMenu::GetWriteFunction() const
{
	return []( r2tm::MenuProcessor* mp )
	{
		mp->AddMessage( "# Test�� r2tm::iItem�� ����� �����", r2tm::eColor::FG_LightRed );
		mp->AddItem( '1', test_empty::Basic() );
		mp->AddMessage( "# ������ Test�� ���� Ű�� �Ҵ� �غ���", r2tm::eColor::FG_LightRed );
		mp->AddItem( '2', test_empty::Basic() );



		mp->AddLineFeed();



		mp->AddMessage( "# Test�� r2tm::iItem �Ⱦ��� �����", r2tm::eColor::FG_LightRed );
		mp->AddItem(
			'3'
			, []()->const char*
			{
				return "Show Title With Lambda";
			}
			, []()->r2tm::eDoLeaveAction
			{
				LS();

				std::cout << r2tm::linefeed2 << "##### Show Title With Lambda #####" << r2tm::linefeed3;

				LS();

				return r2tm::eDoLeaveAction::Pause;
			}
		);



		mp->AddLineFeed();



		mp->AddMessage( "# Test�� r2tm::iMenu ��ü�� �����", r2tm::eColor::FG_LightRed );
		mp->AddMenu( '6', Menu_Test() );



		mp->AddLineFeed();



		mp->AddMenu( 'q', Menu_LeaveAction() );



		mp->AddLineFeed();



		mp->AddItem( 'a', test_key::View() );
		mp->AddMenu( 's', Menu_ColorModifier() );
		mp->AddMenu( 'd', Menu_StopWatch() );
		mp->AddMenu( 'f', Menu_Inspector() );



		mp->AddLineFeed();



		mp->AddMenu( 'z', Menu_WindowUtility() );
		mp->AddMenu( 'x', Menu_CacheCleaner() );
		



		mp->AddSplit();



		mp->AddExit( 27 );
	};
}