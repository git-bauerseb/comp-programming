#include <iostream>
#include <vector>
#include <cstring>

using namespace std;


// const int M_SIZE = 30;

// short dp[M_SIZE][M_SIZE][M_SIZE][M_SIZE];
// bool reachable[M_SIZE][M_SIZE];

/*
// Solution (ALMOST) working
class Solution {
    public:
        int cherryPickup(vector<vector<int>>& grid) {
            const int n = grid.size();

            if (n == 1) return grid[0][0] == 1 ? 1 : 0;

            memset(dp, 0, sizeof(dp));
            memset(reachable, false, sizeof(reachable));

            reachable[0][0] = true;

            for (int y1 = 0; y1 < n; ++y1) {
                for (int x1 = 0; x1 < n; ++x1) {

                    if (grid[y1][x1] != -1) {
                        reachable[y1][x1] |= (y1 > 0 && reachable[y1-1][x1]);
                        reachable[y1][x1] |= (x1 > 0 && reachable[y1][x1-1]);
                    }

                    for (int y2 = 0; y2 < n; ++y2) {
                        for (int x2 = 0; x2 < n; ++x2) {
                            short& entry = dp[y1][x1][y2][x2];

                            if (grid[y1][x1] == -1 || grid[y2][x2] == -1) {
                                continue;
                            }


                            // If one of the players at end, only move other one

                            // Player 1 at end
                            if (y1 == 0 && x1 == 0) {
                                entry = grid[y1][x1];
                            } else if (y2 == 0 && x2 == 0) {
                                entry = grid[y2][x2];
                            } else {

                            if (y1 > 0 && x2 > 0 && grid[y1-1][x1] != -1 && grid[y2][x2-1] != -1)
                                entry = dp[y1-1][x1][y2][x2-1];

                            if (y1 > 0 && y2 > 0 && grid[y1-1][x1] != -1 && grid[y2-1][x2] != -1)
                                entry = max(entry, dp[y1-1][x1][y2-1][x2]);

                            if (x1 > 0 && x2 > 0 && grid[y1][x1-1] != -1 && grid[y2][x2-1] != -1)
                                entry = max(entry, dp[y1][x1-1][y2][x2-1]);

                            if (x1 > 0 && y2 > 0 && grid[y1][x1-1] != -1 && grid[y2-1][x2] != -1)
                                entry = max(entry, dp[y1][x1-1][y2-1][x2]);
                            
                            if (y1 == y2 && x1 == x2) {
                                entry += grid[y1][x1];
                            } else {
                                entry += grid[y1][x1] + grid[y2][x2];
                            }

                            }
                        }
                    }
                }
            }

            return max(0, (int)dp[n-1][n-1][n-1][n-1]);
        }
};
*/

const int S_MAX = 20;
int memo[S_MAX][S_MAX][S_MAX][S_MAX];

const int INF = 6000;

class Solution {
    public:
        int cherryPickup(vector<vector<int>>& grid) {
            const int n = grid.size();
            m_grid = grid;
            m_n = m_grid.size();

            fill(&memo[0][0][0][0],
                    &memo[0][0][0][0] + sizeof(memo) / sizeof(memo[0][0][0][0]),
                    -INF);

            return max(0,topDown(0, 0, 0, 0));
        }

        int topDown(int x1, int y1, int x2, int y2) {
            if (x1 >= m_n || y1 >= m_n || x2 >= m_n || y2 >= m_n
                          || m_grid[y1][x1] == -1 || m_grid[y2][x2] == -1) {
                return -INF; 
            }

            int& entry = memo[y1][x1][y2][x2];

            if (entry != -INF) { return entry; }

            if (x1 == m_n-1 && y1 == m_n-1) {entry = m_grid[y2][x2]; return entry;}
            if (x2 == m_n-1 && y2 == m_n-1) {entry = m_grid[y1][x1]; return entry;}

            int p = 0;

            if (y1 == y2 && x1 == x2) {
                p += m_grid[y1][x1];
            } else {
                p += m_grid[y1][x1] + m_grid[y2][x2];
            }

            entry = p + max(
                        max(topDown(x1+1, y1, x2+1, y2), topDown(x1+1, y1, x2, y2+1)),
                        max(topDown(x1, y1+1, x2, y2+1), topDown(x1, y1+1, x2+1, y2))
                    );

            return entry;
        }

    private:
        int m_n;
        vector<vector<int>> m_grid;
};

