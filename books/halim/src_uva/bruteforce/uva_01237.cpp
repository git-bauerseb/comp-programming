#include <bits/stdc++.h>

using namespace std;


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int T;
	cin >> T;
	
	while (T--) {
		int D;
		cin >> D;
		vector<tuple<string,int,int>> v;
		while (D--) {
			string s;
			int l,r;
			cin >> s >> l >> r;
			v.push_back({s,l,r});
		}

		int Q;
		cin >> Q;
		while (Q--) {
			int p;
			cin >> p;
			
			int numFac = 0;
			int ind = 0;
	
			for (int i = 0; i != v.size(); ++i) {
				if (get<1>(v[i]) <= p && get<2>(v[i]) >= p) {
					numFac++;
					ind = i;
				}
			}

			if (numFac != 1) {
				cout << "UNDETERMINED\n";
			} else {
				cout << get<0>(v[ind]) << "\n";
			}
		}

		if (T > 0)
			cout << "\n";
	}

	return 0;
}
