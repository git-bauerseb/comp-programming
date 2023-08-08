/*
    For weaker constraint (goal = O(1))
    dp[i][k] := Number of subarrays ending at i that have sum k.
    dp[i][k] = dp[i-1][k-num[i]]

    How many subarrays in total?

    [1,2,3] = > [1], [2], [3], [1,2], [1,2,3], [2,3] 

    Use prefix + count
*/
#include <iostream>
#include <vector>
#include <map>

using namespace std;

class Solution {
    public:
        int numSubarraysWithSum(vector<int>& nums, int goal) {
            const int n = nums.size();
            // cnt[sum] := How often prefix with given sum occurs
            map<int,int> cnt;

            int prefix = nums[0];
            cnt[prefix]++;
            cnt[0]++;

            // How often goal subarray occurs
            int numGoals = prefix == goal ? 1 : 0;

            for (int i = 1; i < n; ++i) {
                prefix += nums[i];
                if (prefix >= goal) {
                    numGoals += cnt[prefix-goal];
                }
                cnt[prefix]++;
            }

            return numGoals;
        }
};

int main() {

    vector<int> nums{0,0,0,0,0};

    Solution solution{};
    int g = solution.numSubarraysWithSum(nums, 0);
    cout << g << "\n";

    return 0;
}
