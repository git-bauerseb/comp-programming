#include <vector>
#include <queue>
#include <utility>
#include <algorithm>
#include <iostream>

using namespace std;
using pii = pair<int,int>;

struct CCompare {
    bool operator() (const pair<int,int>& a, const pair<int,int>& b) {
        return a.first < b.first;
    }
};

// Solution - Idea
//
// - Keep two priority queues q1, q2
// - Each queue stores (min, valid) where 
//   - min: minimum number of steps to jump to a previous location
//     q1 - up location
//     q2 - left location
//   - valid: stores the index up to which the minimum value is valid
/*
class Solution {


    public:
        int minimumVisitedCells(vector<vector<int>>& grid) {
            const int m = grid.size();
            const int n = grid[0].size();

            if (m-1 == 0 && n-1 == 0) return 0;


            priority_queue<pii, vector<pii>, CCompare> topQueue;
            priority_queue<pii, vector<pii>, CCompare> leftQueue;

            topQueue.push({0, grid[0][0]});
            leftQueue.push({0, grid[0][0]});

            vector<vector<int>> dist(m, vector<int>(n, -1));

            for (int y = 0; y < m; ++y) {
                for (int x = 0; x < n; ++x) {

                    // Start not important
                    if (y == 0 && x == 0) continue;


                    // Get minimum number of jumps from top
                    int topMin = -1;
                    while (!topQueue.empty()) {
                        // Check if it's possible to jump to current index
                        auto t = topQueue.top();
                        if (t.second >= y) {topMin = t.first; break;}
                        else {topQueue.pop();}
                    }

                    // Get minimum number of jumps from right
                    int leftMin = -1;
                    while (!leftQueue.empty()) {
                        auto t = leftQueue.top();
                        if (t.second >= x) {leftMin = t.first; break;}
                        else {leftQueue.pop();}
                    }

                    int minJumps = min(topMin, leftMin);

                    dist[y][x] = minJumps + 1;
                    topQueue.push({minJumps+1, y + grid[y][x]});
                    leftQueue.push({minJumps+1, x + grid[y][x]});
                }
            }


            for (auto& row : dist) {
                for (auto& e : row) cout << e << " "; 
                cout << "\n";
            }

            return -1;
        }
};
*/

// Naive algorithm
// Iterate over all cells above/left and take min
// 
// Time complexity: O(m*n * max(m,n))
//  => TLE
/*
class Solution {
    public:
        const int INVALID = 1 << 28;

        int minimumVisitedCells(vector<vector<int>>& grid) {
            const int m = grid.size();
            const int n = grid[0].size();

            if (m-1 == 0 && n-1 == 0) return 0;

            vector<vector<int>> dp(m, vector<int>(n, -1));
            dp[0][0] = 0;


            for (int y = 0; y < m; ++y) {
                for (int x = 0; x < n; ++x) {
                    if (x == 0 && y == 0) continue;
                    
                    int minTopJumps = INVALID;
                    for (int yPrev = y-1; yPrev >= 0; yPrev--) {
                        if (dp[yPrev][x] >= 0 && yPrev + grid[yPrev][x] >= y)
                            minTopJumps = min(dp[yPrev][x], minTopJumps);
                    }

                    int minLeftJumps = INVALID;
                    for (int xPrev = x-1; xPrev >= 0; xPrev--) {
                        if (dp[y][xPrev] >= 0 && xPrev + grid[y][xPrev] >= x)
                            minLeftJumps = min(dp[y][xPrev], minLeftJumps);
                    }

                    if (minTopJumps == INVALID && minLeftJumps == INVALID) {
                        dp[y][x] = -1;
                    } else {
                       dp[y][x] = 1 + min(minTopJumps, minLeftJumps);
                    }
                }
            }


            for (auto& row : dp) {
                for (auto& e : row) cout << e << " ";
                cout << "\n";
            }

            return (dp[m-1][n-1] == -1 ? 0 : 1) +  dp[m-1][n-1];
        }
};
*/

