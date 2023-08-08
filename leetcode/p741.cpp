#include <iostream>
#include <vector>

using namespace std;

/*

    Proof (NOT A PROOF):

    max(down + up) = max(down) + max(up | using cherries not picked in down phase)

    1) max(down + up) > max(down) + ...
        => there exists a cherry not picked in either down/up phase
        => if not picked in down phase, it can be picked in up phase
        => if not picked in up phase, then can be added to down phase


    WRONG IDEA:

    Idea wrong (Phases are not independent):
        - Maximizing down and then maximizing up phase is not optimal
        - Consider testcase
            [1,1,1,1,0,0,0],
            [0,0,0,1,0,0,0],
            [0,0,0,1,0,0,1],
            [1,0,0,1,0,0,0],
            [0,0,0,1,0,0,0],
            [0,0,0,1,0,0,0],
            [0,0,0,1,1,1,1]
*/
class Solution {

    public:
        int cherryPickup(vector<vector<int>>& grid) {
            const int n = grid.size();

            // Special case
            if (n == 1) return grid[0][0] == 1 ? 1 : 0;
            
            int numCherries = 0;

            // Store (maxCherries, predecessor)
            // predecessor:
            //  -1 - left
            //  1  - up
            vector<vector<pair<int,int>>> dp(n, vector<pair<int,int>>(n, {-1, 0}));
            dp[0][0].first = grid[0][0] == -1 ? -1 : grid[0][0] == 1 ? 1 : 0;
            for (int i = 0; i < n; ++i) {
                for (int j = 0; j < n; ++j) {
                    if (grid[i][j] == -1) {continue;}

                    if (i > 0 && dp[i-1][j].first >= 0) {
                        dp[i][j].first = dp[i-1][j].first + (grid[i][j] == 1 ? 1 : 0);
                        dp[i][j].second = 1;
                    }
                    
                    if (j > 0 && dp[i][j-1].first >= 0) {
                        if (dp[i][j-1].first + (grid[i][j] == 1 ? 1 : 0) > dp[i][j].first) {
                            dp[i][j].first = dp[i][j-1].first + (grid[i][j] == 1 ? 1 : 0);
                            dp[i][j].second = -1;
                        }
                    }
                }
            }
 
            numCherries = dp[n-1][n-1].first;

            if (numCherries <= 0) return 0;

            // Pick cherries along optimal path
            int x = n-1;
            int y = n-1;

            while (x >= 0 && y >= 0) {
                int pred = dp[y][x].second;
                if (grid[y][x] == 1) grid[y][x] = 0;
                if (pred == -1) {x--;}
                else {y--;}
            }


            // Up phase
            vector<vector<int>> dp2(n, vector<int>(n, 0));

            for (int i = n-1; i >= 0; --i) {
                for (int j = n-1; j >= 0; --j) {
                    if (grid[i][j] == -1) continue;
                    if (i < n-1)
                        dp2[i][j] = dp2[i+1][j];
                    if (j < n-1)
                        dp2[i][j] = max(dp2[i][j+1], dp2[i][j]);

                    if (grid[i][j] == 1)
                        dp2[i][j]++;
                }
            }

            return dp2[0][0] + numCherries;
        }
};

int main() {
    vector<vector<int>> grid {
        {1,1,1,1,0,0,0},
        {0,0,0,1,0,0,0},
        {0,0,0,1,0,0,1},
        {1,0,0,1,0,0,0},
        {0,0,0,1,0,0,0},
        {0,0,0,1,0,0,0},
        {0,0,0,1,1,1,1}
    };

    Solution solution{};
    int n = solution.cherryPickup(grid);
    cout << n << "\n";

    return 0;
}
