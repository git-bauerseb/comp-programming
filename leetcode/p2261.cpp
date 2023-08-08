#include <iostream>
#include <vector>
using namespace std;

class Solution {
    public:
        int countDistinct(vector<int>& nums, int k, int p) {
            const int n = nums.size();

            int r = 0;
            int l = 0;

            int result = 0;
            int curr = 0;

            for (; r < n; ) {
                curr += nums[r] % p == 0;

                while (l < r && curr > k) {
                    curr -= nums[l] % p == 0;
                    l++;
                }

                result += r - l + 1;
                r++;
            }

            return result;
        }
};

int main() {

    vector<int> nums{2,3,3,2,2};

    Solution solution{};
    int c = solution.countDistinct(nums, 2, 2);
    cout << c << "\n";

    return 0;
}
