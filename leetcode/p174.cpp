#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

/*
// dp[i][j][0] := minimum hp needed at start to go to cell (i,j)
// dp[i][j][1] := current hp when starting with dp[i][j][0]
int dp[202][202][2];

class Solution {
    public:
        int calculateMinimumHP(vector<vector<int>>& dungeon) {
            const int m = dungeon.size();
            const int n = dungeon[0].size();
            
            memset(dp, -1, sizeof(dp));
            dp[0][0][0] = dungeon[0][0] <= 0 ? -dungeon[0][0] + 1 : 0;
            dp[0][0][0] = dungeon[0][0] <= 0 ? dp[0][0][0] : dungeon[0][0];
        
            for (int i = 0; i <= m; ++i) {
                for (int j = 0; j <= n; ++j) {
                    if (i == 0 && j == 0) continue;

                    // Consider cell from above
                    if (i > 0) {
                        int minHPAbove = dp[i-1][j][0];
                        int minCurrAbove = dp[i-1][j][1];
                        
                        int curr = dungeon[i][j];

                        if (curr + minCurrAbove > 0) {
                            dp[i][j][0] = minHPAbove;
                            dp[i][j][1] = curr + minCurrAbove;
                        } else {
                            int needed = -(curr+minCurrAbove) + 1;
                            dp[i][j][0] = max(dp[i-1][j][0], needed);
                            dp[i][j][1] = 1;
                        }
                    }

                    // Consider cell from left
                    if (j > 0) {
                        int minHPLeft = dp[i][j-1][0];
                        int minCurrLeft = dp[i][j-1][1];
                        int curr = dungeon[i][j];

                        if (curr + minCurrLeft > 0) {
                            // Value already has been calculated so check
                            // if we have a better value
                            if (dp[i][j][0] > 0) {
                                dp[i][j][0] = minHPLeft;
                                dp[i][j][1] = curr + minCurrLeft;
                            } else {
                                // Value has not been set, so set it
                                dp[i][j][0] = minHPLeft;
                                dp[i][j][1] = curr + minCurrLeft;
                            }
                        } else {
                            int needed = -(curr+minCurrLeft) + 1;

                            if (dp[i][j][0] > 0) {
                                if (dp[i][j][0]) {

                                }
                            }  else {
                                dp[i][j][0] = max(dp[i][j-1][0], needed);
                                dp[i][j][1] = 1;
                            }
                        }
                    }
                }
            }

            return dp[m-1][n-1][0];
        }
};
*/

class Solution {

    public:
    int calculateMinimumHP(vector<vector<int>>& dungeon) {
    
        // Do binary search on min starting value
        int lo = 0;
        int hi = 400'002;

        while (hi - lo > 1) {
            int m = lo + (hi - lo) / 2;

            if (!existsOnlyPosPath(dungeon, m)) lo = m;
            else hi = m;
        }
    
        return hi;
    }

    bool existsOnlyPosPath(vector<vector<int>>& dungeon, int start) {
        const int m = dungeon.size();
        const int n = dungeon[0].size();
        if (dungeon[0][0] + start <= 0) return false;

        vector<vector<int>> dp(m, vector<int>(n,0));
        vector<vector<bool>> dp2(m, vector<bool>(n, false));

        dp[0][0] = dungeon[0][0] + start;
        dp2[0][0] = true;

        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (i == 0 && j == 0) continue;

                if (i > 0 && dp2[i-1][j]) {
                    dp[i][j] = dp[i-1][j] + dungeon[i][j];
                }

                if (j > 0 && dp2[i][j-1]) {
                    dp[i][j] = max(dp[i][j], dp[i][j-1] + dungeon[i][j]);
                }

                dp2[i][j] = dp[i][j] > 0;
            }
        }

        return dp2[m-1][n-1];
    }
};

int main() {

    
    vector<vector<int>> grid{{0}};

    Solution solution{};
    
    int minHP = solution.calculateMinimumHP(grid);
    cout << minHP << "\n";
    return 0;
}
