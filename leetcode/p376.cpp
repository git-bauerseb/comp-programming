#include <iostream>
#include <vector>


using namespace std;

/*
    Example: 1, 7, 2, 5, 8, 3
              6, -5, 3, 3, -5

    Steps:
        1) Transform subsequence into seq. of differences
        2) DP on seq. of differences


    DP
        Time complexity: O(n^2)
        Space complexity: O(n)

        Base case:
            dp[0] = 1

        State:
            dp[i] := length of longest subsequence ending at index i 

        Transations:
            dp[i] = max(dp[j] where diff seq. at index j has different sign)


*/

/*
class Solution {

    public:
        bool sameSign(int a, int b) {
            return (a < 0 && b < 0)
                || (a > 0 && b > 0);
        }

  
        int wiggleMaxLength(vector<int>& nums) {
            const int n = nums.size();

            if (n == 1) return 1;

            // Calculate diff array
            vector<int> diff(n-1, 0);

            bool nZero = false;

            for (int i = 1; i < n; ++i) {
                diff[i-1] = nums[i] - nums[i-1];
                nZero |= diff[i-1] != 0;
            }

            vector<int> dp(n,0);
            dp[0] = 1;

            int tMax = 1;

            for (int i = 1; i < n-1; ++i) {
                int& state = dp[i];
                state = 1;
                for (int j = i-1; j >= 0; --j) {
                    if (!sameSign(diff[i], diff[j]) && (diff[i] != 0 && diff[j] != 0)) {
                        state = max(state, dp[j] + 1);
                    }
                }

                tMax = max(tMax, state);
            }

            return tMax + (nZero ? 1 : 0);
        }

};
*/


// O(n) solution?
class Solution {

    public:
        int wiggleMaxLength(vector<int>& nums) {

            const int n = nums.size();
            if (n == 1) return 1;

            vector<int> diff(n-1, 0);
            bool nZero = false;

            for (int i = 1; i < n; ++i) {
                diff[i-1] = nums[i] - nums[i-1];
                nZero |= diff[i-1] != 0;
            }

            int a = 0;  // Length of longest alternating subseq. that ends with +
            int b = 0;  // ... that ends with - 

            for (int i = 0; i < n-1; ++i) {
                if (diff[i] < 0) {b = a + 1;}
                else if (diff[i] > 0) {a = b + 1;}
            }

            return max(1,max(a,b) + (nZero ? 1 : 0));
        }
};


int main() {
    vector<int> nums{1,3,1,3,1,3};
    Solution solution{};
    int m = solution.wiggleMaxLength(nums);

    cout << m << "\n";

    return 0;
}
