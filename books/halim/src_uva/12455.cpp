#include <iostream>
#include <vector>

using namespace std;

int main() {

	int t;
	cin >> t;

	while (t--) {
		int n, p;
		cin >> n;
		cin >> p;

		vector<int> bars(p);

		for (int i = 0; i != p; ++i)
			cin >> bars[i];

		bool found = false;


		// Enumerate all subsets and compute the sum of heights
		for (int i = 0; i < (1 << p); ++i) {
			
			int cHeight = 0;
			for (int j = 0; j < p; ++j) {
				if ((1 << j) & i)
					cHeight += bars[j]; 
			}

			if (cHeight == n) {
				cout << "YES\n";
				found = true;
				break;
			}
		}

		if (!found) {
			cout << "NO\n";
		}
	}

	return 0;
}
