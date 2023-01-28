#include <iostream>
#include <vector>
#include <stdexcept>

using namespace std;

void func() noexcept {
	throw length_error{"HELLO"};
}

int main() {
	// vector<int> v(-1);
	try {
		// func();
	} catch (length_error& err) {
		cout << err.what() << "\n";
	}

	static_assert(!(sizeof(int) < 8), "Integers too small");

	
	return 0;
}
