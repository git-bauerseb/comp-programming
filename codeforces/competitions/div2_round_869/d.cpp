#include <bits/stdc++.h>

using namespace std;

#define all(x) begin(x), end(x)

// Constants
#define MOD 1'000'000'007

// Simple types
#define ll long long
#define ld long double

// Aggeragte types
#define pii pair<int,int>
#define pll pair<long,long>

#define vi vector<int>
#define vl vector<long>

#define si set<int>
#define sl set<long>

// Output
template <typename T>
void print_v(vector<T>& v) {cout << "{"; for (auto& x : v) cout << x << " "; cout << "\n";}

bool dfs(vector<vector<int>>& adjList, int start) {
    const int v = adjList.size();
    
    stack<int> s;
    vector<int> parents(v+2, -1);

    bitset<2003> discovered;
    discovered[start] = true;
    parents[start] = -1;
    s.push(start);

    int last = -1;
    bool isCycle = false;

    while (!s.empty()) {
        int t = s.top();
        s.pop();
        discovered[t] = true;
        for (auto& n : adjList[t]) {
            if (n == parents[t])
                continue;
        
            last = t;

            if (!discovered[n]) {
                s.push(n);
                parents[n] = t;
            } else if (n == start) {
                isCycle = true;
                break;
            }

            
        }

        if (isCycle) break;
    }

    if (isCycle) {
        vector<pair<int,int>> edges;
        edges.push_back({last+1, start+1});
        set<int> used;
        int p_last = -1;
        while (last != start) {
            p_last = last;
            last = parents[last];
            used.insert(p_last);
            used.insert(last);
            edges.push_back({last+1, p_last+1});
        }
        
        // Print two additional vertices
        int cnt = 2;
        for (auto& n : adjList[start]) {
            if (used.find(n) == used.end() && cnt--)
                edges.push_back({start+1, n+1});
        }

        if (cnt > 0) {
            return false;
        } else {

            cout << "YES\n";
            cout << edges.size() << "\n";
            for (auto& e : edges) cout << e.first << " " << e.second << "\n";
        }

        return true;
    }

    return false;
}

void solution() {
    int n,m; cin >> n >> m;
    vector<vector<int>> adjList(n);

    for (int i = 0; i < m; ++i) {
        int l,r; cin >> l >> r;
        adjList[l-1].push_back(r-1);
        adjList[r-1].push_back(l-1);
    }

    for (int i = 0; i < n; ++i) {
        if (adjList[i].size() > 3 && dfs(adjList, i)) {
            return;
        }
    }

    cout << "NO\n";
}


bool bfs(vector<vector<int>>& adjList, int start) {
    const int n = adjList.size();
    
    queue<int> unvis;
    bitset<2003> discovered;
    unvis.push(start);

    vector<int> parent(n, -1);

    while (!unvis.empty()) {
        int cur = unvis.front();
        unvis.pop();
        discovered[cur] = true;

        for (auto& nei : adjList[cur]) {            
            if (parent[nei] == start) {
                // Found cycle leading back to start node
                // Construct cycle back to start node
                int last = cur;
                int plast = -1;
                vector<pair<int,int>> edges;
                set<int> used;

                while (last != -1) {
                    plast = last;
                    last = parent[last];
                    used.insert(plast);
                    used.insert(last);
                    edges.push_back({plast+1, last+1});
                }

                edges.push_back({cur+1, start+1});

                int add = 2;
                for (auto& neigh : adjList[start]) {
                    if (used.find(neigh) == used.end()
                            && add-- > 0) edges.push_back({start+1, neigh+1});
                }

                if (add > 0) {return false;}
                
                cout << "YES\n";
                cout << edges.size() << "\n";
                for (auto& e : edges) cout << e.first << " " << e.second << "\n";
                return true;
            } else if (!discovered[nei]) {
                unvis.push(nei);
                if (parent[nei] == -1)
                    parent[nei] = cur;
            } 
        }
    }

    return false;
}


void solution2() {
    int n,m; cin >> n >> m;

    vector<vector<int>> adjList(n);

    for (int i = 0; i < m; ++i) {
        int l,r; cin >> l >> r;
        adjList[l-1].push_back(r-1);
        adjList[r-1].push_back(l-1);
    }

    for (int i = 0; i < n; ++i) {
        if (adjList[i].size() > 3 && bfs(adjList, i)) {return;}
    }

    cout << "NO\n";
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int tt;
	cin >> tt;
	while (tt--) {
        solution();
    }

	return 0;
}
