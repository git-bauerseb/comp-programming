#include <iostream>
#include <vector>

#define MOD 1'000'000'007

using namespace std;

class Solution {
    public:
        int numberOfPaths(vector<vector<int>>& grid, int k) {
            const int m = grid.size();
            const int n = grid[0].size();
            vector<vector<vector<long>>> dp(m, vector<vector<long>>(n, vector<long>(k, 0)));

            dp[0][0][grid[0][0] % k] = 1;
                for (int i = 0; i < m; ++i) {
                    for (int j = 0; j < n; ++j) {
                        for (int rem = 0; rem < k; ++rem) {
                            if (i == 0 && j == 0) continue;
                            if (i > 0) {
                                // (x + grid[i][j]) % k == rem
                                // x == (rem - grid[i][j]) % k
                                int x = (rem - (grid[i][j]%k) + k) % k;
                                dp[i][j][rem] = dp[i-1][j][x];
                            }

                            if (j > 0) {
                                int x = (rem - (grid[i][j]%k) + k) % k;
                                dp[i][j][rem] = (dp[i][j][rem] + dp[i][j-1][x]) % MOD;
                            }
                        }
                    }
                }

            return dp[m-1][n-1][0];
        }
};

int main() {

    vector<vector<int>> grid{
        {1,0},
    };

    Solution solution{};
    int num = solution.numberOfPaths(grid, 2);
    cout << num << "\n";
    return 0;
}
