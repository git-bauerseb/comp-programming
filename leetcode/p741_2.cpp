#include <iostream>
#include <vector>

using namespace std;

// dp[y][x][0] := Max. number of picking up cherries when moving down (right/down)
//                when starting at position [y][x]
// dp[y][x][1] := Max. number of picking up cherries when moving up (left/up)
//                when starting at position [y][x]

/*
class Solution {
    public:
        int cherryPickup(vector<vector<int>>& grid) {
            const int n = grid.size();
            vector<vector<vector<int>>> dp(n, vector<vector<int>>(n, vector<int>(2,0)));
            vector<vector<bool>> reach(n, vector<bool>(n, false));

            dp[n-1][n-1][0] = grid[n-1][n-1] == 1;

            for (int y = n-1; y >= 0; --y) {
                for (int x = n-1; x >= 0; --x) {
                    if (grid[y][x] == -1) continue;                    
                    int rMax = y == n-1 || grid[y+1][x] == -1 ? 0 : dp[y+1][x][0];
                    int bMax = x == n-1 || grid[y][x+1] == -1 ? 0 : dp[y][x+1][0];
                    dp[y][x][0] = max(rMax, bMax) + grid[y][x];

                }
            }

            dp[0][0][1] = grid[0][0] == 1;
            reach[0][0] = true;
            for (int y = 0; y < n; ++y) {
                for (int x = 0; x < n; ++x) {
                    if (grid[y][x] == -1) continue;
                    
                    reach[y][x] = reach[y][x] || (y == 0 ? false : reach[y-1][x]);
                    reach[y][x] = reach[y][x] || (x == 0 ? false : reach[y][x-1]);

                    int uMax = y == 0 || grid[y-1][x] == -1 ? 0 : dp[y-1][x][1];
                    int lMax = x == 0 || grid[y][x-1] == -1 ? 0 : dp[y][x-1][1];
                    dp[y][x][1] = max(uMax, lMax) + grid[y][x];
                }
            }

            if (!reach[n-1][n-1]) return 0;

            int tMax = -1;
            for (int y = 0; y < n; ++y) {
                for (int x = 0; x < n; ++x) {
                    if (grid[y][x] == -1) continue;
  
                    for (int k = x+1; k < n; ++k) {
                        int first = dp[y][x][0];
                        int second = (x == n-1 ? 0 : dp[y][x+1][1] - (k == n-1 ? 0 : dp[y][k][1]));
                        tMax = max(tMax, first + second);
                    }
                }
            }

            return tMax;
        }
};
*/


// Key Idea:
//  - Moving from (0,0) to (n-1,n-1) to (0,0)
//    is like moving from (0,0) to (n-1,n-1) twice
//    => 4D DP problem
//     - dp[y1][x1][y2][x2] := max value cherries that can be picked up
//          when first person moves to (x1,y1) and second person moves to (x2,y2)
//
//      - only one cherry can be picked
//          => if grid[y][x] == 1, and x1 == x2 && y1 == y2 => give it to first person
class Solution {
    public:
        int cherryPickup(vector<vector<int>>& grid) {
            const int n = grid.size();

            vector<vector<vector<vector<int>>>> dp(n, vector<vector<vector<int>>>(n, vector<vector<int>>(n, vector<int>(n, 0))));

            for (int y1 = 0; y1 < n; ++y1) {
                for (int x1 = 0; x1 < n; ++x1) {
                    for (int y2 = 0; y2 < n; ++y2) {
                        for (int x2 = 0; x2 < n; ++x2) {
                            int first = 0;
                            
                            if (grid[y1][x1] != -1) {
                                first = (y1 == 0) ? 0 : dp[y1-1][x1][y2][x2];
                                first = max(first, (x1 == 0) ? 0 : dp[y1][x1-1][y2][x2]);
                                first += (grid[y1][x1] == 1);
                            }

                            int second = 0;
                            if (grid[y2][x2] != -1) {
                                second = (y2 == 0) ? 0 : dp[y1][x1][y2-1][x2];
                                second = max(second, (x2 == 0) ? 0 : dp[y1][x1][y2][x2-1]);
                                second += (grid[y2][x2] == 1);
                            }

                            if (grid[y1][x1] == -1 && grid[y2][x2] == -1) dp[y1][x1][y2][x2] = 0;
                            else if (grid[y1][x1] == -1) dp[y1][x1][y2][x2] = second;
                            else if (grid[y2][x2] == -1) dp[y1][x1][y2][x2] = first;
                            else {
                                dp[y1][x1][y2][x2] = first + second - ((y1 == y2 && x2 == x1 && grid[y1][x1] == 1) ? 1 : 0);
                            }

                        }
                    }
                }
            }
            return dp[n-1][n-1][n-1][n-1];
        }
};

int main() {

    vector<vector<int>> grid = {
        {1,1,1,1,0,0,0},
        {0,0,0,1,0,0,0},
        {0,0,0,1,0,0,1},
        {1,0,0,1,0,0,0},
        {0,0,0,1,0,0,0},
        {0,0,0,1,0,0,0},
        {0,0,0,1,1,1,1}
    };


    Solution solution{};
    int s = solution.cherryPickup(grid);
    cout << s << "\n";


    return 0;
}
