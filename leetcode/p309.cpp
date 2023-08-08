#include <vector>
#include <iostream>

using namespace std;

class Solution {

    public:
        int maxProfit(vector<int>& prices) {
            const int n = prices.size();

            vector<int> dp(n+1, 0);

            for (int i = 1; i <= n; ++i) {
                int r = -(1 << 20);
                dp[i] = dp[i-1];
                for (int j = i-1; j >= 0; --j) {
                    // Consider transactions up to day j
                    // Buy at j+2 (j+1 is cooldown)
                    // Sell at i
                    //
                    dp[i] = max(dp[i], prices[i-2] - prices[j+1-1] + dp[j]);
                }
            }

            return dp[n];
        }
};

int main() {

    vector<int> nums{1,2,3,0,2,34,3,6,345,3,4,234,74,4,75,68,56,75,6,56,75,67,3,34,53};
    // vector<int> nums{1,2,3,0,2};

    Solution solution{};
    int d = solution.maxProfit(nums);
    cout << d << "\n";

    return 0;
}
