#include <iostream>
#include <string>
#include <vector>
#include <cstring>

using namespace std;

class Solution {

    public:
        int longestIdealString(string s, int k) {
            const int n = s.size();
            if (k == 25) return n;

            int dp[26];
            memset(dp, 0, sizeof(dp));

            for (int i = 0; i < n; ++i) {
                int curr = s[i] - 'a';

                int mPrev = 0;

                for (int j = 0; j <= k; ++j) {
                    mPrev = max(mPrev, max(dp[max(0, curr-j)], dp[min(25,curr+j)]));
                }

                dp[curr] = mPrev + 1;
            }

            int max_len = 0;
            for (int i = 0; i < 26; ++i) {
                max_len = max(max_len, dp[i]);
            }

            return max_len;
        }
};


int main() {

    Solution solution{};
    int lon = solution.longestIdealString("acegijk", 2);

    cout << lon << "\n";

    return 0;
}
