#include <bits/stdc++.h>

using namespace std;

inline bool uniform(string& s, int start, int end, char c) {
	for (int i = start; i != end; ++i) if (s[i] != c) return false;
	return true;
}

bool cgood(string s, char c) {
	const int n = s.length();
	if (n == 1) {return s[0] == c;}
	else {
		return (uniform(s, 0, n/2, c) && cgood(s.substr(n/2, n/2), c+1))
			|| (uniform(s, n/2, n, c) && cgood(s.substr(0, n/2), c+1));
	}
}

inline int minuniform(string& s, int start, int end, char c) {
	int m = 0;
	for (int i = start; i != end; ++i) {m += s[i] != c ? 1 : 0;}
	return m;
}

int mincgood(string& s, int start, int len, char c) {
	if (len == 1) {return s[0] != c ? 1 : 0;}
	else {
		int m1 = minuniform(s, start, start + len/2, c) + mincgood(s, start + len/2, len/2, c+1);
		int m2 = minuniform(s, start + len/2, start + len, c)
			+ mincgood(s, start, len/2, c+1);
		return min(m1, m2);
	}
}

int main() {
	
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int t;
	cin >> t;
	while (t--) {
		int l;
		cin >> l;
		string s;
		cin >> s;
		cout << mincgood(s, 0, l, 'a') << "\n";
	}
	
	return 0;
}
