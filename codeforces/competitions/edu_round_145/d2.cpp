#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <cstring>
#include <limits>

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


// dp[i][0] Ending with 0
// dp[i][1] Ending with 01
// dp[i][2] Ending with 11

void solution() {
 

    string s; cin >> s;
    const int n = s.length();
    vector<vector<ll>> dp(n+1, vector<ll>(4,1E18));

    ll swap = 1e12;
    ll del = 1e12 + 1;

    dp[0][0] = dp[0][1] = dp[0][2] = 0;
    dp[1][0] = 0;

    for (int i = 2; i < n; ++i) {
        if (s[i] == '1') {
            dp[i][2] = min(dp[i-1][1], dp[i-1][2]);
            dp[i][1] = dp[i-1][0];
        } else {
            dp[i][0] = dp[i-1][0];
            dp[i][1] = dp[i-1][1] + swap;
            dp[i][2] = dp[i-1][2] + del;
        }
    }

    ll r = min(dp[n][0], min(dp[n][1], min(dp[n][2], dp[n][3])));
    cout << r << "\n";
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
