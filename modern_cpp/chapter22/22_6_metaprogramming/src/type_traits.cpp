#include <iostream>
#include <string>
#include <type_traits>

using namespace std;

template<typename T>
void process_helper(const T& t, true_type)
{
    cout << t << " is an integral type." << endl;
}

template<typename T>
void process_helper(const T& t, false_type)
{
    cout << t << " is an non-integral type" << endl;
}

template <typename T>
void process(const T& t)
{
    process_helper(t, typename is_integral<T>::type());
}

int main()
{
    if (is_integral_v<int>) {
		cout << "int is integral" << endl;
	} else {
		cout << "int is not integral" << endl;
	}

	if (is_class_v<string>) {
		cout << "string is a class" << endl;
	} else {
		cout << "string is not a class" << endl;
	}

    process(123);
    process(2.2);
    process("Test"s);
    return 0;
}