/*
struct ElementComparator {

    bool operator() (const tuple<int,int,int>& first, const tuple<int,int,int>& second) {
        return get<0>(first) < get<0>(second);
    }
};

class Solution {
    public:
        int minimumVisitedCells(vector<vector<int>>& grid) {
            const int m = grid.size();
            const int n = grid[0].size();

            if (m-1 == 0 && n-1 == 0) return 0;

            priority_queue<tuple<int,int,int>,
                vector<tuple<int,int,int>>,
                ElementComparator> topQueue;
            priority_queue<tuple<int,int,int>,
                vector<tuple<int,int,int>>,
                ElementComparator> leftQueue;


            topQueue.push({0, 0, 0});
            leftQueue.push({0, 0, 0});
            vector<vector<int>> dp(m, vector<int>(n, -1));
            dp[0][0] = 0;
            for (int y = 0; y < m; ++y) {
                for (int x = 0; x < n; ++x) {
                    if (x == 0 && y == 0) continue;

                    // Get minimum from top
                    int mTop = -1;
                    while (!topQueue.empty()) {
                        auto t = topQueue.top();
                        int l = get<1>(t);
                        int k = get<2>(t);
                        // Can jump to current position
                        if (l + grid[l][k] >= y) {
                            mTop = get<0>(t);
                            break;
                        }
                        topQueue.pop();
                    }
                    // Same for left element
                    int mLeft = -1;
                    while (!leftQueue.empty()) {
                        auto t = leftQueue.top();
                        int i = get<1>(t);
                        int l = get<2>(t);
                        if (l + grid[i][l] >= x) {
                            mLeft = get<0>(t);
                            break;
                        }
                        leftQueue.pop();
                    }
                    // If both are negative, no way to jump to current location
                    if (mLeft == -1 && mTop != -1) {dp[y][x] = 1 + mTop;}
                    else if (mLeft != -1 && mTop == -1) {dp[y][x] = 1 + mLeft;}
                    else if (mLeft != -1 && mTop != -1) {dp[y][x] = 1 + min(mLeft, mTop);}

                    if (dp[y][x] != -1) {
                        topQueue.push({dp[y][x],y,x});
                        leftQueue.push({dp[y][x],y,x});
                    }
                }
            }


            for (auto& row : dp) {
                for (auto& e : row) cout << e << " ";

                cout << "\n";
            }

            return dp[m-1][n-1];
        }
};
*/

class SegmentTree {
    public:

        // Build an segment
        SegmentTree(const vector<int>& numbers, std::function<int(int,int)> combine): m_numbers{numbers}, m_combine{combine} {
            const int n = m_numbers.size();

            m_stsize = n;
            // Reserve enough memory
            // 1 + 2 + 4 + ... + 2^ceil(log2(n)) < 4n vertices
            m_st.resize(4*n+1, 0);
        }

        SegmentTree(const int st_size, std::function<int(int,int)> combine): m_combine{combine} {
            m_stsize = st_size;
            m_st.resize(4 * st_size + 1, 0);
        }

        SegmentTree(const int st_size, int initValue, std::function<int(int,int)> combine)
            : m_combine{combine} {

            m_stsize = st_size;
            m_st.resize(4 * st_size + 1, 0);
            buildZero(initValue);
        }

        // Build without using numbers array
        void buildZero(int initValue) {buildZero(0, m_stsize-1, 1, initValue);}

        void build() {build(0, m_stsize-1, 1);}
        void update(int index, int value) {update(index, 0, m_stsize-1, value, 1);}

        // Query sum in range [l,...,r] (l,r inclusive)
        int query(int l, int r) {
            return query(l, r, 0, m_stsize-1, 1);
        }

