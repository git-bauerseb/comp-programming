#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        const int n = nums.size();
        if (n == 1) {return nums[0];}

        int lo = -1;
        int hi = n;

        while (hi - lo > 1) {
            int m = lo + (hi - lo) / 2;

            // Element occurs twice, if all elements from 1, ..., m occur twice then
            // array size must be even
            if (m < n-1 && nums[m] == nums[m+1]) {
                int len = m+1 + 1;
                if (len % 2 == 0) {
                    lo = m;
                } else {
                    hi = m+1;
                }
            } else if (m > 0 && nums[m] == nums[m-1]) {
                int len = m + 1;
                if (len % 2 == 0) {
                    lo = m;
                } else {
                    hi = m-1;
                }
            } else {
                return nums[m];
            }
        }

        return -1;
    }
};

int main() {
    vector<int> nums{3,3,7,7,10,11,11};
    Solution solution{};
    cout << solution.singleNonDuplicate(nums) << "\n";
    return 0;
}
