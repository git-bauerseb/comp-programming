#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

int dp[21][21];

class Solution {
public:

    bool predictTheWinner(vector<int>& nums) {
            int sum = 0;
            for (auto& e : nums) {
                sum += e;
            }

            std::fill(&dp[0][0], &dp[20][20], -1);

            int r = rec(nums, 0, nums.size()-1);
            return r >= (sum+1)/2;
    }

    int rec(vector<int>& nums, int i, int j) {
        if (i > j) {return 0;}
        if (i == j) {return nums[i];}

        int& entry = dp[i][j];

        if (entry >= 0) return entry;

        // Round k
        //
        // - Player can take element i
        //  - Enemy can then take i+1, j
        //  - Player can in next round take (i+2,j) OR (i+1, j-1)
        //
        // - Player can take element j
        //  - Enemy can then take i, j-1
        //  - Player can in next round take (i+1, j-1) OR (i, j-2)

        entry = max(nums[i] + min(rec(nums, i+2, j), rec(nums, i+1, j-1)),
                   nums[j] + min(rec(nums, i+1, j-1), rec(nums, i, j-2)));
        
        return entry;
    }
};

int main() {
    
    vector<int> nums{1,3,1};

    Solution solution{};
    bool t = solution.predictTheWinner(nums);
    cout << t << "\n";

    return 0;
}
