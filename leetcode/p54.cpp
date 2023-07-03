#include <iostream>
#include <vector>

using namespace std;

class Solution {

    public:
        vector<int> spiralOrder(vector<vector<int>>& matrix) {
            const int m = matrix.size();
            const int n = matrix[0].size();

            vector<vector<bool>> f(m, vector<bool>(n, true));

            int free = m*n;

            int x = -1;
            int y = 0;

            vector<int> elements;

            while (free > 0) {
                for (auto& dir : dirs) {
                    x += dir[0]; y += dir[1];
                    while (x >= 0 && x < n 
                            && y >= 0 && y < m
                            && f[y][x]) {
                        elements.push_back(matrix[y][x]);
                        f[y][x] = false;
                        free--;
                        x += dir[0];
                        y += dir[1];
                    }

                    
                    x -= dir[0];
                    y -= dir[1];
                }
            }

            return elements;
        }

        vector<vector<int>> dirs = {
            {1,0},  // right
            {0,1},  // down
            {-1,0}, // left
            {0,-1}  // up
        };
};

int main() {

    vector<vector<int>> nums = {
        {1,2,3,4},
        {5,6,7,8},
        {9,10,11,12}
    };

    Solution solution{};
    auto el = solution.spiralOrder(nums);

    for (auto& e : el) cout << e << " ";
    cout << "\n";

    return 0;
}
