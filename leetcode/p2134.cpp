#include <iostream>
#include <vector>

using namespace std;

class Solution {
    public:
        int minSwaps(vector<int>& nums) {
            const int n = nums.size();
            vector<int> pref(n);
            pref[0] = nums[0];

            for (int i = 1; i < n; ++i) {
                pref[i] = pref[i-1] + nums[i];
            }

            // t := Total number of 1s
            int t = pref[n-1];

            if (t == n || t == 0) {
                return 0;
            }

            int m = 1 << 22;

            for (int i = t-1; i < n; ++i) {
                // Number of swaps necessary to fill current window
                // i-t, ..., i with 1s
                int cOnes = pref[i] - (i-t < 0 ? 0 : pref[i-t]);
                m = min(m, t - cOnes);
            }

            // Check cyclic arrays
            // l elements are at front, t - l at back
            for (int l = 1; l < t; ++l) {
                int ones = pref[l-1];
                ones += (pref[n-1] - (n-1-(t-l) < 0 ? 0 : pref[n-1-(t-l)]));

                m = min(m, t - ones);
            }

            return m;
        }
};

int main() {
    vector<int> nums{0,1,0,1,1,0,0};
    Solution solution{};

    cout << solution.minSwaps(nums) << "\n";
    return 0;
}
