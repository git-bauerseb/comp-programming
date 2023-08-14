#include <iostream>

#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int maximumJumps(vector<int>& nums, int target) {
        const int n = nums.size();
        
        vector<int> dp(n,-1);
        dp[0] = 0;

        for (int i = 1; i < n; ++i) {
            int& entry = dp[i];
            for (int j = i-1; j >= 0; --j) {
                if (abs(nums[i] - nums[j]) <= target && dp[j] >= 0) {
                    dp[i] = max(dp[i], 1 + dp[j]);
                }
            }
        }

        return dp[n-1];
    }
};
