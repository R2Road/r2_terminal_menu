#include "test_color_modifier.h"

#include "r2tm/r2tm_ColorModifier.h"
#include "r2tm/r2tm_Inspector.h"
#include "r2tm/r2tm_ostream.h"

namespace test_color_modifier
{
	r2tm::TitleFunctionT Basic::GetTitleFunction() const
	{
		return []()->const char*
		{
			return "Color Modifier";
		};
	}
	r2tm::DoFunctionT Basic::GetDoFunction() const
	{
		return []()->r2tm::eDoLeaveAction
		{
			LS();

			{
				OUTPUT_SUBJECT( "None" );

				LF();

				PROCESS_MAIN( std::cout << "  " << r2tm::ColorModifier( r2tm::eColor::None ) << "Do Something" << r2tm::ColorModifier() << r2tm::linefeed );
			}

			LS();

			{
				OUTPUT_SUBJECT( "Setup 1" );

				LF();

				PROCESS_MAIN( std::cout << "  " << r2tm::ColorModifier( r2tm::eColor::FG_Red ) << "Do Something" << r2tm::ColorModifier() << r2tm::linefeed );
			}

			LS();

			{
				OUTPUT_SUBJECT( "Setup 2" );

				LF();

				PROCESS_MAIN( std::cout << "  " << clm( r2tm::eColor::BG_Red ) << clm( r2tm::eColor::FG_Blue ) << "Do Something" << clm() << r2tm::linefeed );
			}

			LS();

			return r2tm::eDoLeaveAction::Pause;
		};
	}
}