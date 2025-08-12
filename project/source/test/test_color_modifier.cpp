#include "test_color_modifier.hpp"

#include "r2tm/r2tm_color_modifier.hpp"
#include "r2tm/r2tm_inspector.hpp"
#include "r2tm/r2tm_ostream.hpp"


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
				OUTPUT_SUBJECT( "크기" );

				LF();

				OUTPUT_SIZE( r2tm::ColorModifier{} );
			}

			LS();

			{
				OUTPUT_SUBJECT( "바이너리" );

				LF();

				OUTPUT_BINARY( r2tm::ColorModifier{} );
			}

			LS();

			{
				OUTPUT_SUBJECT( "기본 생성자" );

				LF();

				DECL_MAIN( r2tm::ColorModifier cm );

				LF();

				EXPECT_EQ( r2tm::ColorModifier::DEFAULT_COLOR, cm.GetColor() );
				OUTPUT_VALUE( cm.GetColor() );

				LF();

				OUTPUT_BINARY( cm );
			}

			LS();

			{
				OUTPUT_SUBJECT( "인자가 있는 생성자" );

				LF();

				DECL_MAIN( r2tm::eColor c( r2tm::eColor::FG_LightAqua ) );
				DECL_MAIN( r2tm::ColorModifier cm( c ) );

				LF();

				EXPECT_EQ( c, cm.GetColor() );
				OUTPUT_VALUE( cm.GetColor() );

				LF();

				OUTPUT_BINARY( cm );
			}

			LS();

			return r2tm::eDoLeaveAction::Pause;
		};
	}



	r2tm::TitleFunctionT Test::GetTitleFunction() const
	{
		return []()->const char*
		{
			return "Test";
		};
	}
	r2tm::DoFunctionT Test::GetDoFunction() const
	{
		return []()->r2tm::eDoLeaveAction
		{
			LS();

			{
				OUTPUT_SUBJECT( "Empty" );

				LF();

				PROC_MAIN( std::cout << "  " << r2tm::ColorModifier() << "Do Something" << r2tm::ColorModifier() << r2tm::linefeed );
			}

			LS();

			{
				OUTPUT_SUBJECT( "None" );

				LF();

				PROC_MAIN( std::cout << "  " << r2tm::ColorModifier( r2tm::eColor::None ) << "Do Something" << r2tm::ColorModifier() << r2tm::linefeed );
			}

			LS();

			{
				OUTPUT_SUBJECT( "글자색 지정" );

				LF();

				PROC_MAIN( std::cout << "  " << r2tm::ColorModifier( r2tm::eColor::FG_Red ) << "Do Something" << r2tm::ColorModifier() << r2tm::linefeed );
			}

			LS();

			{
				OUTPUT_SUBJECT( "r2tm::ColorModifier 대신에 줄임 표현인 clm 사용 가능" );

				LF();

				PROC_MAIN( std::cout << "  " << clm( r2tm::eColor::FG_Red ) << "Do Something" << clm() << r2tm::linefeed );
			}

			LS();

			{
				OUTPUT_SUBJECT( "글자색 + 배경색 지정" );

				LF();

				PROC_MAIN( std::cout << "  " << clm( r2tm::eColor::BG_Red ) << clm( r2tm::eColor::FG_Blue ) << "Do Something" << clm() << r2tm::linefeed );
			}

			LS();

			return r2tm::eDoLeaveAction::Pause;
		};
	}
}