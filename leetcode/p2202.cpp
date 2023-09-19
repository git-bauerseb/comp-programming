#include <cmath>
#include <vector>

// Proof why largest element among min(k, n) is always possible of there are < k-1
// elements before
//
// 
//
using namespace std;
class Solution {
public:
    int maximumTop(vector<int>& nums, int k) {
        const int n = nums.size();
        int mE = -1;
        int mI = -1;
        
        for (int i = 0; i <= min(n-1, k); ++i) {
            
            if (i != k-1 && nums[i] >= mE) {
                mE = nums[i];
                mI = i;
            }

        }

        if (n == 1) {
            return k % 2 == 0 ? mE : -1;
        }

        return mE;
    }
};
