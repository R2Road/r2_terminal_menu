#include "menu_inspector_file.hpp"

#include "r2tm/r2tm_menu_processor.hpp"

#include "test_inspector_file.hpp"
#include "test_inspector_source.hpp"

#include "menu_dev.hpp"

r2tm::TitleFunctionT Menu_Inspector_File::GetTitleFunction() const
{
	return []()->const char*
	{
		return "Menu : Inspector : File";
	};
}
r2tm::DescriptionFunctionT Menu_Inspector_File::GetDescriptionFunction() const
{
	return []()->const char*
	{
		return "";
	};
}
r2tm::WriteFunctionT Menu_Inspector_File::GetWriteFunction() const
{
	return []( r2tm::MenuProcessor* mp )
	{
		mp->AddItem( '1', test_inspector_file::File_1() );
		mp->AddItem( '2', test_inspector_file::File_2() );
		mp->AddItem( '3', test_inspector_file::File_3() );
		mp->AddItem( '4', test_inspector_file::Out_File_Current_Directory() );



		mp->AddLineFeed();



		mp->AddItem( 'q', test_inspector_file::FileRange_1() );
		mp->AddItem( 'w', test_inspector_file::FileRange_2() );
		mp->AddItem( 'e', test_inspector_file::FileRange_3() );
		mp->AddItem( 'r', test_inspector_file::Out_File_Range_Current_Directory() );



		mp->AddLineFeed();



		mp->AddItem( 'a', test_inspector_file::DirectoryOpen() );
		mp->AddItem( 's', test_inspector_source::Basic() );



		mp->AddSplit();



		mp->AddMenu( 27, Menu_Dev() );
	};
}