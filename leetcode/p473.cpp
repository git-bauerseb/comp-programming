#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>

using namespace std;

int dp[1 << 15];

class Solution {
public:

    int used = 0;

    bool makesquare(vector<int>& matchsticks) {
        const int n = matchsticks.size();
        fill(&dp[0], &dp[(1 << 15) - 1], -1);

        int tSum = 0;

        for (auto& e : matchsticks) {
            tSum += e;
        }      

        if (tSum % 4 != 0) {
            return false;
        }

        int pSum = tSum / 4;


        return partition(matchsticks, 0, 0, 0, pSum, 1);
    }

    bool partition(vector<int>& nums, int cUsed, int idx, int sum, int goal, int nPartitions) {
        const int n = nums.size();
        if (sum > goal) {return false;}

        if (sum == goal) {
            return nPartitions == 4 ? true : partition(nums, 0, 0, 0, goal, nPartitions+1);
        }

        if (idx >= n) {
            if (sum < goal) {
                return false;
            }

            if (used == ((1 << n) - 1)) {
                dp[cUsed] = true;
                return true;
            }

            return sum == goal 
                && partition(nums, 0, 0, 0, goal, nPartitions+1);
        }

        int& entry = dp[cUsed];
        if (entry != -1) {return entry == 1;}

        // Use current element
        if (((used) & (1 << idx)) == 0 
                && sum + nums[idx] <= goal) {
            used |= 1 << idx;
            if (partition(nums, cUsed | (1 << idx), idx + 1, sum + nums[idx], goal, nPartitions)) {
                entry = 1;
                return true;
            }

            used &= ~(1 << idx);
        }

        // Don't use current element
        if (partition(nums, cUsed, idx + 1, sum, goal, nPartitions)) {
            entry = 1;
            return true;
        }

        return false;
    }
};


int main() {
    vector<int> nums{3,3,3,3,4};
    Solution s{};
    cout << s.makesquare(nums) << "\n";
    return 0;
}
