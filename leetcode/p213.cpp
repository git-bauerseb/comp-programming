#include <iostream>
#include <vector>

using namespace std;

/*
    DP

    Convention:
        houses start at index 1, end at n

    State:
        dp[i][0] := considering houses 1, ..., n-1
        dp[i][1] := considering houses 2, ..., n

    Approach:
      - a) consider houses 1, ..., n-1
      - b) consider houses 2, ..., n

      - return max
*/
class Solution {

    public:
        int rob(vector<int>& nums) {
            const int n = nums.size();
    
            // Edge case
            if (n == 1) return nums[0];

            // dp[idx][0] := considering houses 1, ..., n-1
            // dp[idx][1] := considering houses 2, ..., n
            vector<vector<int>> dp(n+3, vector<int>(2,0));

            // a)
            for (int i = 2; i < n+1; ++i) {
                dp[i][0] = max(dp[i-1][0], dp[i-2][0] +  nums[i-2]);
                dp[i+1][1] = max(dp[i][1], dp[i-1][1] + nums[i-1]);
            }

            return max(dp[n][0], dp[n+1][1]);
        }
};


int main() {

    vector<int> nums{1};
    Solution solution{};
    int m = solution.rob(nums);
    cout << m << "\n";


    return 0;
}
