#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <bitset>
#include <queue>
#include <map>
#include <cstring>

using namespace std;

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

vector<vector<int>> adjList;

const int N_MAX = 1503;
bool USED[N_MAX];
int DIST[N_MAX];
int maxDepth = 0;
multimap<int,int> distances;

void bfs(int start) {
    queue<int> q;
    q.push(start);
    USED[start] = true;
    while (!q.empty()) {
        int v = q.front();
        q.pop();
        for (int u : adjList[v]) {
            if (!USED[u]) {
                q.push(u);
                USED[u] = true;
                DIST[u] = DIST[v]+1;
                distances.insert({DIST[u], u});
                maxDepth = max(maxDepth, DIST[u]);
            }
        }
    }
}

void solution() {
    int n,m; cin >> n >> m;
    adjList.resize(n+1);
    for (int i = 0; i < m; ++i) {
        int start, end; cin >> start >> end;
        adjList[end].push_back(start);
    }

    // Base cases
    if (n == 1) {cout << "FINITE\n1\n1\n"; return;}
    if (m == 0) {
        if (n == 1) cout << "FINITE\n1\n1\n";
        else cout << "INFINITE\n";
        return;
    }
    
    bfs(1);
    for (int i = 2; i <= n; ++i) {
        if (DIST[i] == 0) {
            cout << "INFINITE\n";
            return;
        }
    }


    cout << "FINITE\n";
    vi nums;

    for (int i = 0; i <= maxDepth; ++i) {
            for (int j = maxDepth; j >= i; --j) {
            if (j == 0) {nums.push_back(1); continue;}
            if (distances.count(j) > 0) {
                auto ret = distances.equal_range(j);
                for (auto it = ret.first; it != ret.second; ++it) nums.push_back(it->second);
            }
        }
    }

    cout << nums.size() << "\n";
    for (auto& e : nums) cout << e << " ";
    cout << "\n";
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int tt;
	cin >> tt;
	while (tt--) {
		solution();
        memset(DIST, 0, sizeof DIST);
	    memset(USED, false, sizeof USED);
        maxDepth = 0;
        distances.clear();
        adjList.clear();
    }

	return 0;
}
