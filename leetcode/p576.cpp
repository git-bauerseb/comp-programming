#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

#define MOD 1'000'000'007

class Solution {

    public:
        int findPaths(int m, int n, int maxMove, int startRow, int startColumn) {
            ++startRow;
            ++startColumn;


            long dp[m+2][n+2][maxMove+1];
            memset(dp, 0, sizeof(dp));

            dp[startRow][startColumn][0] = 1;

            for (int moves = 1; moves < maxMove; ++moves) {
                for (int y = 1; y <= m; ++y) {
                    for (int x = 1; x <= n; ++x) {
                        if (inBound(x,y-1,m,n))
                            dp[y][x][moves] = (dp[y][x][moves] + dp[y-1][x][moves-1]) % MOD;
                        if (inBound(x,y+1,m,n))
                            dp[y][x][moves] = (dp[y][x][moves] + dp[y+1][x][moves-1]) % MOD;
                        if (inBound(x-1,y,m,n))
                            dp[y][x][moves] = (dp[y][x][moves] + dp[y][x-1][moves-1]) % MOD;
                        if (inBound(x+1,y,m,n))
                            dp[y][x][moves] = (dp[y][x][moves] + dp[y][x+1][moves-1]) % MOD;
                    }
                }
            }


            long totalCount = 0;


            // Count number of ways outside grid
            for (int x = 1; x <= n; ++x) {
                for (int move = 0; move < maxMove; ++move) {
                    totalCount = (totalCount + dp[1][x][move]) % MOD;
                    totalCount = (totalCount + dp[m][x][move]) % MOD;
                }
            }

            for (int y = 1; y <= m; ++y) {
                for (int move = 0; move < maxMove; ++move) {
                    totalCount = (totalCount + dp[y][1][move]) % MOD;
                    totalCount = (totalCount + dp[y][n][move]) % MOD;
                }
            }
            return totalCount;
        }

        bool inBound(int x, int y, int m, int n) {
            return (0 <= x && x <= n+1)
                && (0 <= y && y <= m+1);
        }
};

int main() {
    Solution solution{};
    int outside = solution.findPaths(2,2,2,0,0);
    cout << outside << "\n";
    return 0;
}
