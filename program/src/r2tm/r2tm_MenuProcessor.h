#pragma once

#include <string_view>
#include <vector>

#include "r2tm_Color.h"
#include "r2tm_MenuConstant.h"

namespace r2tm
{
	class Director;
	class iItem;
	class iMenu;

	class MenuProcessor
	{
	private:
		struct ItemInfo
		{
			ItemInfo(
				const char key_code
				, const r2tm::eColor message_color_code
				, const r2tm::eColor background_color_code
				, const TitleFunctionT& title_function
				, const DoFunctionT& do_function
			) :
				KeyCode( key_code )
				, MessageColorCode( message_color_code )
				, BackgroundColorCode( background_color_code )
				, TitleFunction( title_function )
				, DoFunction( do_function )
			{}

			char KeyCode;
			r2tm::eColor MessageColorCode;
			r2tm::eColor BackgroundColorCode;
			TitleFunctionT TitleFunction;
			DoFunctionT DoFunction;
		};

		using ItemContainerT = std::vector<ItemInfo>;



	public:
		MenuProcessor( Director& director );



		//
		//
		//
		void ShowTitle() const;
		void ShowDescription() const;
		void ShowItems() const;

		eDoLeaveAction Do( const int key_code );



		//
		//
		//
		void Reset( const TitleFunctionT& title_function, const DescriptionFunctionT& description_function, const WriteFunctionT& write_function );



		//
		//
		//
		void AddItem( const char key_code, const r2tm::eColor message_color_code, const r2tm::eColor background_color_code, const TitleFunctionT& func_title, const DoFunctionT& func_do );
		void AddItem( const char key_code, const r2tm::eColor message_color_code, const TitleFunctionT& func_title, const DoFunctionT& func_do );
		void AddItem( const char key_code, const TitleFunctionT& func_title, const DoFunctionT& func_do );
		void AddItem( const char key_code, const iItem& item_obj );

		void AddExit( const char key_code, const r2tm::eColor message_color_code, const r2tm::eColor background_color_code );
		void AddExit( const char key_code, const r2tm::eColor message_color_code );
		void AddExit( const char key_code );

		void AddMenu( const char key_code, const iMenu& menu_obj );

		void AddLineFeed();
		void AddSplit();

		void AddMessage( const char* const message, const r2tm::eColor message_color_code, const r2tm::eColor background_color_code );
		void AddMessage( const char* const message, const r2tm::eColor message_color_code );
		void AddMessage( const char* const message );



	protected:
		Director& mDirector;
		std::string_view mTitleString;
		std::string_view mDescriptionString;

		ItemContainerT mItemContainer;
	};
}