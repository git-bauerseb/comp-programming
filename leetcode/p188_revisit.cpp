#include <iostream>
#include <vector>

using namespace std;

const int INF = 1'000'000'007;

class Solution {
    public:
        int maxProfit(int k, vector<int>& prices) {
            const int n = prices.size();
            vector<vector<int>> dp(n+1, vector<int>(k+1,0));

            int cMax = -INF;

            for (int t = 1; t <= k; ++t) {
                cMax = -INF;
                for (int i = 1; i <= n; ++i) {
                    dp[i][t] = dp[i-1][t];
                    if (i > 1) {
                        cMax = max(cMax, dp[i-2][t-1] - prices[i-2]);
                    }
                    dp[i][t] = max(dp[i][t], cMax + prices[i-1]);
                }
            }

            return dp[n][k];
        }
};

int main() {
    vector<int> nums{2,4,1};
    Solution solution{};
    int m = solution.maxProfit(2, nums);
    cout << m << "\n";
    return 0;
}
