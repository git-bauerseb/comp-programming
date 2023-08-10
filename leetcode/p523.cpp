#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

// 23 2 6 4 7
//
// mod 13 10 12 5  9  3
class Solution {
    public:
        bool checkSubarraySum(vector<int>& nums, int k) {
            if (k == 1) {return nums.size() > 1;}

            const int n = nums.size();

            // Map storing what mod has been saved
            map<int,int> occ;
            occ[0] = -1;

            int prefix = 0;

            for (int i = 0; i < n; ++i) {
                prefix = (prefix + nums[i]) % k;
                if (occ.count(prefix) > 0 && i - occ[prefix] > 1) {
                    return true;
                }

                if (occ.count(prefix) > 0) {
                    occ[prefix] = (occ[prefix] == i-1) ? occ[prefix] : i;
                } else {
                    occ[prefix] = i;
                }
            }

            return false;
        }
};

int main() {

    // 24
    vector<int> nums {0,1,2,3,4,5,10,25};

    Solution solution{};
    cout << solution.checkSubarraySum(nums, 25) << "\n";

    return 0;
}
