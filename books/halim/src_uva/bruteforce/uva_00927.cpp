#include <bits/stdc++.h>

using namespace std;

typedef unsigned long long ull;

int i,d,k;

// P[0] = c0
// P[1] = c1
// P[2] = c2
//
// P[i] = ci
long long P[21];


// P(x) = c0 + c1*x + c2*x^2 c3*x^3 = c0 + x*(c1 + x*(c2 + x*c3))
ull eval(int n, ull currentNPowVals, int coeff){
    if (coeff > deg)
        return 0;
    return P[coeff] * currentNPowVals + eval(n, n * currentNPowVals, coeff + 1);
}

void solution() {
	int n = 1;
	int nums = d;
	while (nums < k) {
		n++;
		nums += n*d; 
	}

	cout << eval(n) << "\n";
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
