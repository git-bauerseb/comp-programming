#include <iostream>
#include <vector>

using namespace std;

const int MOD = 1'000'000'007;
const int OFF = 500;

class Solution {
public:
    int numberOfWays(int startPos, int endPos, int k) {
        vector<vector<int>> dp(1000 + 2*OFF + 1, vector<int>(k+1,0));
        dp[startPos + OFF][0] = 1;

        for (int step = 1; step <= k; ++step) {
            for (int pos = -500; pos <= 1500; ++pos) {
                
                int aPos = pos + OFF;
                
                if (aPos > 0) {
                    dp[aPos][step] += dp[aPos-1][step-1];
                    dp[aPos][step] %= MOD;
                }

                if (aPos < 1000 + 2*OFF) {
                    dp[aPos][step] += dp[aPos+1][step-1];
                    dp[aPos][step] %= MOD;
                }
            }
        }

        return dp[endPos + OFF][k];
    }
};

int main() {
    Solution s{};
    cout << s.numberOfWays(921,413,716) << "\n";
    return 0;
}
