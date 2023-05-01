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

// Time complexity: O(n^2*k) --> TOO SLOW

void solution() {
    int n, k; cin >> n >> k;
    vi fs(n); for (int i = 0; i < n; ++i) cin >> fs[i];
    vi ds(n); for (int i = 0; i < n; ++i) cin >> ds[i];

    int mChange = n;

    for (int i = 0; i < n; ++i) {
        ll pi = fs[i] * ds[i];
        for (int ks = 0; ks <= k; ++ks) {
            ll lower = pi - (k-ks);
            ll upper = pi + (ks);
            int toChange = 0;
            bool poss = true;
            
            for (int j = 0; j < n; ++j) { if (j == i) continue;

                ll pj = fs[j] * ds[j];
                
                if (pj < lower || pj > upper) {
                    ll nds = (pi - (k-ks) + (fs[j]-1))/fs[j];
                    // ll a1 = nds * fs[j];
                    // ll a2 = (nds+1) * fs[j];
                    // if (a1 >= lower && a1 <= upper || a2 >= lower && a2 <= upper) {
                    //    toChange++;
                    // } else {poss = false; break;}
                
                    ll a1 = (nds) * fs[j];
                    if (a1 >= lower && a1 <= upper) toChange++;
                    else {poss = false; break;}
                }
            }

            if (poss)
                mChange = min(mChange, toChange);
        }
    }

    cout << mChange << "\n";
}


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int tt;
	cin >> tt;
	while (tt--) {
		solution();
	}

	return 0;
}
