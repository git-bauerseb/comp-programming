#include <iostream>
#include <vector>

using namespace std;

// Sliding Window

// Invariant: Product a[l], ..., a[r-1] < k
class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        const int n = nums.size();

        long long cProd = 1;
        int ans = 0;

        int r = 0;
        for (int l = 0; l < n; ++l) {
            r = max(r, l);
            if (l > 0) {
                if (cProd > 1) {
                    cProd /= nums[l-1];
                }
            }

            while (r < n && cProd * nums[r] < k) {
                cProd = cProd * nums[r];
                r++;
            }

            ans += r - l;
        }

        return ans;
    }
};

int main() {
    vector<int> nums{57,44,92,28,66,60,37,33,52,38,29,76,8,75,22};

    Solution s{};
    cout << s.numSubarrayProductLessThanK(nums, 18) << "\n";
    return 0;
}
