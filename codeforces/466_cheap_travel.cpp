#include <iostream>

using namespace std;

int main() {

	int n, m, a, b;
	cin >> n >> m >> a >> b;

	float ratioM = b;
	float ratio1 = m * a;

	if (ratio1 < ratioM) {
		cout << n*a << "\n";
	} else {
		int r = n % m;
	   	int price = b * (n / m);
		cout << (price + min(a*r,b)) << "\n";
	}


	return 0;
}
