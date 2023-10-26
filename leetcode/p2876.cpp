#include <vector>
#include <stack>

#include <iostream>

using namespace std;

class Solution {
public:
    vector<int> nodeCnt;
    
    // visited[i] := 0 if visited in 0th round, ....
    // -1 if never visited
    vector<int> visited;

    void dfs(vector<int>& neigh, int start, int rnd) {
        const int n = neigh.size();
        visited[start] = rnd;

        stack<int> st;
        st.push(start);
        nodeCnt[start] = 1;

        int cycleLength = 0;
        bool containsCycle = false;
        int cycleEntry = 0;
        int mVisited = 0;

        while (!st.empty()) {

            int u = st.top();
            st.pop();

            int v = neigh[u];

            // Node has been visited in previous round => Can just use result
            if (visited[v] >= 0 && visited[v] < rnd) {
                mVisited = nodeCnt[v] + nodeCnt[u];
                break;
            }

            // Node has been visited in current round => cycle
            if (visited[v] == rnd) {
                // We have a cycle
                containsCycle = true;
                cycleLength = nodeCnt[u] + 1 - nodeCnt[v];
                cycleEntry = v;
                break;
            }

            // Node has not been visited
            if (visited[v] < 0) {
                st.push(v);
                visited[v] = rnd;
                nodeCnt[v] = 1 + nodeCnt[u];
                mVisited = nodeCnt[v];
            }
        }

        // Use back edges to set #num visited nodes for each node to be cycleLen
        
        if (containsCycle) {
            int s = cycleEntry;
            while (true) {
                nodeCnt[s] = cycleLength;
                s = neigh[s];

                if (s == cycleEntry) break;          
            }
        }

        int s = start;
        while (visited[s] == rnd && s != cycleEntry) {
            nodeCnt[s] = mVisited--;
            s = neigh[s];;
        }
    }

    vector<int> countVisitedNodes(vector<int>& edges) {
        const int n = edges.size();
        nodeCnt.resize(n,-1);
        visited.resize(n,-1);

        int round = 0;
    
        for (int i = 0; i < n; ++i) {
            if (visited[i] < 0) {
                dfs(edges, i, round++);
            }
        }

        return nodeCnt;
    }
};

int main() {
    
    vector<int> edges{8,17,14,8,14,12,16,11,4,14,19,6,8,8,2,10,2,1,1,18};
    Solution s{};
    auto r = s.countVisitedNodes(edges);

    for (auto& e : r) cout << e << " ";
    cout << "\n";

    return 0;
}
