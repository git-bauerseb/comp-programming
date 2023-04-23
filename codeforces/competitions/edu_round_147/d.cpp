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

void solution() {
    ll n,k; cin >> n >> k;
    vector<pair<ll,ll>> intervals(n);

    // Left end point
    for (int i = 0; i < n; ++i) {cin >> intervals[i].first;}
    for (int i = 0; i < n; ++i) {cin >> intervals[i].second;}
    sort(intervals.begin(), intervals.end());

    ll steps = 0;
    bool shift = false;

    ll cost = 0;
    ll toColor = k;

    ll pos = 0;

    while (toColor && !intervals.empty()) {
        auto f = *intervals.begin();
    
        // if we are not in current interval, we need to end shift
        if (pos < f.first) {cost += 1; shift = false;}

        // [1    x1]  [2     2]
        // [1   [2  x1]    2]
        // Move cursor to begin of interval if less
        if (pos < f.first) {
            cost += f.first - pos;
            pos = f.first;
        }

        cost += shift ? 0 : 1;
        shift = true;

        // [1,2] -> Len: 2
        // [0,2] -> 0,1,2 Len: 3
        ll iLen = f.second - f.first + 1LL;

        // Don't need to consider complete interval
        if (iLen > toColor) {
            cost += iLen - toColor - 1;
            toColor = 0;
        } else {
            toColor -= iLen;
        }
    
        intervals.erase(intervals.begin());
    }

    cost += shift ? 1 : 0;

    if (toColor) {printf("-1\n");}
    else {printf("%lld\n", cost);}
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
