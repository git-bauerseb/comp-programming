#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

// Solution using DP
class Solution1 {
    public:
        int maxIncreasingCells(vector<vector<int>>& mat) {
            const int m = mat.size();
            const int n = mat[0].size();

            // For each value, store all coordinates where value resides
            map<int, vector<pair<int,int>>> pos;
            vector<vector<int>> dp(m, vector<int>(n, 0));

            int answer = 0;

            // Maximum length of path for a certain row/column
            vector<int> rowMax(m, 0);
            vector<int> colMax(n, 0);

            for (int r = 0; r < m; ++r) {
                for (int c = 0; c < n; ++c) {
                    pos[mat[r][c]].push_back({r,c});
                }
            }

            for (auto it = pos.begin(); it != pos.end(); ++it) {
                for (auto& element: it->second) {
                    int r = element.first;
                    int c = element.second;
                    dp[r][c] = max(rowMax[r], colMax[c]) + 1;
                    answer = max(answer, dp[r][c]);
                }

                for (auto& element: it->second) {
                    int r = element.first;
                    int c = element.second;
                    rowMax[r] = max(rowMax[r], dp[r][c]);
                    colMax[c] = max(colMax[c], dp[r][c]);
                }
            }

            return answer;
        }
};

// Solution using DFS + Binary Search + DP
class Solution2 {
public:
    int answer;
        
    vector<vector<int>> rowSorted;
    vector<vector<int>> colSorted;
    vector<vector<int>> dp;

    vector<vector<int>> mat;
    int calls = 0;

    int dfs(int x, int y) {
        int cIdx = (int) (lower_bound(rowSorted[y].begin(), rowSorted[y].end(), -1,
                [&](const int element, const int value) {
                    return mat[y][element] < mat[y][x];
                }) - rowSorted[y].begin());

        int rIdx = (int) (lower_bound(colSorted[x].begin(), colSorted[x].end(), -1,
                [&](const int element, const int value) {
                    return mat[element][x] < mat[y][x];
                }) - colSorted[x].begin());

        int first = 0;
        int second = 0;

        // rIdx points to first element >= current => 
        // rIdx-1 last element < current
        if (cIdx > 0) {
            int cX = rowSorted[y][cIdx-1];
            int cY = y;
            int initial = mat[cY][cX];

            while (cIdx > 0 && mat[cY][cX] == initial) {
                cX = rowSorted[y][cIdx-1];
                cY = y;

                if (dp[cY][cX] == -1) {first = max(first, dfs(cX, cY));}
                else {first = max(first, dp[cY][cX]);}
                cIdx--;
            }
        }

        // Same as rIdx
        if (rIdx > 0) {
            int cX = x;
            int cY = colSorted[x][rIdx-1];
            int initial = mat[cY][cX];

            while (rIdx > 0 && mat[cY][cX] == initial) {
                cX = x;
                cY = colSorted[x][rIdx-1];
                
                if (dp[cY][cX] == -1) {second = max(second, dfs(cX, cY));}
                else { second = max(second, dp[cY][cX]);}
                rIdx--;
            }
        }

        int current = max(first, second) + 1;
        dp[y][x] = current;
        answer = max(dp[y][x], answer);
        return current;
    }
    
    int maxIncreasingCells(vector<vector<int>>& matrix) {
        mat = move(matrix);
        const int m = mat.size();
        const int n = mat[0].size();

        answer = 0;
        rowSorted.resize(m, vector<int>(n));
        colSorted.resize(n, vector<int>(m));
        dp.resize(m, vector<int>(n, -1));

        for (auto& row : rowSorted) {
            for (int i = 0; i < n; ++i) {row[i] = i;}
        }

        for (auto& col : colSorted) {
            for (int j = 0; j < m; ++j) {col[j] = j;}
        }


        for (int i = 0; i < m; ++i) {
            sort(rowSorted[i].begin(), rowSorted[i].end(),
                    [&](const int first, const int second) {
                        return mat[i][first] < mat[i][second];
                    });
        }

        for (int j = 0; j < n; ++j) {
            sort(colSorted[j].begin(), colSorted[j].end(),
                    [&](const int first, const int second) {
                        return mat[first][j] < mat[second][j];
                    });
        }

        for (int y = 0; y < m; ++y) {
            for (int x = 0; x < n; ++x) {
                if (dp[y][x] == -1) {
                    dfs(x, y);
                }
            }
        }

        return answer;
    }
};

int main() {
    
    vector<vector<int>> grid = {
        {2,-6,-1,-6},
        {6,-6,-5,-6},
        {0,0,-3,5},
        {-6,-1,-2,-5},
        {7,6,2,-8},
        {-1,-6,2,3},
        {-2,4,0,7},
        {-5,6,5,-5}
    };

    Solution2 s{};
    cout << s.maxIncreasingCells(grid) << "\n";

    return 0;
}
