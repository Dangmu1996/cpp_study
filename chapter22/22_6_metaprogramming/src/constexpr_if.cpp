#include <tuple>
#include <iostream>
#include <string>

using namespace std;

template<typename TupleType, int n>
void tuple_print_helper(const TupleType& t) {
	if constexpr(n > 1) {
		tuple_print_helper<TupleType, n - 1>(t);
	}
	cout << get<n - 1>(t) << endl;
}

template<typename T>
void tuple_print(const T& t)
{
	tuple_print_helper<T, tuple_size<T>::value>(t);
}

int main()
{
    auto t1 = make_tuple(167, "Testing", false, 2.3);
    tuple_print(t1);

    return 0;
}