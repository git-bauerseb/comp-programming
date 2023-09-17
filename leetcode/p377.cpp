#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <limits>

using namespace std;

//
// dp[i] := Number of ways to add up to value i
//
// Base case
//  dp[nums]++
//
// Transitions
//  dp[i] += sum_{nums} dp[i-nums]
// 
// 
//
// Example: Nums = {1,2,3}, target = 4
//
// dp[1] = 1
// dp[2] = 1
// dp[3] = 1
//
// Transition
//  dp[2] = dp[2] + dp[2-1] = 2
//  dp[3] = dp[3] + dp[3-1] + dp[3-2] = 1 + 2 + 1 = 4
//  dp[4] = dp[4] + dp[4-1] + dp[4-2] + dp[4-3] = 0 + dp[3] + dp[2] + dp[1] = 0 + 4 + 2 + 1 = 7 
class Solution {
public:
    int combinationSum4(vector<int>& nums, int target) {
        vector<long long> dp(target+2, 0);
        for (auto& e : nums) {
            if (e >= 0 && e <= target) {
                dp[e] = 1;
            }
        }

        for (int i = 1; i <= target; ++i) {
            for (auto& e : nums) {
                if (i - e >= 0) {
                    dp[i] += dp[i-e];
                    dp[i] %= numeric_limits<int>::max();
                }
            }
        }

        return dp[target];
    }
};

int main() {
    vector<int> nums{1,2,3,4};
    Solution solution {};
    cout << solution.combinationSum4(nums,17) << "\n";
    return 0;
}
