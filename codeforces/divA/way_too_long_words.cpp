#include <iostream>

using namespace std;

int main() {

	int N;

	cin >> N;

	for (int i = 0; i != N; ++i) {
		string inp;
		cin >> inp;

		if (inp.length() > 10) {
			cout << inp[0] << (inp.length() - 2) << inp[inp.length()-1] << "\n";
		} else
			cout << inp  << "\n";
	}

	return 0;
}
