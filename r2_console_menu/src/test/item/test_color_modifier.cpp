#include "test_color_modifier.h"

#include "r2cm/r2cm_Inspector.h"
#include "r2cm/r2cm_ostream.h"

namespace test_color_modifier
{
	r2cm::TitleFunctionT Basic::GetTitleFunction() const
	{
		return []()->const char*
		{
			return "Color Modifier : Basic";
		};
	}
	r2cm::DoFunctionT Basic::GetDoFunction() const
	{
		return []()->r2cm::eDoLeaveAction
		{
			LS();

			{
				OUTPUT_NOTE( "None" );

				LF();

				PROCESS_MAIN( std::cout << r2cm::tab2 << r2cm::ColorModifier( r2cm::eColor::None ) << "Do Something" << r2cm::ColorModifier() << r2cm::linefeed );
			}

			LS();

			{
				OUTPUT_NOTE( "Setup" );

				LF();

				PROCESS_MAIN( std::cout << r2cm::tab2 << r2cm::ColorModifier( r2cm::eColor::FG_Red ) << "Do Something" << r2cm::ColorModifier() << r2cm::linefeed );

				LF();

				PROCESS_MAIN( std::cout << r2cm::tab2 << clm( r2cm::eColor::BG_Red ) << clm( r2cm::eColor::FG_Blue ) << "Do Something" << clm() << r2cm::linefeed );
			}

			LS();

			return r2cm::eDoLeaveAction::Pause;
		};
	}
}