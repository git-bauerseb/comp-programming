#include <iostream>
#include <vector>

using namespace std;

class Solution {

    public:
        int numTrees(int n) {
            vector<int> dp(n+1, 0);

            dp[0] = dp[1] = 1;
            for (int i = 2; i <= n; ++i) {
                for (int l = 0; l < i; ++l) {
                    dp[i] += dp[l]*dp[i-1-l];
                }
            }

            return dp[n];
        }
};

int main() {

    Solution solution{};
    int n = solution.numTrees(3);
    cout << n << "\n";
    return 0;
}
