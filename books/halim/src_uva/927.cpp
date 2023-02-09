#include <bits/stdc++.h>

using namespace std;

int evalPoly(vector<int>& coeff, int x) {
	const int n = coeff.size();
	int val = coeff[n-1]*x;
	for (int i = n-2; i != 0; --i)
		val = (val + coeff[i])*x;

	return val + coeff[0];
}

int main() {

	int c;
	cin >> c;


	while (c--) {
		int degree;
		cin >> degree;

		vector<int> coeff(degree+1, 0);
		for (int i = 0; i <= degree; ++i)
			cin >> coeff[i];

		int d, k;
		cin >> d >> k;

		float discr =  1.0 + 8.0*(static_cast<float>(k)/static_cast<float>(d));
		float n = (-1+sqrt(discr))/2;
		cout << evalPoly(coeff, ceil(n)) << "\n";
	}
	


	return 0;
}
