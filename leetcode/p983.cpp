#include <iostream>
#include <vector>

using namespace std;

const int INF = 365*1001 + 10;

class Solution {
    public:
        int mincostTickets(vector<int>& days, vector<int>& costs) {
            const int n = days.size();
            vector<int> dp(n, INF); 

            for (int i = 0; i < n; ++i) {
                dp[i] = min(dp[i], (i == 0 ? 0 : dp[i-1]) + costs[0]);
                dp[i] = min(dp[i], (i == 0 ? 0 : dp[i-1]) + costs[1]);
                dp[i] = min(dp[i], (i == 0 ? 0 : dp[i-1]) + costs[2]);

                for (int j = i+1; j < n; ++j) {
                    if (days[j] - days[i] < 7) {
                        dp[j] = min(dp[j], (i == 0 ? 0 : dp[i-1]) + costs[1]);
                    }

                    if (days[j] - days[i] < 30) {
                        dp[j] = min(dp[j], (i == 0 ? 0 : dp[i-1]) + costs[2]);
                    }

                }
            }


            return dp[n-1];
        }
};

int main() {

    vector<int> nums{1,5,6,7,8,20};
    vector<int> p{7,2,15};

    Solution solution{};
    int m = solution.mincostTickets(nums, p);
    cout << m << "\n";

    return 0;
}
