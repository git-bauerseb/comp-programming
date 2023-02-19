#include <bits/stdc++.h>

using namespace std;


long long a[200001];
long long b[200001];

long long c[200001];
long long c1[200001];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int t;
	cin >> t;
	while (t--) {

		int n;
		cin >> n;

		int offset = 0;

		for (int i = 0; i != n; ++i)
			cin >> a[i];

		for (int i = 0; i != n; ++i)
			cin >> b[i];

		while (offset < n) {
		for (int i = 0; i != n; ++i) {
			int consumed = 0;
			for (int j = i-offset; j >= 0; j--) {
				consumed += min(a[j], b[i]);
				a[j] -= consumed;
			}

			cout << consumed;
			cout << (i == (n-1) ? "\n" : " ");
		}
		offset++;
		}
	}

	return 0;
}
