#include <bits/stdc++.h>

using namespace std;

#define ll long long


const int M_N = 200002;
ll a[M_N];
ll b[M_N];

ll bPref[M_N];
ll t[M_N];

ll cnt[M_N];
ll add[M_N];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int tt;
	cin >> tt;

	while (tt--) {
		int n;
		cin >> n;
		for (int i = 0; i != n; ++i) cin >> a[i];
		for (int i = 0; i != n; ++i) cin >> b[i];

		bPref[0] = b[0];
		for (int i = 1; i != n; ++i) bPref[i] = b[i] + bPref[i-1];

		for (int i = 0; i != n; ++i) {

			auto it = upper_bound(bPref, bPref + i, -1,
					[](const ll element, const ll value {
						return element < a[i] + prefB[i];	
					});

			int rem = a[i] - *it;
		}
	}

	return 0;
}
