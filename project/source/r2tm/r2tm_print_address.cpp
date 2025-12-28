#include "r2tm_print_address.hpp"

namespace r2tm
{
	long long CalculatePointerOffset( const void* p_1, const void* p_2 )
	{
		struct A
		{
			long long address;
			long long high;
		};

		const A a_1 = ( A& )p_1;
		const A a_2 = ( A& )p_2;

		return (
			  a_1.address > a_2.address
			? a_1.address - a_2.address
			: a_2.address - a_1.address
		);
	}
}