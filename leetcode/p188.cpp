#include <iostream>
#include <vector>

using namespace std;

/*
 Idea 1: DP

 Time complexity: O(trans. * days^2)

*/

/*
class Solution {

    public:
        int maxProfit(int k, vector<int>& prices) {
            const int n = prices.size();

            // Optimization
            // k > n/2 => can buy/sell at every point 
            // => max profit is sum of non-neg. diff of pairs
            if (k >= n/2) {
                int mProf = 0;
                for (int i = 1; i < n; ++i) {
                    mProf += max(0, prices[i] - prices[i-1]);
                }
                return mProf;
            }

            // dp[day][transac]
            vector<vector<int>> dp(n+2, vector<int>(k+2,0));

            // Base case: satisfied
            for (int d = 1; d <= n; ++d) {
                for (int t = 1; t <= k; ++t) {
                        dp[d][t] = max(dp[d-1][t]);

                    for (int i = d-1; i >= 0; --i) {
                        int diff = prices[d-1] - prices[i];

                        dp[d][t] = max(dp[d][t], dp[i][t-1] + diff);
                    }

                }
            }

            return dp[n][k];
        }
};
*/

class Solution {

    public:
        int maxProfit(int k, vector<int>& prices) {
            const int n = prices.size();
            vector<vector<int>> dp(n+2, vector<int>(k+2,0));
            for (int t = 1; t <= k; ++t) {
                int cMax = -prices[0];
                for (int d = 1; d <= n; ++d) {
                    int& entry = dp[d][t];
                    entry = max(cMax + prices[d-1], dp[d-1][t]);
                    cMax = max(cMax, dp[d-1][t-1] - prices[d-1]);
                }
            }

            return dp[n][k];
        }
};


int main() {

    int k = 2;
    vector<int> prices{2,4,1};

    Solution solution{};
    int m = solution.maxProfit(k, prices);
    cout << m << "\n";

    return 0;
}
