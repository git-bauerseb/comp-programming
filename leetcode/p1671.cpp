#include <iostream>
#include <vector>

using namespace std;

class Solution {

    public:
        int minimumMountainRemovals(vector<int>& nums) {
            const int n = nums.size();

            vector<int> dp1(n, 0);
            vector<int> dp2(n, 0);
            
            // Calculate LIS
            dp1[0] = 1;
            for (int i = 1; i < n; ++i) {
                dp1[i] = 1;
                for (int j = i-1; j >= 0; --j) {
                    if (nums[j] < nums[i]) {
                        dp1[i] = max(dp1[i], dp1[j] + 1);
                    }
                }
            }

            // Calculate LDS
            dp2[n-1] = 1;
            for (int i = n-2; i >= 0; --i) {
                dp2[i] = 1;
                for (int j = i+1; j < n; ++j) {
                    if (nums[j] < nums[i]) {
                        dp2[i] = max(dp2[i], dp2[j]+1);
                    }
                }
            }

            // Calculate complete answer
            int minDel = n;

            for (int i = 1; i < n-1; ++i) {
                // PIE - exclusion/inclusion - element at index i is
                // counted twice in dp1/dp2
                if (dp1[i] > 1 && dp2[i] > 1) {
                    int cDel = n - (dp1[i] + dp2[i]) + 1;
                    minDel = min(cDel, minDel);
                }
            }

            return minDel;
        }
};

int main() {

    vector<int> nums{100,92,89,77,74,66,64,66,64};

    Solution solution{};
    int m = solution.minimumMountainRemovals(nums);
    cout << m << "\n";

    return 0;
}
