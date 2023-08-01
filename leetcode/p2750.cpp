#include <iostream>
#include <vector>

using namespace std;

const int MOD = 1'000'000'007;

class Solution {
    public:
        int numberOfGoodSubarraySplits(vector<int>& nums) {
            const int  n = nums.size();

            int r = 0;
            int prev = -1;

            long long res = 1;

            for (; r < n; ++r) {
                
                if (nums[r] == 1) {
                    if (prev >= 0) {
                        int dist = r - prev;
                        res = (res * dist) % MOD;
                    }

                    prev = r;
                }

            }

            return prev < 0 ? 0 : res;
        }
};

int main() {

    // 0 1 0 0 1 0 0 1
    //
    // 0 1 | 0 0 1 | 0 0 1
    // 0 1 0 | 0 1 | 0 0 1
    // 0 1 0 0 | 1 | 0 0 1
    //
    // 0 1 | 0 0 1 0 | 0 1

    vector<int> nums{1,1,1};
    Solution solution{};

    int n = solution.numberOfGoodSubarraySplits(nums);
    cout << n << "\n";

    return 0;
}
