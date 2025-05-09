#include "test_color_modifier.h"

#include "r2tm/r2tm_ColorModifier.h"
#include "r2tm/r2tm_Inspector.h"
#include "r2tm/r2tm_ostream.h"


namespace test_color_modifier
{
	std::ostream& operator<<( std::ostream& os, const r2tm::eColor& color )
	{
		return os << static_cast<int>( color );
	}

	r2tm::TitleFunctionT Declaration::GetTitleFunction() const
	{
		return []()->const char*
		{
			return "Declaration";
		};
	}
	r2tm::DoFunctionT Declaration::GetDoFunction() const
	{
		return []()->r2tm::eDoLeaveAction
		{
			LS();

			{
				DECLARATION_MAIN( r2tm::ColorModifier clm );

				LF();

				EXPECT_EQ( r2tm::eColor::None, clm.GetColor() );
				OUTPUT_VALUE( clm.GetColor() );

				LF();

				OUTPUT_SIZE( clm );
			}

			LS();

			return r2tm::eDoLeaveAction::Pause;
		};
	}



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