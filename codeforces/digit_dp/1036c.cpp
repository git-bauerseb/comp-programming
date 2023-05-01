#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <cstring>

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

// dp[n][cnt][t]
//   - Number of numbers with suffix n such that they contain cnt non-zero digits.
ll dp[20][25][2];

ll solution(string num) {
    const int n = num.size();
    memset(dp, 0, sizeof(dp));

    // Base case
    // Exactly one suffix of length 0 such that it contains
    dp[n][0][0] = 1;
    dp[n][0][1] = 1;

    for (int i = n-1; i >= 0; --i) {
        for (int t = 0; t < 2; ++t) {
            for (int cnt = 0; cnt < 25; ++cnt) {
            
                // dp[i][cnt][1]
                if (t) {
                    for (int d = 0; d <= num[i]-'0'; ++d) {
                        if (d && d == num[i]-'0')
                            dp[i][cnt][t] += dp[i+1][cnt-1][1];
                        else if (!d && d == num[i]-'0')
                            dp[i][cnt][t] += dp[i+1][cnt][1];
                        else if (!d) {
                            dp[i][cnt][t] += dp[i+1][cnt][0];
                        } else {
                            dp[i][cnt][t] += dp[i+1][cnt-1][0];
                        }
                    }
                // dp[i][cnt][0]
                } else {
                    dp[i][cnt][0] += 9*dp[i+1][cnt-1][0] + dp[i+1][cnt][0];
                }
            }
        }
    }

    ll ans = 0;
    for (int i = 0; i <= 3; ++i) {ans += dp[0][i][1];}
    return ans;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int tt;
	cin >> tt;
	while (tt--) {
        ll l;
        ll r;
        cin >> l >> r;
        string upper = to_string(r);
        string lower = to_string(l-1);
        ll a1 = solution(upper);
        ll a2 = solution(lower);
        cout << (a1-a2) << "\n";
    }

	return 0;
}
