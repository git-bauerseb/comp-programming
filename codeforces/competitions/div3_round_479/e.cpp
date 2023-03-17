#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <stack>

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

const int N_MAX = 200001;
bool USED[N_MAX];

vector<vector<int>> adjL;
vector<vector<int>> connected;

void dfs(int start) {
	stack<int> visited;
	visited.push(start);

	vector<int> group;
	group.push_back(start);

	while (!visited.empty()) {
		int node = visited.top();
		visited.pop();
		USED[node] = true;
		for (auto& e : adjL[node]) {
			if (!USED[e]) {
				group.push_back(e);
				visited.push(e);
			}
		}
	}

	connected.push_back(group);
}

void solution() {
	int n, m; cin >> n >> m;
	adjL.resize(n+1);

	for (int i = 0; i != m; ++i) {
		int s, e; cin >> s >> e;
		adjL[s].push_back(e);
		adjL[e].push_back(s);
	}

	// Determine connected components
	for (int i = 1; i <= n; ++i) {
		if (!USED[i]) {
			dfs(i);
		}
	}

	int cnt = 0;

	for (auto& group : connected) {
		if (group.size() <= 2) continue;

		// Count edges in component
		bool cycle = true;
		for (auto& e : group) {if (adjL[e].size() != 2) {cycle=false;break;}}
		if (cycle) {
			cnt++;
		}
	}

	cout << cnt << "\n";
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	solution();
	return 0;
}
