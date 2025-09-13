#include "menu_portfolio.hpp"

#include <string>

#include "r2tm/r2tm_director.hpp"
#include "r2tm/r2tm_ostream.hpp"
#include "r2tm/r2tm_version_info.hpp"

#include "test/test_inspector_base.hpp"
#include "test/test_inspector_binary.hpp"
#include "test/test_inspector_demo.hpp"
#include "test/test_inspector_file.hpp"
#include "test/test_inspector_input.hpp"
#include "test/test_inspector_source.hpp"

#include "menu_dev.hpp"

r2tm::TitleFunctionT Menu_Portfolio::GetTitleFunction() const
{
	return []()->const char*
	{
		return "Portfolio";
	};
}
r2tm::DescriptionFunctionT Menu_Portfolio::GetDescriptionFunction() const
{
	return []()->const char*
	{
		return (
			      "  "  "주요 코드는 프로젝트의 r2tm 폴더 안에 있습니다."
			"\n"
			"\n"  "  "  "키보드 조작으로 지정된 기능이 실행됩니다."
			"\n"
			"\n"  "  "  "코드의 기능을 테스트 하고 정돈된 로그를 출력해주기 위한 도구 입니다."
			"\n"  "  "  "제가 만든 터미널 기반 프로젝트에는 이 코드들이 항상 쓰입니다."
		);
	};
}
r2tm::WriteFunctionT Menu_Portfolio::GetWriteFunction() const
{
	return []( r2tm::MenuProcessor* mp )
	{
		mp->AddMessage( "이 프로젝트 하려는 것을 빠르게 알아 보려면 아래 Demo를 봅니다.", r2tm::eColor::FG_Yellow );
		mp->AddItem( '1', test_inspector_demo::Demo_1() );
		mp->AddItem( '2', test_inspector_demo::Demo_2() );



		mp->AddLineFeed();
		mp->AddLineFeed();



		mp->AddMessage( "위 데모를 구성하는 Inspector의 기능 테스트 입니다.", r2tm::eColor::FG_Yellow );
		mp->AddItem( 'q', test_inspector_base::Basic() );
		mp->AddItem( 'w', test_inspector_base::Expect_1() );
		mp->AddItem( 'e', test_inspector_base::Size() );
		mp->AddItem( 'r', test_inspector_base::Address() );



		mp->AddLineFeed();



		mp->AddItem( 'a', test_inspector_binary::Binary() );
		mp->AddItem( 's', test_inspector_binary::Binaries_1() );



		mp->AddLineFeed();



		mp->AddItem( 'z', test_inspector_file::File_1() );
		mp->AddItem( 'x', test_inspector_file::FileRange_1() );
		mp->AddItem( 'c', test_inspector_source::Basic() );



		mp->AddLineFeed();
		mp->AddLineFeed();



		mp->AddMessage( "이 프로젝트의 개발 메뉴 Menu로 이동합니다.", r2tm::eColor::FG_Yellow );
		mp->AddMenu( 32, Menu_Dev() );
		



		mp->AddSplit();



		mp->AddExit( 27 );
	};
}