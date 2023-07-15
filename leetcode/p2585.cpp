#include <iostream>
#include <vector>
#include <cstring>

#define MOD 1'000'000'007

using namespace std;

int dp[51][1001];

// dp[k][t] := Number of ways to reach target 't' by using the first 'k' types of questions.
//
// Base case
// =========
// dp[0][t] = 1 iff t = c * marks[i], 0 <= c <= count[i]
// dp[k][0] = 1
//
// Transition
// ==========
// dp[k][t] = dp[k-1][t]
//   - Count all possible ways to get target 't' by using only first 'k-1' questions
//   - Now, we can use up to count[k] times the question k with mark k
//
//      => dp[k][t] += dp[k-1][t - c * mark[k]] for 1 <= c <= count[k]
//
//      - Why c >= 1?
//        - If we would allow c == 0, then we would use dp[k-1][t] which was used above
//          => Therefore, we would count this twice
//
//      - Why not use dp[k][t - c * mark[k]]
//        - If we use k instead of k-1 then we would also possibly include the kth question.
//        - Because we iterate to c <= count[k] and we would also possibly use the same question,
//          we would potentially use question k more than count[k] times.
//
// Final
// =====
// dp[n-1][target]
class Solution {
    public:
        int waysToReachTarget(int target, vector<vector<int>>& types) {
            const int n = types.size();
            memset(dp, 0, sizeof(dp));

            // Base case(s)
            for (int k = 0; k < n; ++k) {
                dp[k][0] = 1;
            } 

            for (int c = 0; c <= types[0][0]; ++c) {
                if (c*types[0][1] <= target) {
                    dp[0][c*types[0][1]] = 1;
                }
            }

            for (int k = 1; k < n; ++k) {
                for (int t = 0; t <= target; ++t) {
                    dp[k][t] = dp[k-1][t];
                    for (int c = 1; c <= types[k][0]; ++c) {
                        if (t - c*types[k][1] >= 0) {
                            dp[k][t] = (dp[k][t] + dp[k-1][t - c * types[k][1]]) % MOD;
                        }
                    }

                }
            }

            return dp[n-1][target];
        }
};

int main() {
    
    vector<vector<int>> types = {
        {50,1}, {50,2}, {50,5}
    };
    
    Solution solution{};
    int n = solution.waysToReachTarget(5, types);
    cout << n << "\n";
    return 0;
}
