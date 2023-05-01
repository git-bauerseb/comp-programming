#include <iostream>

// Dynamic array
#include <vector>

// Static array
#include <array>

// Bitset
#include <bitset>

using namespace std;

void static_array() {

	// Static array
	// template<class T, std::size_t N>
	// Not initialized
	array<int, 6> a;
	cout << a.empty() << "\n";

	a[0] = 10;
	cout << a[0] << "\n";
	cout << a.back() << "\n";

	array<int, 0> b;
	cout << b.empty() << "\n";

	array<int, 3> c = {1,2,3};
	cout << c.back() << "\n";
}

// Vectors
void dynamic_array() {
	// resize vs reserve
	//   - reserve(n): allocates memory, uninitialized
	//   	does not affect size
	//   - resize(n, value): affects size
	vector<int> a;
    a.reserve(5);

	cout << a.size() << "\n"; // 0
	cout << a.capacity() << "\n"; // 5
	cout << a[2] << "\n"; // Undefined behaviour


	vector<int> b;
	b.resize(5,0);
	cout << b.size() << "\n"; // 5
	cout << b.capacity() << "\n"; // 5
	cout << b[0] << "\n"; // 0 (Defined behaviour)

	// Same as resize for empty vector
	b.assign(3, 2);
	cout << b.size() << "\n";
	cout << b.capacity() << "\n";
	cout << b[0] << "\n";
}

void bitsets() {

	// bitset<size>
	bitset<8> s;
	cout << s << "\n";
	cout << ~s << "\n";

	s = ~s;
	s &= 0b11011;
	cout << s << "\n";
	if (s[1])
		cout << "Bit set at position 1\n";
}

int main() {

	// dynamic_array();
	bitsets();

	return 0;
}
