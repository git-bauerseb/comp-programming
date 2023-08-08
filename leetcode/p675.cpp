#include <iostream>
#include <vector>
#include <queue>
#include <utility>
#include <tuple>

using namespace std;

struct CComparator {

    int operator()(const tuple<int,int,int>& a, const tuple<int,int,int>& b) {
        return get<0>(a) > get<0>(b);
    }
};


class Solution {

    public:
        int cutOffTree(vector<vector<int>>& forest) {
            const int m = forest.size();
            const int n = forest[0].size();
            
            // Contains (nextElement, xPos, yPos)
            priority_queue<tuple<int,int,int>,
                vector<tuple<int,int,int>>,
                CComparator> pq;
            for (int y = 0; y < m; ++y) {
                for (int x = 0; x < n; ++x) {
                    if (forest[y][x] > 1) {
                        pq.push({forest[y][x], x, y});
                    }
                }
            }

            int minDist = 0;
            int cX = 0;
            int cY = 0;
            
            while (!pq.empty()) {
                auto el = pq.top();
                pq.pop();


                int cDist = bfs(cX, cY, get<0>(el), n, m, forest);
                if (cDist < 0) {return -1;}
                minDist += cDist;
                
                cX = get<1>(el);
                cY = get<2>(el);
            }

            return minDist;
        }


        int bfs(int xStart, int yStart, int target, int n, int m,
                vector<vector<int>>& forest) {
            // Starting on target
            
            if (forest[yStart][xStart] == target) return 0;
            
            queue<pair<int,int>> q;
            q.push({xStart, yStart});

            vector<vector<int>> distance(m, vector<int>(n,-1));
            vector<vector<bool>> visited(m, vector<bool>(n, false));
            visited[yStart][xStart] = true;
            distance[yStart][xStart] = 0;

            while (!q.empty()) {
                auto pos = q.front();
                int x = pos.first;
                int y = pos.second;
                q.pop();

                for (auto& dir : m_dirs) {
                    int xNew = x + dir.first;
                    int yNew = y + dir.second;
                    if (inBounds(xNew, yNew, n, m) 
                            && forest[yNew][xNew] != 0
                            && !visited[yNew][xNew]) {
                        distance[yNew][xNew] = 1 + distance[y][x];
                        
                        if (forest[yNew][xNew] == target) {
                            return distance[yNew][xNew];
                        }

                        q.push({xNew, yNew});
                        visited[yNew][xNew] = true;
                    }
                }
            }

            return -1;
        }

        bool inBounds(int x, int y, int n, int m) {
            return (x >= 0 && x < n)
                && (y >= 0 && y < m);
        }


        vector<pair<int,int>> m_dirs = {{1,0}, {-1,0}, {0,-1}, {0,1}};
};

int main() {

    vector<vector<int>> f = {
            {54581641,64080174,24346381,69107959},
            {86374198,61363882,68783324,79706116},
            {2 ,92178815,89819108,94701471},
            {83920491,22724204,46281641,47531096},
            {89078499,3,25462145,60813308} 
    };

    Solution solution{};
    int m = solution.cutOffTree(f);
    cout << m << "\n";

    return 0;
}
