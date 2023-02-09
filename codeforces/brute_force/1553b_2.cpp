#include <bits/stdc++.h>

using namespace std;


/*
 	dacaba
	cabac

	p = 2



*/

int main() {

	int tt;
	cin >> tt;

	while (tt--) {

		string s, t;
		cin >> s >> t;

		vector<int> pos;
		const int n = s.size();
		const int m = t.size();

		for (int i = 0; i != n; ++i)
			if (s[i] == t[0])
				pos.push_back(i);


		bool found = false;

		for (auto& p : pos) {
			// Moving to the right
			for (int i = 1; i <= m && p + (i-1) < n; ++i) {
				string right = s.substr(p, i);
				int rem = m - right.size();
				
				if (p+i-rem-1 >= 0) {
				string left = s.substr(p+i-rem-1, rem);
				reverse(left.begin(), left.end());
				if (right + left == t) {
					found = true;
					cout << "YES\n";
					goto end;
				}
				}
			}
		}

end:
		if (!found) {
		cout << "NO\n";
		}
	}

	return 0;
}
