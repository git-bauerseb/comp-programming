#include <iostream>
#include <algorithm>
#include <vector>
#include <set>

using namespace std;

// Constants
#define MOD 1'000'000'007

// Simple types
#define ll long long
#define ld long double

// Aggeragte types
#define pii pair<int,int>
#define pll pair<long,long>

#define vi vector<int>
#define vl vector<long>

#define si set<int>
#define sl set<long>

// Output
template <typename T>
void print_v(vector<T>& v) {cout << "{"; for (auto& x : v) cout << x << " "; cout << "\n";}

ll solution() {
    ll n; cin >> n;

    ll k = 0;

    while (true) {
        ll num = (1LL << (k+1LL)) + k*(k+1LL)/2LL;
        if (num > n) break;
        k++;
    }


    return k;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int tt;
	cin >> tt;
	while (tt--) {
		ll res = solution();
	    cout << res << "\n";
    }

	return 0;
}
