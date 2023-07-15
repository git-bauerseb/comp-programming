#include <iostream>
#include <vector>

using namespace std;


// dp[i][k] := max number of coins after k operations when using first i piles
//
// dp[i][k] = dp[i-1][k] + dp[i-1][k-1] + pile[i].top + dp[i-1][k-2] + pile[i].top + pile[i].second + ...
class Solution {

    const int M_INF = -1'000'000'000;

    public:
        int maxValueOfCoins(vector<vector<int>>& piles, int k) {
            const int n = piles.size();

            vector<int> cum(n,0);

            // Calculate prefix sums for piles
            for (int i = 0; i < n; ++i) {
                const int m = piles[i].size();
                for (int j = 1; j < m; ++j) {
                    piles[i][j] = piles[i][j] + piles[i][j-1];
                }
                
                cum[i] = (i == 0 ? 0 : cum[i-1]) + piles[i][piles[i].size()-1];
            }



            vector<vector<int>> dp(n+1, vector<int>(k+1, M_INF));
            dp[0][0] = 0;
            for (int op = 0; op <= min((int)(piles[0].size()), k); ++op) {
                dp[0][op] = (op == 0) ? 0 : piles[0][op-1];
            }

            for (int i = 1; i < n; ++i) {
                dp[i][0] = 0;
                for (int op = 1; op <= k; ++op) {    
                    const int m = piles[i].size();
                    for (int l = 0; l <= min(m, k); ++l) {
                        // If previous piles have to few coins, then skip
                        if (op-l < 0 || cum[i-1] < op-l)
                            continue;

                        // Perform op-l operations on previous piles
                        int n = dp[i-1][op-l];

                        // Perform l operations on current pile
                        n += (l == 0) ? 0 : piles[i][l-1];

                        dp[i][op] = max(dp[i][op], n);
                    }
                }
            }

             return dp[n-1][k];
        }
};

// op = 2
// l = 1
//  => dp[i-1][op-l] = 1
//  => piles[i][l-1] = 7
//  => 8
//
// l = 2
//  => dp[i-1][op-l] = 0
//  => piles[i][l-1] = 15
//  => 15


int main() {
    vector<vector<int>> p = {
        {1},{2},{3},{4}
    };

    Solution solution{};
    int m = solution.maxValueOfCoins(p, 2);
    cout << m << "\n";
    return 0;
}
