#include "test_window_utility.h"

#include <conio.h> // _kbhit(), _getch()

#include "r2tm/r2tm_Inspector.h"
#include "r2tm/r2tm_ostream.h"
#include "r2tm/r2tm_WindowUtility.h"

namespace test_window_utility
{
	r2tm::TitleFunctionT CursorPointOperator::GetTitleFunction() const
	{
		return []()->const char*
		{
			return "WIndow Utility : CursorPoint - Operator";
		};
	}
	r2tm::DoFunctionT CursorPointOperator::GetDoFunction() const
	{
		return []()->r2tm::eDoLeaveAction
		{
			LS();

			{
				OUTPUT_SUBJECT( "Operator +" );

				LF();

				DECLARATION_MAIN( r2tm::WindowUtility::CursorPoint p );

				LF();

				PROCESS_MAIN( p = p + r2tm::WindowUtility::CursorPoint( 2, 4 ) );

				LF();

				EXPECT_EQ( 2, p.x );
				EXPECT_EQ( 4, p.y );
			}
			
			LS();

			{
				OUTPUT_SUBJECT( "Operator +=" );

				LF();

				DECLARATION_MAIN( r2tm::WindowUtility::CursorPoint p );

				LF();

				PROCESS_MAIN( p += r2tm::WindowUtility::CursorPoint( 2, 4 ) );

				LF();

				EXPECT_EQ( 2, p.x );
				EXPECT_EQ( 4, p.y );
			}

			LS();

			return r2tm::eDoLeaveAction::Pause;
		};
	}



	r2tm::TitleFunctionT MoveCursorWithClearBuffer::GetTitleFunction() const
	{
		return []()->const char*
		{
			return "WIndow Utility : Move Cursor With Clear Buffer";
		};
	}
	r2tm::DoFunctionT MoveCursorWithClearBuffer::GetDoFunction() const
	{
		return []()->r2tm::eDoLeaveAction
		{
			LS();

			DECLARATION_MAIN( const auto cursor_point_1 = r2tm::WindowUtility::GetCursorPoint() );

			LS();

			{
				std::cout << "ddddddddddddddddduuuuuuuuuuummmmmmmmmmmyyyyyyyyyyyyyyyyyy" << r2tm::linefeed;
				std::cout << "ddddddddddddddddduuuuuuuuuuummmmmmmmmmmyyyyyyyyyyyyyyyyyy" << r2tm::linefeed;
			}

			LS();

			DECLARATION_MAIN( const auto cursor_point_2 = r2tm::WindowUtility::GetCursorPoint() );

			LS();

			for( int i = 0; 20 > i; ++i )
			{
				std::cout << "ddddddddddddddddduuuuuuuuuuummmmmmmmmmmyyyyyyyyyyyyyyyyyy" << r2tm::linefeed;
			}

			LS();

			std::cout << "[Any Key] Move Cursor 2 with Clear Buffer";
			_getch();

			PROCESS_MAIN( r2tm::WindowUtility::MoveCursorPointWithClearBuffer( cursor_point_2 ) );

			std::cout << "[Any Key] Move Cursor 1 with Clear Buffer";
			_getch();

			PROCESS_MAIN( r2tm::WindowUtility::MoveCursorPointWithClearBuffer( cursor_point_1.x, cursor_point_1.y ) );

			std::cout << "[Any Key] End";
			_getch();

			return r2tm::eDoLeaveAction::None;
		};
	}



	r2tm::TitleFunctionT FillColor::GetTitleFunction() const
	{
		return []()->const char*
		{
			return "WIndow Utility : FillColor";
		};
	}
	r2tm::DoFunctionT FillColor::GetDoFunction() const
	{
		return []()->r2tm::eDoLeaveAction
		{
			LS();

			{
				OUTPUT_SUBJECT( "한 칸에 색 채우기" );

				LF();

				r2tm::WindowUtility::FillColor( r2tm::WindowUtility::GetCursorPoint(), r2tm::WindowUtility::eColor::BG_Aqua );
				r2tm::WindowUtility::FillColor( r2tm::WindowUtility::GetCursorPoint() + r2tm::WindowUtility::CursorPoint{ 1, 0 }, r2tm::WindowUtility::eColor::BG_Green );
				r2tm::WindowUtility::FillColor( r2tm::WindowUtility::GetCursorPoint() + r2tm::WindowUtility::CursorPoint{ 2, 0 }, ( r2tm::WindowUtility::eColor::FG_Blue | r2tm::WindowUtility::eColor::BG_LightYellow ) );
				r2tm::WindowUtility::FillColor( r2tm::WindowUtility::GetCursorPoint() + r2tm::WindowUtility::CursorPoint{ 3, 0 }, ( r2tm::WindowUtility::eColor::FG_Green | r2tm::WindowUtility::eColor::BG_LightRed ) );

				//
				// Cursor Setup
				//
				r2tm::WindowUtility::MoveCursorPointWithClearBuffer( r2tm::WindowUtility::GetCursorPoint() + r2tm::WindowUtility::CursorPoint{ 0, 1 } );
			}

			LS();

			{
				OUTPUT_SUBJECT( "지정된 길이 만큼 색 채우기" );

				LF();

				r2tm::WindowUtility::FillColor( r2tm::WindowUtility::GetCursorPoint() + r2tm::WindowUtility::CursorPoint{ 0, 0 }, r2tm::WindowUtility::eColor::BG_Aqua, 4 );
				r2tm::WindowUtility::FillColor( r2tm::WindowUtility::GetCursorPoint() + r2tm::WindowUtility::CursorPoint{ 1, 1 }, r2tm::WindowUtility::eColor::BG_Green, 4 );
				r2tm::WindowUtility::FillColor( r2tm::WindowUtility::GetCursorPoint() + r2tm::WindowUtility::CursorPoint{ 2, 2 }, ( r2tm::WindowUtility::eColor::FG_Blue | r2tm::WindowUtility::eColor::BG_LightYellow ), 4 );
				r2tm::WindowUtility::FillColor( r2tm::WindowUtility::GetCursorPoint() + r2tm::WindowUtility::CursorPoint{ 3, 3 }, ( r2tm::WindowUtility::eColor::FG_Green | r2tm::WindowUtility::eColor::BG_LightRed ), 4 );

				//
				// Cursor Setup
				//
				r2tm::WindowUtility::MoveCursorPointWithClearBuffer( r2tm::WindowUtility::GetCursorPoint() + r2tm::WindowUtility::CursorPoint{ 0, 4 } );
			}

			LS();

			return r2tm::eDoLeaveAction::Pause;
		};
	}



