#include "r2cm_Menu.h"

#include <cctype> // std::toupper

#include "r2cm_iItem.h"
#include "r2cm_iMenuWriter.h"
#include "r2cm_ostream.h"


namespace
{
	const char KeyCode4LineFeed = '@';
	const char KeyCode4Split = '*';
	const char KeyCode4Message = '(';
}

namespace r2cm
{
	Menu::Menu( Director& director ) :
		mDirector( director )
		, mTitleString( "" )
		, mDescriptionString( "" )
		, mItemContainer()
	{}

	void Menu::ShowTitle() const
	{
		std::cout << "# " << mTitleString << " #" << r2cm::linefeed;
		std::cout << r2cm::split;
	}
	void Menu::ShowDescription() const
	{
		if( !mDescriptionString.empty() )
		{
			std::cout << "+ Message" << r2cm::linefeed2;
			
			std::cout << clm( r2cm::eColor::FG_LightGreen ) << mDescriptionString << clm() << r2cm::linefeed;

			std::cout << r2cm::split;
		}
	}

	void Menu::ShowItems() const
	{
		std::cout << "+ Menu" << r2cm::linefeed2;

		for( const auto t : mItemContainer )
		{
			//
			// Function Key
			//
			if( KeyCode4Split == t.KeyCode ) // *
			{
				std::cout << r2cm::split;
				continue;
			}
			if( KeyCode4LineFeed == t.KeyCode ) // @
			{
				std::cout << r2cm::linefeed;
				continue;
			}
			if( KeyCode4Message == t.KeyCode ) // (
			{
				std::cout << t.TitleFunction() << r2cm::linefeed;
				continue;
			}

			//
			// Key
			//
			std::cout << "[";

			if( 27 == t.KeyCode ) // ESC
			{
				std::cout << "ESC";
			}
			else if( 32 == t.KeyCode ) // SPACE_BAR
			{
				std::cout << "SPACE";
			}
			else
			{
				std::cout << static_cast<char>( std::toupper( t.KeyCode ) );
			}

			std::cout << "] ";
			
			//
			// Title
			//
			std::cout << clm( static_cast<r2cm::eColor>( t.ColorCode ) ) << t.TitleFunction() << clm() << r2cm::linefeed;
		}

		std::cout << r2cm::split << "Select Menu";
	}

	eDoLeaveAction Menu::Do( const int key_code )
	{
		for( const auto& i : mItemContainer )
		{
			if( key_code == i.KeyCode )
			{
				std::cout << "# " << i.TitleFunction() << " #" << r2cm::linefeed;

				//
				// # 2022.12.25 by R
				//
				// i.DoFunction 의 내부에서 Menu 변경을 위해 mItemContainer.clear() 를 호출하는경우
				// 작동중인 lambda 가 날아가면서 함수 내부의 capture 변수들이 날아가고 잘못된 메모리 참조로 터진다.
				//
				// 위와 같은 문제의 해결을 위해 lambda 를 복사하여 사용한다.
				//
				// 다른 해결책이 있을까?
				//
				auto do_func = i.DoFunction;
				return do_func();
			}
		}

		return eDoLeaveAction::Pause;
	}

	void Menu::Reset( const TitleFunctionT& title_function, const DescriptionFunctionT& description_function, const WriteFunctionT& write_function )
	{
		mTitleString = title_function();
		mDescriptionString = description_function();

		mItemContainer.clear();
		write_function( this );
	}

	void Menu::AddItem( const char key_code, const int color_code, const r2cm::TitleFunctionT& func_title, const r2cm::DoFunctionT& func_do )
	{
		mItemContainer.emplace_back( key_code, color_code, func_title, func_do );
	}
	void Menu::AddItem( const char key_code, const r2cm::TitleFunctionT& func_title, const r2cm::DoFunctionT& func_do )
	{
		mItemContainer.emplace_back( key_code, r2cm::eColor::FG_White, func_title, func_do );
	}
	void Menu::AddItem( const char key_code, const iItem& item_obj )
	{
		AddItem( key_code, r2cm::eColor::FG_White, item_obj.GetTitleFunction(), item_obj.GetDoFunction() );
	}

	void Menu::AddMenu( const char key_code, const iMenuWriter& menu_obj )
	{
		AddItem( key_code, r2cm::eColor::FG_Aqua, menu_obj.GetTitleFunction(),
			[
			this
			, &m = *this
			, t = menu_obj.GetTitleFunction()
			, d = menu_obj.GetDescriptionFunction()
			, w = menu_obj.GetWriteFunction()
			]()->r2cm::eDoLeaveAction
		{
			mTitleString = t();
			mDescriptionString = d();

			mItemContainer.clear();
			w( &m );

			return r2cm::eDoLeaveAction::None;
		} );
	}

	void Menu::AddLineFeed()
	{
		static const r2cm::TitleFunctionT func_title = []()->const char* { return ""; };
		static const r2cm::DoFunctionT func_do = []()->const r2cm::eDoLeaveAction { return r2cm::eDoLeaveAction::Pause; };

		AddItem( KeyCode4LineFeed, r2cm::eColor::FG_White, func_title, func_do );
	}
	void Menu::AddSplit()
	{
		static const r2cm::TitleFunctionT func_title = []()->const char* { return ""; };
		static const r2cm::DoFunctionT func_do = []()->const r2cm::eDoLeaveAction { return r2cm::eDoLeaveAction::Pause; };

		AddItem( KeyCode4Split, r2cm::eColor::FG_White, func_title, func_do );
	}
	void Menu::AddMessage( const char* const message )
	{
		const r2cm::TitleFunctionT func_title = [message]()->const char* { return message; };
		static const r2cm::DoFunctionT func_do = []()->const r2cm::eDoLeaveAction { return r2cm::eDoLeaveAction::Pause; };

		AddItem( KeyCode4Message, r2cm::eColor::FG_White, func_title, func_do );
	}
}