    public:
        void buildZero(int l, int r, int vertex, int initValue) {
            if (l == r) m_st[vertex] = initValue;
            else {
                int m = (l + r) / 2;
                buildZero(l, m, leftChild(vertex));
                buildZero(m+1, r, rightChild(vertex));
                m_st[vertex] = m_combine(m_st[leftChild(vertex)], m_st[rightChild(vertex)]);
            }
        }

        // Build a segment tree for range sum queries
        void build(int l, int r, int vertex) {
            if (l == r) m_st[vertex] = m_numbers[l];
            else {
                // Current segment is [l,r]
                // Split into [l, ..., m], [m+1, ..., r]
                // where m = (l+r)/2
                int m = (l+r)/2;
                build(l, m, leftChild(vertex));
                build(m+1,r, rightChild(vertex));
                // Child nodes are built, so compute sum
                // Bottom-up
                m_st[vertex] = m_combine(m_st[leftChild(vertex)], m_st[rightChild(vertex)]);
            }
        }

        // cl: current left endpoint of segment
        // cr: current right endpoint of segment
        int query(int l, int r, int cl, int cr, int vertex) {
            // Cannot answer query because outside range
            if (l == cl && r == cr) return m_st[vertex];
            else {
                int m = (cl+cr)/2;

                // Only need to recursive in left subtree
                if (r <= m) return query(l, r, cl, m, leftChild(vertex));
                else if (l > m) return query(l, r, m+1, cr, rightChild(vertex));
                else {
                    int leftPart = query(l, m, cl, m, leftChild(vertex));
                    int rightPart = query(m+1, r, m+1, cr, rightChild(vertex));
                    return m_combine(leftPart, rightPart);
                }
            }
        }

        void update(int index, int cl, int cr, int val, int vertex) {
            if (cl == cr) m_st[vertex] = val;
            else {
                int m = (cl+cr) / 2;
                if (index <= m) update(index, cl, m, val, leftChild(vertex));
                else update(index, m+1, cr, val, rightChild(vertex));
                m_st[vertex] = m_combine(m_st[leftChild(vertex)], m_st[rightChild(vertex)]);
            }
        }

        int leftChild(int parent) {return 2*parent;}
        int rightChild(int parent) {return 2*parent + 1;}


        int m_stsize = 0;
        const vector<int> m_numbers;
        vector<int> m_st;           // Implicit segment tree

        // Combine function (Addition for range sum queries, maximum for range maximum queries)
        std::function<int(int,int)> m_combine;
};


class Solution {

    public:
        int minimumVisitedCells(vector<vector<int>>& grid) {
            const int m = grid.size();
            const int n = grid[0].size();

            const int UP = 1 << 28;

            vector<SegmentTree> cols(n, SegmentTree(m, UP,
                [](const int a, const int b) {return min(a,b);}));
            vector<SegmentTree> rows(m, SegmentTree(n, UP,
                [](const int a, const int b) {return min(a,b);}));

            vector<vector<int>> dp(m, vector<int>(n,-1));
            cols[0].update(0, 0);
            rows[0].update(0, 0);
            
            for (int y = 0; y < m; ++y) {
                for (int x = 0; x < n; ++x) {
                    if (x == 0 && y == 0) continue;

                    int mTop = -1;
                    if (x > 0) {mTop = cols[x].query(0, x-1);}

                    int mLeft = -1;
                    if (y > 0) {mLeft = rows[y].query(0, y-1);}

                    int cBest = -1;
                    if (mTop == -1 && mLeft != -1) {cBest = mLeft;}
                    else if (mTop != -1 && mLeft == -1) {cBest = mTop;}
                    else if (mTop != -1 && mLeft != -1) {cBest = min(mLeft, mTop);}

                    if (cBest != -1) {
                        dp[y][x] = cBest + 1;
                        cols[y] // Update range
                    }
                }
            }
        }
};

int main() {

    vector<vector<int>> grid {
        {2,1,0},
        {1,0,0}
    };

    Solution solution{};
    int mJumps = solution.minimumVisitedCells(grid);
    cout << mJumps << "\n";

    return 0;
}
