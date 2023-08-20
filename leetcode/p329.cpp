#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <utility>

using namespace std;

#define FLATTEN(x, y, m, n) (((y) * (m)) + x)

const int INF = 1e9;

// Greedy solution does not work
// => Can construct path where one element is < and another > 
// but > element wins
// e.g.
//  2 choices:
//      i)  1 -> 3
//      ii) 1 -> 9
//
//  Greedy would choose 3 because lowest increment, but it could be that
//  after 3 there are only elements 1,2 while after 9 there are elements 10,11,12,13,14,...
//  => Wrong Answer
/*
class Solution {
    public:
        vector<pair<int,int>> dir = {{-1,0}, {1,0}, {0,-1}, {0,1}};
        
        int bfs(vector<vector<int>>& matrix, int x, int y) {
            const int m = matrix.size();
            const int n = matrix[0].size();
            vector<bool> visited(m*n, false);
            vector<int> dist(m*n, INF);
            int maxDist = 1;
            dist[FLATTEN(x,y,m,n)] = 1;
            
            queue<int> pq;
            pq.push(FLATTEN(x,y,m,n));

            while (!pq.empty()) {
                const int crds = pq.front();
                pq.pop();
                visited[crds] = true;

                int xpar = crds % m;
                int ypar = (crds - xpar) / m;

                for (auto& d : dir) {
                    int nx = xpar + d.first;
                    int ny = ypar + d.second;
                    const int curCoord = FLATTEN(nx, ny, m, n);

                    if (nx >= 0 && nx < n && ny >= 0 && ny < m) {
                        if (!visited[curCoord] && matrix[ny][nx] > matrix[ypar][xpar]) {
                            pq.push(curCoord);
                            dist[curCoord] = 1 + dist[crds];
                            maxDist = max(maxDist, dist[curCoord]);
                        }
                    }
                }
            }

            return maxDist;
        }
        
        int longestIncreasingPath(vector<vector<int>>& matrix) {
            const int m = matrix.size();
            const int n = matrix[0].size();
            
            int longest = -INF;
            for (int y = 0; y < m; ++y) {
                for (int x = 0; x < n; ++x) {
                    longest = max(longest, bfs(matrix, x, y));
                }
            }

            return longest; // bfs(matrix, 0, 0);
        }
};
*/

// Topological Sorting + Longest path in DAG
// Key idea:
//  Form a graph where an edge exists if one value < other value
class Solution {
    public:
        int m;
        int n;

        vector<pair<int,int>> dirs = {{-1,0}, {1,0}, {0,-1}, {0,1}};
        vector<int> sorted;
        vector<bool> visited;
        int idx = 0;

        int flatten(int x, int y) {return y * n + x;}
        pair<int,int> unflatten(int coord) {
            int x = coord;
            return {x % n, coord / n};
        }

        void topologicalSort(int node, vector<vector<int>>& matrix) {
            visited[node] = true;

            auto p = unflatten(node);
            int x = p.first;
            int y = p.second;

            for (auto& dir : dirs) {
                int nx = x + dir.first;
                int ny = y + dir.second;

                if (nx >= 0 && nx < n && ny >= 0 && ny < m) {
                    const int nCoord = flatten(nx, ny);

                    if (!visited[nCoord] && matrix[y][x] < matrix[ny][nx]) {
                        topologicalSort(nCoord, matrix);
                    }
                }
            }

            sorted[idx++] = node;
        }

        int longestPath(vector<vector<int>>& matrix) {
            const long long INF = 1e18;
            vector<long long> dist(m*n, -INF);
            long long longest = 1;

            for (int i = 0; i < n*m; ++i) {
                int node = sorted[i];
                
                if (dist[node] == -INF) {
                    dist[node] = 1;
                }

                auto p = unflatten(node);
                int x = p.first;
                int y = p.second;

                for (auto& dir : dirs) {
                    int nx = x + dir.first;
                    int ny = y + dir.second;

                    if (nx >= 0 && nx < n && ny >= 0 && ny < m) {
                        const int cCoord = flatten(nx, ny);

                        if (matrix[y][x] < matrix[ny][nx] && dist[cCoord] < 1 + dist[node]) {
                            dist[cCoord] = dist[node] + 1;
                            longest = max(longest, dist[cCoord]);
                        }
                    }
                }
            }

            return longest;
        }

        int longestIncreasingPath(vector<vector<int>>& matrix) {
            m = matrix.size();
            n = matrix[0].size();
        
            if (m == 1 && n == 1) {
                return 1;
            }

            sorted.resize(m*n);
            visited.resize(m*n, false);

            for (int i = 0; i < m*n; ++i) {
                if (!visited[i]) {
                    topologicalSort(i, matrix);
                }
            }

            reverse(sorted.begin(), sorted.end());
            int l = longestPath(matrix);   
            return l;
        }
};

int main() {
    vector<vector<int>> matrix = {
        {7,0,8},
        {4,7,8},
        {4,7,4}
    };

    Solution solution{};
    cout << solution.longestIncreasingPath(matrix) << "\n";
    return 0;
}
