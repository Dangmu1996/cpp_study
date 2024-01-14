#include "hash_map.hpp"
#include <iostream>
#include <map>

using namespace ProCpp;
using namespace std;

int main()
{
	//hash_map<string, int> myHash;
	//myHash.insert(make_pair("KeyOne", 100));
	//myHash.insert(make_pair("KeyTwo", 200));
	//myHash.insert(make_pair("KeyThree", 300));

	hash_map<string, int> myHash{
			{ "KeyOne", 100 },
			{ "KeyTwo", 200 } };

	myHash.insert({
			{ "KeyThree", 300 },
			{ "KeyFour", 400 } });

	for (auto it = myHash.cbegin(); it != myHash.cend(); ++it) {
		// ->\BF\CD *\B8\A6 \B5\D1 \B4\D9 \BB\E7\BF\EB\C7ؼ\AD \C0\CC \BF\AC\BB\EA\C0\BB \C5׽\BAƮ\C7Ѵ\D9.
		cout << it->first << " maps to " << (*it).second << endl;
	}

	cout << "----" << endl;

	// \B9\FC\C0\A7 \B1\E2\B9\DD for\B9\AE\C0\B8\B7\CE \BF\F8\BCҸ\A6 \C3\E2\B7\C2\C7Ѵ\D9.
	for (auto& p : myHash) {
		cout << p.first << " maps to " << p.second << endl;
	}

	cout << "----" << endl;

	// \B9\FC\C0\A7 \B1\E2\B9\DD for\B9\AE\B0\FA C++17 \B1\B8\C1\B6\C0\FB \B9\D9\C0ε\F9\C0\BB \BB\E7\BF\EB\C7ؼ\AD \BF\F8\BCҸ\A6 \C3\E2\B7\C2\C7Ѵ\D9.
	for (auto&[key, value] : myHash) {
		cout << key << " maps to " << value << endl;
	}

	cout << "----" << endl;

	// \C7ؽø\CA\C0\C7 \BF\F8\BCҸ\A6 \B8\F0\B5\CE \B4\E3\C0\BA std::map\C0\BB \BB\FD\BC\BA\C7Ѵ\D9.
	map<string, int> myMap(cbegin(myHash), cend(myHash));
	for (auto& p : myMap) {
		cout << p.first << " maps to " << p.second << endl;
	}

	cout << "----" << endl;

	auto found = myHash.find("KeyThree");
	if (found != end(myHash))
	{
		cout << "Found KeyThree: value = " << found->second << endl;
	}


	map<string, int> someMap{ {"One", 1},{"Two", 2} };
	hash_map<string, int> hashMapFromMap(cbegin(someMap), cend(someMap));

	hash_map<string, int> myHash2;
	myHash.swap(myHash2);

	hash_map<string, int> myHash3(std::move(myHash2));

	cout << myHash3.size() << endl;
	cout << myHash3.max_size() << endl;

	return 0;
}