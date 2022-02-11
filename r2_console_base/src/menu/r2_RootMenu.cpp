#include "pch.h"
#include "r2_RootMenu.h"

#include "base/r2_Director.h"
#include "base/r2_eTestResult.h"

#include "menu/r2_InputMenu.h"

#include "test/base_test.h"
#include "test/key_test.h"

namespace r2
{
	MenuUp RootMenu::Create( Director& director )
	{
		MenuUp ret( new ( std::nothrow ) Menu(
			director
			, GetTitle(),
					"> Inprogress : BlaBla"
			"\n"	"> To do : BlaBla"
			"\n"	"> To do : BlaBla"
			"\n"	"> To do : BlaBla"
		) );

		{
			ret->AddChild( '1', base_test::RunTest_And_Pause::GetInstance() );
			ret->AddChild( '2', base_test::RunTest_Without_Pause::GetInstance() );

			ret->AddLineFeed();

			ret->AddChild( 'q', key_test::Basic::GetInstance() );
			ret->AddChild(
				'w'
				, []()->const char* { return r2::InputMenu::GetTitle(); }
				, [&director]()->eTestResult
				{
					director.Setup( r2::InputMenu::Create( director ) );
					return eTestResult::ChangeScene;
				}
			);


			ret->AddSplit();


			ret->AddChild(
				27
				, []()->const char* { return "Exit"; }
				, []()->eTestResult { return eTestResult::Exit; }
			);
		}

		return ret;
	}
}