#include <atomic>
#include <iostream>
#include <type_traits>

// 아토믹 타입을 사용할 때는 동기화 메커니즘을 명시적으로 사용하지 않아도 된다.
// 하지만 특정 타입에 대해 아토믹 연산으로 처리할 때는 뮤텍스와 같은 동기화 메커니즘을 내부적으로 사용하기도 한다. 이럴 때는
// is_lock_free() 메서드를 호출해서 잠그지 않아도 되는지(락-프리), 즉 명시적으로 동기화 메커니즘을 사용하지 않고도 수행할 수 있는지 확인한다.

using namespace std;

class Foo { private: int mArray[123]; }; //Foo는 락-0프리가 아니고.
class Bar { private: int mInt; }; //Bar는 락-프리이다.

int main()
{
	atomic<Foo> f;
	// cout << is_trivially_copyable_v<Foo> << " " << f.is_lock_free() << endl;

	atomic<Bar> b;
	cout << is_trivially_copyable_v<Bar> << " " << b.is_lock_free() << endl;

    return 0;
}