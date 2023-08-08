#include <iostream>
#include <vector>

using namespace std;

const int INF = 1'000'000'007;

class Solution {
    public:
        int maxProfit(vector<int>& prices, int fee) {
            const int n = prices.size();
            vector<int> dp(n+1, 0);
            int rolling = -INF;

            for (int i = 1; i <= n; ++i) {
                if (i > 1) {rolling = max(rolling, dp[i-2] - prices[i-2] - fee);}
                dp[i] = max(dp[i-1], rolling + prices[i-1]);
            }

            return dp[n];
        }
};

int main() {

    vector<int> prices{1,3,7,5,10,3};
    Solution solution{};
    int p = solution.maxProfit(prices, 3);
    cout << p << "\n";

    return 0;
}
