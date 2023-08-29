#include <iostream>
#include <vector>

#include <utility>
#include <queue>
#include <tuple>

using namespace std;

struct Comparator {
    bool operator()(const tuple<int,int,int>& a, const tuple<int,int,int>& b) {
        return get<0>(a) > get<0>(b);
    }
};

class Solution {
public:
    int maxIncreasingCells(vector<vector<int>>& mat) {
        const int m = mat.size();
        const int n = mat[0].size();
        const int INF = 1e9;

        priority_queue<tuple<int,int,int>,
            vector<tuple<int,int,int>>, Comparator> pq;
    

        vector<pair<int,int>> rowMax(m+1, {0,-INF});
        vector<pair<int,int>> colMax(n+1, {0,-INF});

        for (int y = 0; y < m; ++y) {
            for (int x = 0; x < n; ++x) {
                pq.push({mat[y][x], x,y});
            }
        }

        int largest = -INF;

        while (!pq.empty()) {
            auto t = pq.top();
            pq.pop();
            int val = get<0>(t);
            int x = get<1>(t);
            int y = get<2>(t);
            int oMax = -INF;

            if (val == -2) {
                cout << "!\n";
            }


            if (val > rowMax[y].second) {
                rowMax[y].first = 1 + rowMax[y].first;
                if (val > colMax[x].second) {
                    colMax[x].first += 1;
                    rowMax[y].first = max(rowMax[y].first, colMax[x].first);
                    colMax[x].second = val;
                }

                rowMax[y].second = val;
            }

            if (val > colMax[x].second) {
                colMax[x].first = 1 + colMax[x].first;
                if (val > rowMax[y].second) {
                    rowMax[y].first += 1;
                    colMax[x].first = max(colMax[x].first, rowMax[y].first);
                    rowMax[y].second = val;
                }
                colMax[x].second = val;
            }

            largest = max(largest, max(rowMax[y].first, colMax[x].first));
        }

        return largest;
    }
};

int main() {
    // -9 -> -3 -> -2 -> -1 -> 1 -> 3 -> 4
    vector<vector<int>> mat = {
        {4,-2, -5,  -1,  1,  3},
        {1,-3,  7,  -9, -9, -3}
    };

    Solution solution{};
    cout << solution.maxIncreasingCells(mat) << "\n";
    return 0;
}