int main() {

    /*
    vector<vector<int>> grid = {
        {1,1,1,1,0,0,0},
        {0,0,0,1,0,0,0},
        {0,0,0,1,0,0,1},
        {1,0,0,1,0,0,0},
        {0,0,0,1,0,0,0},
        {0,0,0,1,0,0,0},
        {0,0,0,1,1,1,1}
    };
    */

    
    vector<vector<int>> grid = {
        {1,-1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,-1,1,1},
        {1,1,1,1,1,1,1,1,-1,-1,1,1,1,1,1,1,1,1,1,-1},
        {1,-1,-1,-1,1,1,1,1,1,1,1,1,1,1,-1,1,1,1,1,1},
        {-1,1,1,1,0,1,1,1,1,1,1,1,-1,1,1,-1,1,-1,1,1},
        {1,1,1,1,1,-1,-1,1,1,1,-1,1,-1,1,-1,1,1,1,-1,-1},
        {1,1,1,1,1,-1,1,1,1,1,1,1,1,-1,1,1,1,1,-1,1},
        {1,1,1,1,-1,1,1,1,1,1,1,-1,1,1,1,1,-1,1,1,1},
        {1,1,1,1,-1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,-1},
        {-1,1,1,1,1,1,1,-1,1,-1,1,-1,1,1,1,1,1,1,1,-1},
        {1,1,1,1,1,1,0,1,1,1,1,1,1,1,1,0,1,1,1,1},
        {-1,1,-1,1,-1,-1,-1,1,1,1,1,-1,-1,1,-1,1,0,1,1,1},
        {-1,1,1,1,1,1,1,1,1,1,1,-1,1,1,1,-1,1,1,1,1},
        {1,1,1,1,1,1,1,1,1,1,1,1,-1,1,1,-1,1,1,-1,-1},
        {1,1,1,1,1,1,1,1,-1,1,1,1,1,1,1,1,1,1,1,1},
        {0,1,1,-1,1,1,1,1,-1,1,-1,1,1,1,-1,-1,-1,1,1,1},
        {1,-1,1,1,1,-1,1,1,1,-1,1,-1,1,1,1,1,1,1,-1,1},
        {1,1,1,-1,1,1,1,-1,1,1,1,1,1,-1,1,1,1,1,1,1},
        {1,1,1,1,-1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
        {1,1,-1,1,1,-1,1,1,1,1,-1,1,1,1,1,1,1,-1,0,1},
        {-1,1,1,1,1,1,1,1,1,1,1,1,1,1,-1,1,1,1,-1,1}
    };
    

    /*
    vector<vector<int>> grid = 
    {{1,1,-1,1,1,1,0,1,1,-1,-1,1,1,-1,1,1,1,1,0,1},
{1,1,1,0,1,1,0,1,0,1,-1,1,1,1,1,1,1,0,1,1},
{1,1,1,1,1,1,1,0,1,1,-1,-1,-1,1,1,1,-1,1,-1,1},
{1,1,1,-1,0,1,1,1,1,1,1,1,1,0,1,-1,-1,1,1,1},
{1,-1,-1,1,1,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
{1,1,1,0,1,1,1,1,1,-1,1,1,0,1,1,1,1,1,1,1},
{0,1,1,-1,1,1,1,1,1,1,1,1,1,1,1,1,0,1,1,1},
{1,1,-1,1,1,1,-1,1,0,1,1,1,1,1,1,-1,1,1,1,1},
{0,-1,1,1,1,-1,1,1,1,-1,1,1,1,1,1,1,-1,1,1,1},
{1,1,-1,1,1,1,0,1,1,1,1,0,1,1,-1,0,1,0,-1,1},
{0,1,1,1,1,1,1,1,1,1,1,1,1,0,1,1,0,1,-1,0},
{1,1,1,1,1,1,-1,1,0,1,1,1,1,-1,1,1,1,0,1,1},
{1,1,1,1,-1,-1,1,-1,1,1,1,1,1,1,1,1,1,-1,1,1},
{-1,1,1,1,1,-1,1,1,1,1,1,1,-1,1,0,0,1,0,1,1},
{0,1,-1,1,1,-1,1,1,1,-1,1,1,1,1,1,1,0,-1,1,1},
{1,1,1,-1,1,1,1,-1,1,-1,1,1,1,1,1,1,1,1,1,-1},
{1,-1,1,1,1,1,1,1,1,1,0,-1,1,1,1,1,1,1,1,-1},
{1,1,1,-1,0,1,0,1,1,0,1,1,1,1,1,1,-1,0,1,1},
{1,1,-1,0,-1,1,1,-1,-1,1,1,-1,1,1,1,1,-1,-1,0,1},
{-1,0,0,1,1,1,1,1,-1,-1,1,1,1,0,1,0,0,1,-1,1}};
    */

    Solution solution{};
    int m = solution.cherryPickup(grid);
    cout << m << "\n";

    return 0;
}
