#include "menu_tutorial.hpp"

#include "r2tm/r2tm_menu_processor.hpp"
#include "r2tm/r2tm_ostream.hpp"

#include "test_empty.hpp"

#include "menu_root.hpp"
#include "menu_make_menu.hpp"

r2tm::TitleFunctionT Menu_Tutorial::GetTitleFunction() const
{
	return []()->const char*
	{
		return "Menu : Tutorial";
	};
}
r2tm::DescriptionFunctionT Menu_Tutorial::GetDescriptionFunction() const
{
	return []()->const char*
	{
		return "";
	};
}
r2tm::WriteFunctionT Menu_Tutorial::GetWriteFunction() const
{
	return []( r2tm::MenuProcessor* mp )
	{
		mp->AddMessage( "# Test�� r2tm::iItem�� ����� �����", r2tm::eColor::FG_Yellow );
		mp->AddItem( '1', test_empty::Basic() );



		mp->AddLineFeed();



		mp->AddMessage( "# ������ Test�� ���� Ű�� �Ҵ� �غ���", r2tm::eColor::FG_Yellow );
		mp->AddItem( '2', test_empty::Basic() );



		mp->AddLineFeed();



		mp->AddMessage( "# Test�� r2tm::iItem �Ⱦ��� �����", r2tm::eColor::FG_Yellow );
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



		mp->AddMessage( "# Test�� r2tm::iMenu ��ü�� �����", r2tm::eColor::FG_Yellow );
		mp->AddMenu( '6', Menu_MakeMenu() );



		mp->AddSplit();



		mp->AddMenu( 27, Menu_Root() );
	};
}