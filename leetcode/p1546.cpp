#include <iostream>
#include <map>
#include <vector>

using namespace std;

class Solution {
    public:
        int maxNonOverlapping(vector<int>& nums, int target) {
            const int n = nums.size();

            map<int,int> occ;
            occ[0]++;

            int pref = 0;
            int res = 0;
            for (int i = 0; i < n; ++i) {
                pref += nums[i];
                if (occ.count(pref-target) > 0) {
                    res++;
                    occ.clear();
                }
                occ[pref]++;
            }

            return res;
        }
};
int main() {
    // vector<int> nums{-2,6,6,3,5,4,1,2,8};
    vector<int> nums{-5,5,-4,5,4};
    Solution solution{};
    cout << solution.maxNonOverlapping(nums, 0) << "\n";
    return 0;
}
