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

// Binary search version of Problem 1725/B
void solution() {
    ll n,d; cin >> n >> d;
    vector<long long> nums(n);
    for (int i = 0; i < n; ++i) cin >> nums[i];
    sort(nums.begin(), nums.end());

    int r = n-1;
    int l = 0;

    ll teams = 0;

    // Invariant:
    //  - l is index (from left) of first player not used
    //  - r is index of top player currently considered

    while (r >= l) {

        // Special case: Single player is enough
        if (nums[r] > d) {r--; teams++; continue;}

        // Binary search on how many players are needed to form a team
        // that has > D power
        int lo = l-1;
        int hi = r;

        while (hi - lo > 1) {
            int m = lo + (hi - lo) / 2;

            // Number of players is player r
            // and players l,l+1, ..., m
            // => m-l+1
            ll score = (m-l+2)*nums[r];

            if (score <= d) {lo = m;}
            else {hi = m;}
        }

        if (hi == r || (hi-l+2)*nums[r] <= d) break;
        else {r--; l = hi+1; teams++;}
    }

    cout << teams << "\n";
}

int main() {
	// int tt; cin >> tt;
    // while (tt--)
    solution();
	return 0;
}
