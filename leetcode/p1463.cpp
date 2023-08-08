#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>

using namespace std;

const int N_MAX = 30;
int dp[N_MAX][N_MAX][N_MAX][N_MAX];

int n, m;

class Solution {

    public:
        vector<vector<int>> m_grid;

        int cherryPickup(vector<vector<int>>& grid) {
            m = grid.size();
            n = grid[0].size();

            fill(&dp[0][0][0][0], &dp[0][0][0][0] + (sizeof(dp) / sizeof(int)), -1);
            m_grid = grid;


            // dp[y1][x1][y2][x2] := 
            //      (x1, y1) = coordinates of robot 1
            //      (x2, y2) = coordinates of robot 2
            rec(0, 0, 0, n-1);
        
            int ma = 0;

            for (int x1 = 0; x1 < n; ++x1)
                for (int x2 = 0; x2 < n; ++x2)
                    ma = max(ma, dp[m-1][x1][m-1][x2]);
            return ma;
        }

        int rec(int y1, int x1, int y2, int x2) {
            if (y1 >= m || y2 >= m) {
                return 0;
            }

            int& entry = dp[y1][x1][y2][x2];
            if (entry >= 0) return entry;


            // Total: 6 possibilities
            int maxP = 0;

            int toAdd = m_grid[y1][x1];            
            if (!(x1 == x2 && y1 == y2)) { 
                toAdd += m_grid[y2][x2];
            }

            for (int first = -1; first <= 1; ++first) {
                for (int second = -1; second <= 1; ++second) {
                    if (x1+first >= 0 && x1+first < n &&
                        x2+second >= 0 && x2+second < n) {
                        maxP = max(maxP, rec(y1 + 1, x1+first, y2 + 1, x2+second));
                    
                    }
                }
            }

            entry = maxP + toAdd;
            return maxP;
        }
};

int main() {

    vector<vector<int>> grid = {
        {3,1,1},
        {2,5,1},
        {1,5,5},
        {2,1,1}
    };


    Solution solution{};
    int p = solution.cherryPickup(grid);
    cout << p << "\n";
    return 0;
}
