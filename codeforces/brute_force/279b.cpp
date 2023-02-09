#include <bits/stdc++.h>

using namespace std;



int main() {

	int n, t;
	cin >> n >> t;

	vector<int> books(n, 0);
	for (int i = 0; i != n; ++i)
		cin >> books[i];
	

	// Calculate prefix sum
	vector<int> pref(n, 0);
	pref[0] = books[0];
	for (int i = 1; i != n; ++i)
		pref[i] = pref[i-1] + books[i];

	int numBooks = 0;
	for (int j = 0; j != n; ++j) {
		auto it = lower_bound(pref.begin() + j, pref.end(),
				t, [&](const int elem, const int value) {
				return elem - (j == 0 ? 0 : pref[j-1]) <= value; 
		});

		int num = (it - pref.begin()) - j;
		numBooks = max(numBooks, num);
	}

	cout << numBooks << "\n";

	return 0;
}
