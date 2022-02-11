#include "pch.h"
#include "r2_Director.h"

#include <conio.h>
#include <utility>

#include "r2_eTestResult.h"

namespace r2
{
	Director::Director() : mMenu()
	{}

	void Director::Setup( MenuUp menu )
	{
		mMenu = std::move( menu );
	}

	void Director::Update()
	{
		int input = 0;
		while( true )
		{
			mMenu->ShowTitle();
			mMenu->ShowDescription();
			mMenu->ShowMenu();
			input = _getch();

			system( "cls" );

			switch( mMenu->Do( input ) )
			{
			case eTestEndAction::Pause:
				std::cout << r2::linefeed;
				system( "pause" );

				system( "cls" );
				break;

			case eTestEndAction::None:
				system( "cls" );
				break;

			//case eTestEndAction::ChangeScene:
				//break;

			case eTestEndAction::Exit:
				return;
			}
		}
	}
}