#pragma once

#include <memory>

namespace r2cm
{
	class Director;
	using MenuUp = std::unique_ptr<class Menu>;
}

class InspectorMenu
{
private:
	InspectorMenu() = delete;

public:
	static const char* GetTitle() { return "Inspector Menu"; }
	static r2cm::MenuUp Create( r2cm::Director& director );
};