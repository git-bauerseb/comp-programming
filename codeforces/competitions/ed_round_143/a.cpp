#include <bits/stdc++.h>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);


	int t;
	cin >> t;

	while (t--) {
		int n,m;
		cin >> n >> m;

		string s, t;
		cin >> s >> t;

		reverse(t.begin(), t.end());
		s += t;

		int wrong = 0;

		for (int i = 0; i <= n + m - 2; i++) {
			wrong += (s[i] == s[i+1]);
		}

		cout << (wrong <= 1 ? "YES\n" : "NO\n");
	}

	return 0;
}
