#pragma once

#include "r2cm_ColorModifier.h"

namespace r2cm
{
	template<class _Elem, class _Traits>
	inline std::basic_ostream<_Elem, _Traits>& linefeed( std::basic_ostream<_Elem, _Traits>& os )
	{
		// insert newline
		return os.put( os.widen( '\n' ) );
	}

	template<class _Elem, class _Traits>
	inline std::basic_ostream<_Elem, _Traits>& linefeed2( std::basic_ostream<_Elem, _Traits>& os )
	{
		return os << r2cm::linefeed << r2cm::linefeed;
	}

	template<class _Elem, class _Traits>
	inline std::basic_ostream<_Elem, _Traits>& linefeed3( std::basic_ostream<_Elem, _Traits>& os )
	{
		return os << r2cm::linefeed << r2cm::linefeed << r2cm::linefeed;
	}



	template<class _Elem, class _Traits>
	inline std::basic_ostream<_Elem, _Traits>& split( std::basic_ostream<_Elem, _Traits>& os )
	{
		return os << r2cm::linefeed << "==========" "==========" "==========" "==========" "==========" "==========" "========" << r2cm::linefeed << r2cm::linefeed;
	}



	template<class _Elem, class _Traits>
	inline std::basic_ostream<_Elem, _Traits>& softsplit( std::basic_ostream<_Elem, _Traits>& os )
	{
		return os << r2cm::linefeed << "    " "----------" "----------" "----------" "----------" "----------" "----------" << r2cm::linefeed << r2cm::linefeed;
	}



	template<class _Elem, class _Traits>
	inline std::basic_ostream<_Elem, _Traits>& tab( std::basic_ostream<_Elem, _Traits>& os )
	{
		return os.put( os.widen( '\t' ) );
	}

	template<class _Elem, class _Traits>
	inline std::basic_ostream<_Elem, _Traits>& tab2( std::basic_ostream<_Elem, _Traits>& os )
	{
		return os << r2cm::tab << r2cm::tab;
	}

	template<class _Elem, class _Traits>
	inline std::basic_ostream<_Elem, _Traits>& tab3( std::basic_ostream<_Elem, _Traits>& os )
	{
		return os << r2cm::tab << r2cm::tab << r2cm::tab;
	}

	template<class _Elem, class _Traits>
	inline std::basic_ostream<_Elem, _Traits>& tab4( std::basic_ostream<_Elem, _Traits>& os )
	{
		return os << r2cm::tab << r2cm::tab << r2cm::tab << r2cm::tab;
	}
}

inline void LF()
{
	std::cout << r2cm::linefeed;
}
inline void LF2()
{
	std::cout << r2cm::linefeed2;
}
inline void LF3()
{
	std::cout << r2cm::linefeed3;
}

inline void SS()
{
	std::cout << r2cm::softsplit;
}

inline void LS()
{
	std::cout << r2cm::split;
}