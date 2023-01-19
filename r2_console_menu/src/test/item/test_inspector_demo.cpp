#include "test_inspector_demo.h"

#include "r2cm/r2cm_Inspector.h"
#include "r2cm/r2cm_ostream.h"

namespace test_inspector_demo
{
	r2cm::TitleFunctionT Demo::GetTitleFunction() const
	{
		return []()->const char*
		{
			return "Inspector : Demo";
		};
	}
	r2cm::DoFunctionT Demo::GetDoFunction() const
	{
		return []()->r2cm::eDoLeaveAction
		{
			std::cout << r2cm::split;

			{
				DECLARATION_MAIN( int i = 0 );
				DECLARATION_MAIN( int j = i );
				EXPECT_EQ( i, j );
				PROCESS_MAIN( i = 1 );
				PROCESS_MAIN( i = 2 );
				EXPECT_NE( i, 1 );
				EXPECT_EQ( i, 2 );
			}

			std::cout << r2cm::split;

			return r2cm::eDoLeaveAction::Pause;
		};
	}
}