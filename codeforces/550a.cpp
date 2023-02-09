#include <bits/stdc++.h>

using namespace std;

int main() {

	string s;
	cin >> s;

	const int n = s.length();
	bool found = false;
	
	if (n < 4) {
		cout << "NO\n";
		return 0;
	}

	for (int i = 0; i < n-1; ++i) {
		// Look for 'AB' then 'BA'
		if (s[i] == 'A' && s[i+1] == 'B')
			for (int j = i+2; j < n-1; ++j)
				if (s[j] == 'B' && s[j+1] == 'A') {
					found = true;
					goto end;
				}

		// Look for 'BA' then 'AB'
		if (s[i] == 'B' && s[i+1] == 'A')
			for (int j = i+2; j < n-1; ++j)
				if (s[j] == 'A' && s[j+1] == 'B'){
					found = true;
					goto end;
				}
	}

	end:
		cout << (found ? "YES\n" : "NO\n");

	return 0;
}
