#include "r2cm_Director.h"

#include <conio.h>

#include "r2cm_iMenuWriter.h"

namespace r2cm
{
	Director::Director() : mMenuProcessor( *this )
	{}

	void Director::Setup( const iMenu& menu_writer )
	{
		mMenuProcessor.Reset( menu_writer.GetTitleFunction(), menu_writer.GetDescriptionFunction(), menu_writer.GetWriteFunction() );
	}

	void Director::Run()
	{
		int input = 0;
		while( true )
		{
			system( "cls" );

			mMenuProcessor.ShowTitle();
			mMenuProcessor.ShowDescription();
			mMenuProcessor.ShowItems();
			input = _getch();

			system( "cls" );

			switch( mMenuProcessor.Do( input ) )
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