	r2tm::TitleFunctionT FillCharacter::GetTitleFunction() const
	{
		return []()->const char*
		{
			return "WIndow Utility : FillCharacter";
		};
	}
	r2tm::DoFunctionT FillCharacter::GetDoFunction() const
	{
		return []()->r2tm::eDoLeaveAction
		{
			LS();

			{
				OUTPUT_SUBJECT( "한 칸에 글자/색 채우기" );

				LF();

				r2tm::WindowUtility::FillCharacter( r2tm::WindowUtility::GetCursorPoint() + r2tm::WindowUtility::CursorPoint{ 0, 0 }, 'T', r2tm::WindowUtility::eColor::BG_Green );
				r2tm::WindowUtility::FillCharacter( r2tm::WindowUtility::GetCursorPoint() + r2tm::WindowUtility::CursorPoint{ 1, 1 }, 'E', r2tm::WindowUtility::eColor::BG_Aqua );
				r2tm::WindowUtility::FillCharacter( r2tm::WindowUtility::GetCursorPoint() + r2tm::WindowUtility::CursorPoint{ 2, 2 }, 'S', ( r2tm::WindowUtility::eColor::FG_Green | r2tm::WindowUtility::eColor::BG_LightRed ) );
				r2tm::WindowUtility::FillCharacter( r2tm::WindowUtility::GetCursorPoint() + r2tm::WindowUtility::CursorPoint{ 3, 3 }, 'T', ( r2tm::WindowUtility::eColor::FG_Blue | r2tm::WindowUtility::eColor::BG_LightYellow ) );

				//
				// Cursor Setup
				//
				r2tm::WindowUtility::MoveCursorPointWithClearBuffer( r2tm::WindowUtility::GetCursorPoint() + r2tm::WindowUtility::CursorPoint{ 0, 4 } );
			}

			LS();

			return r2tm::eDoLeaveAction::Pause;
		};
	}



	r2tm::TitleFunctionT FillString::GetTitleFunction() const
	{
		return []()->const char*
		{
			return "WIndow Utility : FillString";
		};
	}
	r2tm::DoFunctionT FillString::GetDoFunction() const
	{
		return []()->r2tm::eDoLeaveAction
		{
			LS();

			DECLARATION_MAIN( using P = r2tm::WindowUtility::CursorPoint; );

			LS();

			{
				OUTPUT_SUBJECT( "문자열 출력" );

				LF();

				PROCESS_MAIN( r2tm::WindowUtility::FillString( r2tm::WindowUtility::GetCursorPoint(), "asdfgh", 6 ) );

				LF();
			}

			LS();

			{
				OUTPUT_SUBJECT( "문자열, Offset" );

				LF();

				DECLARATION_MAIN( auto cursor_point = ( r2tm::WindowUtility::GetCursorPoint() + P{ 4, 5 } ) );
				PROCESS_MAIN( r2tm::WindowUtility::FillString( cursor_point, "asdfgh", 4 ) );

				r2tm::WindowUtility::MoveCursorPoint( cursor_point.x, cursor_point.y + 1 );
			}

			LS();

			{
				OUTPUT_SUBJECT( "문자열, Offset, 색상" );

				LF();

				DECLARATION_MAIN( auto cursor_point = ( r2tm::WindowUtility::GetCursorPoint() + P{ 4, 5 } ) );
				PROCESS_MAIN( r2tm::WindowUtility::FillString( cursor_point, "asdfgh", 4, r2tm::WindowUtility::eColor::BG_LightGreen ) );

				r2tm::WindowUtility::MoveCursorPoint( cursor_point.x, cursor_point.y + 1 );
			}

			LS();

			{
				OUTPUT_SUBJECT( "한 문자를 여러개 찍기" );

				LF();

				DECLARATION_MAIN( auto cursor_point = ( r2tm::WindowUtility::GetCursorPoint() + P{ 4, 5 } ) );
				PROCESS_MAIN( r2tm::WindowUtility::FillString( cursor_point, 'z', 10 ) );

				r2tm::WindowUtility::MoveCursorPoint( cursor_point.x, cursor_point.y + 1 );
			}

			LS();

			{
				OUTPUT_SUBJECT( "한 문자를 색상을 넣어 여러개 찍기" );

				LF();

				DECLARATION_MAIN( auto cursor_point = ( r2tm::WindowUtility::GetCursorPoint() + P{ 4, 5 } ) );
				PROCESS_MAIN( r2tm::WindowUtility::FillString( cursor_point, 'z', 10, r2tm::WindowUtility::eColor::BG_LightGreen ) );

				r2tm::WindowUtility::MoveCursorPoint( cursor_point.x, cursor_point.y + 1 );
			}

			LS();

			return r2tm::eDoLeaveAction::Pause;
		};
	}
}