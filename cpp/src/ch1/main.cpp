#include <iostream>

using namespace std;

constexpr double square(double x) {
	return x*x;
}

// Constructing a null reference (don't do that)
int& to_reference(int* a) {
	return *a;
}

int main() {
	//	float pi = 3.14159'265;
	//
    //	cout << pi << "\n";
    //
    //	// Error: Narrowing conversion from double to int
    //	// int i2{7.8};
    //	constexpr auto x = square(3);
    //	cout << x << "\n";
    //
    //	// Cannot use 'a' in constexpr
    //	// int a = 18;
    //	//  constexpr auto c = square(a);
    //	
    //	int v[] = {1,4,9,16,25,36,49};
    //	for (const int e : v)
    //		cout << e << " ";
    //	cout << "\n";
    //
    //
    //	// Accessing a 'nullptr' reference
    //	// int var = 8;
    //	// int& a = to_reference(nullptr);
    //	// cout << a << "\n";
	
	
	
	
	

	return 0;
}
