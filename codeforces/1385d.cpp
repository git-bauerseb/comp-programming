#include <bits/stdc++.h>

using namespace std;

inline int minuniform(string& s, int start, int end, char c) {
	int m = 0;
	for (int i = start; i != end; ++i) {m += s[i] != c ? 1 : 0;}
	return m;
}

// Time complexity: O(nlog(n))
//  - not too slow as sum of n <= 2*10^5
//  - Time: n*log(n) = 2*10^5 * 5 * log(20) < 5 * 10^6
int mincgood(string& s, int start, int len, char c) {
	if (len == 1) {return s[start] != c ? 1 : 0;}
	else {
		int m1 = minuniform(s, start, start + len/2, c) + mincgood(s, start + len/2, len/2, c+1);
		int m2 = minuniform(s, start + len/2, start + len, c) + mincgood(s, start, len/2, c+1);
		return min(m1, m2);
	}
}

/*
	If s is 'a'-good string
	  s[1], ..., s[n/2] is 'b'-good string or s[n/2], ..., s[n] is 'b'-good string

*/
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
