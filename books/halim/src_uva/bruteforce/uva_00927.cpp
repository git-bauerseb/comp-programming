#include <bits/stdc++.h>

using namespace std;

int i,d,k;
int P[20];


// P(x) = c0 + c1*x + c2*x^2 c3*x^3 = c0 + x*(c1 + x*(c2 + x*c3))
//
long evalPoly(int x) {
	long v = 0;
	for (int j = i; j > 0; --j) {
		v = static_cast<long>(x)*static_cast<long>(v + P[j]);
	}
	return v + static_cast<long>(P[0]);
}

void solution() {
	int n = 1;
	int nums = d;
	while (nums < k) {
		n++;
		nums += n*d; 
	}

	cout << evalPoly(n) << "\n";
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int C;
	cin >> C;
	while (C--) {
		cin >> i;

		for (int j = 0; j != i+1; ++j)
			cin >> P[j];

		cin >> d >> k;
		solution();

		memset(P, 0, sizeof(P));
	}

	return 0;
}
