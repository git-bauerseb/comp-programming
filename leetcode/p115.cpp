#include <iostream>
#include <vector>

using namespace std;

const long MOD = 1L << 31;

class Solution {

    public:
        int numDistinct(string s, string t) {
            const int n = s.size();
            const int m = t.size();

            // dp[i][j] := number of distinct subsequences of s[1], ..., s[i] (1-based indexing)
            // such that subsequence equals t[1], ..., t[j]
            //
            // dp[0][0] = 1
            // dp[i][j] = dp[i-1][j-1] if s[i] == t[j] + dp[i-1][j]
            vector<vector<long>> dp(n+1, vector<long>(m+1, 0));
            dp[0][0] = 1;           

            for (int i = 1; i <= n; ++i) {
                dp[i][0] = 1;
                for (int j = 1; j <= m; ++j) {
                    if (s[i-1] == t[j-1]) dp[i][j] = (dp[i][j] + dp[i-1][j-1]) % MOD;
                    dp[i][j] = (dp[i][j] +(dp[i][j] + dp[i-1][j]) % MOD;
                }
            }
            return dp[n][m];
        }
};

int main() {
    Solution solution{};
    int ways = solution.numDistinct("rabbbit", "rabbit");
    cout << ways << "\n";
    return 0;
}
