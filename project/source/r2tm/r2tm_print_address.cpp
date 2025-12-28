#include "r2tm_print_address.hpp"

namespace r2tm
{
	long long CalculatePointerOffset( const void* p_1, const void* p_2 )
	{
		// 멤버 함수 포인터의 경우 16byte 이상이 될 수 있으므로 아래 구조체를 사용하여 주소값을 추출한다.
		//
		// + A::dummy 부분에 포함될 수 있는 정보
		//   > 1. this 조정값( 상속 )
		//   > 2. 가상 함수 테이블 조정 정보

		struct A
		{
			long long address;
			long long dummy;
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