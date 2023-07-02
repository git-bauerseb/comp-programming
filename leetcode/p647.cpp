#include <iostream>
#include <vector>
#include <string>
#include <cstring>

using namespace std;

// Time complexity: O(n^2)
class Solution {

    public:
        int countSubstrings(string s) {
            const int n = s.size();

            // dp[i][j] := number of palindromes in substring s[i], ..., s[j]
            vector<vector<int>> dp(n, vector<int>(n,0));
            vector<vector<bool>> p(n, vector<bool>(n,false));

            for (int i = n-1; i >= 0; --i) {
                dp[i][i] = 1;
                p[i][i] = true;
                if (i < n && s[i] == s[i+1]) {
                    dp[i][i+1]++;
                    p[i][i+1] = true;
                }
                for (int j = i+1; j < n; ++j) {
                    if (j-1 >= 0) dp[i][j] += dp[i][j-1];

                    if (i+1 < n) dp[i][j] += dp[i+1][j];
                    if (i+1 < n && j-1 >= 0) {
                        if (p[i+1][j-1] && s[i] == s[j]) {
                            dp[i][j]++;
                            p[i][j] = true;
                        }
                        dp[i][j] -= dp[i+1][j-1];
                    }
                }
            }
            return dp[0][n-1];
        }
};

int main() {
    Solution solution{};
    int a = solution.countSubstrings("abaabba");
    cout << a << "\n";
    return 0;
}
