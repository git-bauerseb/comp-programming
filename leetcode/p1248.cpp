#include <iostream>
#include <vector>
using namespace std;

class Solution {
    public:
        int atmostK(vector<int>& nums, int k) {
            const int n = nums.size();

            int r = 0;
            int l = 0;

            int odd = 0;
            int result = 0;

            for (; r < n; ) {
                odd += nums[r] % 2 == 1;

                while (odd > k) {
                    odd -= nums[l] % 2 == 1;
                    l++;
                }

                result += r - l + 1;
                r++;
            }

            return result;
        }

        int numberOfSubarrays(vector<int>& nums, int k) {
            int r = atmostK(nums, k);
            r -= atmostK(nums, k-1);
            return r;
        }
};

int main() {

    vector<int> nums{2,2,2,1,2,2,1,2,2,2};

    Solution solution{};
    int c = solution.numberOfSubarrays(nums, 2);
    cout << c << "\n";

    return 0;
}
