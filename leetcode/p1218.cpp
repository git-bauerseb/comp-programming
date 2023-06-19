#include <iostream>
#include <vector>

using namespace std;


// Time complexity: O(n)


const int OFFSET = 10'000;

class Solution {
    public:
        int longestSubsequence(vector<int>& arr, int difference) {
            const int n = arr.size();
            vector<int> dp(2*10'005, 0);
            int m_ = -1;

            for (int i = 0; i < n; ++i) {
                int prev = arr[i] - difference;

                if (prev + OFFSET >= 0 && prev + OFFSET < dp.size()) {
                    dp[arr[i] + OFFSET] = dp[prev + OFFSET] + 1;
                    m_ = max(m_, dp[arr[i] + OFFSET]);
                } else {
                    dp[arr[i] + OFFSET] = 1;
                }
            }

            return m_;
        }
};

int main() {
    vector<int> nums{1,5,7,8,5,3,4,2,1};

    Solution solution{};
    int l = solution.longestSubsequence(nums, -2);
    cout << l << "\n";
    return 0;
}
