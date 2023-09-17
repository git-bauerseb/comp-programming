#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    const int INF = 1e9;
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        const int m = mat.size();
        const int n = mat[0].size();

        vector<vector<int>> lu(m, vector<int>(n,INF));
        vector<vector<int>> rd(m, vector<int>(n,INF));

        for (int y = 0; y < m; ++y) {
            for (int x = 0; x < n; ++x) {
                
                // Left-up update
                if (mat[y][x] == 0) {lu[y][x] = 0;}
                else {
                    if (y > 0) {lu[y][x] = min(lu[y][x], 1 + lu[y-1][x]);}
                    if (x > 0) {lu[y][x] = min(lu[y][x], 1 + lu[y][x-1]);}
                }

                const int ym = m - 1 - y;
                const int xm = n - 1 - x;

                // Right-down update
                if (mat[ym][xm] == 0) {rd[ym][xm] = 0;}
                else {
                    if (ym < m-1) {rd[ym][xm] = min(rd[ym][xm], rd[ym+1][xm] + 1);}
                    if (xm < n-1) {rd[ym][xm] = min(rd[ym][xm], rd[ym][xm+1] + 1);}
                }
            }
        }

        vector<vector<int>> output(m, vector<int>(n,INF));
        for (int y = 0; y < m; ++y) {
            for (int x = 0; x < n; ++x) {
                output[y][x] = min(rd[y][x], lu[y][x]);
                for (auto& d : dirs) {
                    int nx = d[0] + x;
                    int ny = d[1] + y;
                    if (nx >= 0 && nx < n && ny >= 0 && ny < m) {
                        output[y][x] = min(output[y][x], 1 + min(rd[ny][nx], lu[ny][nx]));
                    }
                }
            }
        }

        return output;
    }

    vector<vector<int>> dirs = {{-1,0},{1,0},{0,-1},{0,1}};
};

/*
 
EXPECTED
========

[[0,0,1,0,1,2,1,0,1,2],
[1,1,2,1,0,1,1,1,2,3],
[2,1,2,1,1,0,0,0,1,2],
[1,0,1,0,1,1,1,0,1,2],
[0,0,1,1,1,0,1,1,2,3],
[1,0,1,2,1,1,1,2,1,2],
[1,1,1,1,0,1,0,1,0,1],
[0,1,0,0,0,1,0,0,1,2],
[1,1,1,0,1,1,0,1,0,1],
[1,0,1,1,1,0,1,2,1,0]] 

OUTPUT
======

0 0 1 0 1 2 1 0 1 2 
1 1 2 1 0 1 1 1 2 3 
2 1 2 1 1 0 0 0 1 2 
1 0 1 0 1 1 1 0 1 2 
0 0 1 1 1 0 1 1 2 3 
1 0 1 2 1 1 1 2 1 4 
1 1 1 1 0 1 0 1 0 1 
0 1 0 0 0 1 0 0 1 2 
1 1 1 0 1 1 0 1 0 1 
1 0 1 1 1 0 1 2 1 0 

*/

int main() {
    vector<vector<int>> mat = {	
	    {0,0,1,0,1,1,1,0,1,1},
	    {1,1,1,1,0,1,1,1,1,1},
	    {1,1,1,1,1,0,0,0,1,1},
	    {1,0,1,0,1,1,1,0,1,1},
	    {0,0,1,1,1,0,1,1,1,1},
	    {1,0,1,1,1,1,1,1,1,1},
	    {1,1,1,1,0,1,0,1,0,1},
	    {0,1,0,0,0,1,0,0,1,1},
	    {1,1,1,0,1,1,0,1,0,1},
	    {1,0,1,1,1,0,1,1,1,0}
    };

    Solution solution{};
    auto r = solution.updateMatrix(mat);
    
    for (auto& row : r) {
        for (auto& e : row) cout << e << " ";
        cout << "\n";
    }
    
    return 0;
}
