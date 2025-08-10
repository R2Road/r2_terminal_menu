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

#include "menu_root.hpp"

r2tm::TitleFunctionT Menu_Portfolio::GetTitleFunction() const
{
	return []()->const char*
	{
		static const std::string ret =
			std::string()

			+ "Portfolio"
			  " : "	"<"   "C++17" + ">"
			  ", "	"<"   "MS C/C++ : " + std::to_string( _MSC_VER ) + ">"
			  ", "	"<" + r2tm::VersionInfo.String4Version + ">"
			;
		return ret.c_str();
	};
}
r2tm::DescriptionFunctionT Menu_Portfolio::GetDescriptionFunction() const
{
	return []()->const char*
	{
		return (
			     "�ֿ� �ڵ�� ������Ʈ�� r2tm ���� �ȿ� �ֽ��ϴ�."
			"\n"
			"\n" "�ڵ��� ����� �׽�Ʈ �ϰ� ������ �α׸� ������ֱ� ���� ���� �Դϴ�."
			"\n" "���� ���� �͹̳� ��� ������Ʈ���� �� �ڵ���� �׻� ���Դϴ�."
		);
	};
}
r2tm::WriteFunctionT Menu_Portfolio::GetWriteFunction() const
{
	return []( r2tm::MenuProcessor* mp )
	{
		mp->AddMessage( "�� ������Ʈ �Ϸ��� ���� ������ �˾� ������ �Ʒ� Demo�� ���ϴ�.", r2tm::eColor::FG_Yellow );
		mp->AddItem( '1', test_inspector_demo::Demo_1() );
		mp->AddItem( '2', test_inspector_demo::Demo_2() );



		mp->AddLineFeed();
		mp->AddLineFeed();



		mp->AddMessage( "�� ���� �����ϴ� Inspector�� ��� �׽�Ʈ �Դϴ�.", r2tm::eColor::FG_Yellow );
		mp->AddItem( 'q', test_inspector_base::Basic() );
		mp->AddItem( 'w', test_inspector_base::Expect_1() );
		mp->AddItem( 'e', test_inspector_base::Expect_2() );
		mp->AddItem( 'r', test_inspector_base::Size() );
		mp->AddItem( 't', test_inspector_base::Code() );
		mp->AddItem( 'y', test_inspector_base::Address() );
		mp->AddItem( 'u', test_inspector_base::String_Note_Subject_Comment() );



		mp->AddLineFeed();



		mp->AddItem( 'a', test_inspector_binary::Binary() );
		mp->AddItem( 's', test_inspector_binary::Binaries_1() );
		mp->AddItem( 'd', test_inspector_binary::Binaries_2() );
		mp->AddItem( 'f', test_inspector_input::Wait_Any_Key() );
		mp->AddItem( 'g', test_inspector_input::GetKey() );
		mp->AddItem( 'h', test_inspector_input::Keyboard_Hit() );



		mp->AddLineFeed();



		mp->AddItem( 'z', test_inspector_file::File_1() );
		mp->AddItem( 'x', test_inspector_file::File_2() );
		mp->AddItem( 'c', test_inspector_file::FileRange_1() );
		mp->AddItem( 'v', test_inspector_file::FileRange_2() );
		mp->AddItem( 'b', test_inspector_file::FileRange_3() );
		mp->AddItem( 'n', test_inspector_source::Basic() );



		mp->AddLineFeed();
		mp->AddLineFeed();



		mp->AddMessage( "�� ������Ʈ�� ���� Root Menu�� �̵��մϴ�. ��Ʈ������ �޴��� ���ƿ� �� �����ϴ�.", r2tm::eColor::FG_Yellow );
		mp->AddMenu( 32, Menu_Root() );
		



		mp->AddSplit();



		mp->AddExit( 27 );
	};
}