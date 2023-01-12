#include "color_modifier_test.h"

#include "r2cm/r2cm_Inspector.h"
#include "r2cm/r2cm_ostream.h"

namespace color_modifier_test
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
			r2cm_split;

			{
				OUTPUT_NOTE( "None" );

				r2cm_lf;

				PROCESS_MAIN( std::cout << r2cm::tab2 << r2cm::ColorModifier( r2cm::eColor::None ) << "Do Something" << r2cm::ColorModifier() << r2cm::linefeed );
			}

			r2cm_split;

			{
				OUTPUT_NOTE( "Setup" );

				r2cm_lf;

				PROCESS_MAIN( std::cout << r2cm::tab2 << r2cm::ColorModifier( r2cm::eColor::FG_Red ) << "Do Something" << r2cm::ColorModifier() << r2cm::linefeed );

				r2cm_lf;

				PROCESS_MAIN( std::cout << r2cm::tab2 << clm( r2cm::eColor::BG_Red ) << clm( r2cm::eColor::FG_Blue ) << "Do Something" << clm() << r2cm::linefeed );
			}

			r2cm_split;

			return r2cm::eDoLeaveAction::Pause;
		};
	}
}