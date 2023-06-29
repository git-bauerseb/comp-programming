#include <iostream>
#include <vector>
#include <string>
#include <cstring>

using namespace std;

int dp[50'003];

// invalid value
// if this value present in dp, then it's not initialized
const int I_VALUE = 50'000'001;

class Solution {
    public:
        string stoneGameIII(vector<int>& stoneValue) {
            const int n = stoneValue.size();

            vector<int> prefSum(n, 0);
            prefSum[0] = stoneValue[0];
            for (int i = 1; i < n; ++i) {
                prefSum[i] = prefSum[i-1] + stoneValue[i];
            }

            fill(dp, dp + sizeof(dp) / sizeof(int), I_VALUE);
            int aliceMax = rec(prefSum, 0);

            if (prefSum[n-1] % 2 == 0 && aliceMax == prefSum[n-1] / 2) {
                return "Tie";
            } else if (aliceMax >= (prefSum[n-1]+1)/2) {
                return "Alice";
            } else {
                return "Bob";
            }
        }

        int rec(vector<int>& values, int start) {
            const int n = values.size();
            if (start == n-1) { return values[n-1] - (start == 0 ? 0 : values[start-1]); }
            if (start >= n) { return 0; }

            int rem = n - start;
            int& entry = dp[start];

            if (entry != I_VALUE) { return entry; }

            int mValue = -I_VALUE;

            for (int take = 1; take <= min(rem, 3); ++take) {
                int cValue = values[start + take - 1] - (start == 0 ? 0 : values[start-1]);
                int mVal = 1 << 28;

                // Enemy now can also take values
                for (int eTake = 1; eTake <= min(rem, 3); ++eTake) {
                    int minPlayerR2 = rec(values, start + take + eTake);
                    mVal = min(mVal, minPlayerR2);
                }

                mValue = max(mValue, cValue + mVal);
            }

            entry = mValue;
            return entry;
        }
};

int main() {
    vector<int> nums{-1,-2,3,1};

    Solution solution{};
    string w = solution.stoneGameIII(nums);
    cout << w << "\n";
    return 0;
}
