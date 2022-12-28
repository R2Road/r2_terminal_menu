#include "r2cm_Director.h"

#include <conio.h>

#include "r2cm_iMenuWriter.h"

namespace r2cm
{
	Director::Director() : mMenu( *this )
	{}

	void Director::Setup( const iMenuWriter& menu_writer )
	{
		mMenu.Reset( menu_writer.GetTitleFunction(), menu_writer.GetDescriptionFunction(), menu_writer.GetWriteFunction() );
	}

	void Director::Run()
	{
		int input = 0;
		while( true )
		{
			system( "cls" );

			mMenu.ShowTitle();
			mMenu.ShowDescription();
			mMenu.ShowItems();
			input = _getch();

			system( "cls" );

			switch( mMenu.Do( input ) )
			{
			//case eDoLeaveAction::None: break;

			case eDoLeaveAction::Pause:
				system( "pause" );				
				break;

			case eDoLeaveAction::Exit:
				return;
			}
		}
	}
}