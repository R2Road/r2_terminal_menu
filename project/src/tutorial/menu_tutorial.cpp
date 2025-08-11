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
		mp->AddMessage( "# Test를 r2tm::iItem을 사용해 만들기", r2tm::eColor::FG_Yellow );
		mp->AddItem( '1', test_empty::Basic() );



		mp->AddLineFeed();



		mp->AddMessage( "# 동일한 Test를 여러 키에 할당 해보기", r2tm::eColor::FG_Yellow );
		mp->AddItem( '2', test_empty::Basic() );



		mp->AddLineFeed();



		mp->AddMessage( "# Test를 r2tm::iItem 안쓰고 만들기", r2tm::eColor::FG_Yellow );
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



		mp->AddMessage( "# Test를 r2tm::iMenu 객체로 묶어보기", r2tm::eColor::FG_Yellow );
		mp->AddMenu( '6', Menu_MakeMenu() );



		mp->AddSplit();



		mp->AddMenu( 27, Menu_Root() );
	};
}