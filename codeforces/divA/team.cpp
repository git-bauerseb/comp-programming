#include <iostream>

using namespace std;

int main() {
	int n, count = 0;
	cin >> n;
	for (int i = 0; i != n; ++i) {
		int a,b,c;
		cin >> a;
		cin >> b;
		cin >> c;

		if ((a && b) || (a && c) || (b && c)) count++;
	}
	cout << count << "\n";
	return 0;
}
