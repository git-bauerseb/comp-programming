#include <iostream>

using namespace std;

int main() {

	int N;
	cin >> N;
	for (int i = 0; i != N; ++i) {
		int num;
		cin >> num;
		cout << (num-1) << "\n";
	}

	return 0;
}
