#include <iostream>
#include <vector>

using namespace std;

// Bitset DP
//
// dp[mask][i] := Minimum XOR sum when using all elements in mask
//                and ending with ith element
class Solution {
    public:
        int minimumXORSum(vector<int>& n1, vector<int>& n2) {
            const int n = n1.size();
            const int INF = 1e9;
            vector<vector<int>> dp(1 << n, vector<int>(n, INF));

            // Base case
            for (int i = 0; i < n; ++i) {
                dp[1 << i][i] = n1[0] ^ n2[i];
            }

            for (int mask = 0; mask < (1 << n); ++mask) {
                for (int i = 0; i < n; ++i) {
                    if ((mask & (1 << i))) {
                        for (int j = 0; j < n; ++j) {
                            if (j != i && (mask & (1 << j))) {
                                int elements = __builtin_popcount(mask);
                                int v = n1[elements-1] ^ n2[i];
                                dp[mask][i] = min(dp[mask][i], dp[mask^(1<<i)][j] + v);
                            }
                        }
                    }
                }
            }

            int answer = 1e9;
            for (int i = 0; i < n; ++i) {
                answer = min(answer, dp[(1 << n)-1][i]);
            }
            return answer;
        }
};

int main() {
    vector<int> n1{1,0,3};
    vector<int> n2{5,3,4};
    Solution solution{};
    cout << solution.minimumXORSum(n1, n2) << "\n";
    return 0;
}
