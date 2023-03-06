#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <queue>
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

const int N_MAX = 200001;
int DIST[N_MAX];
int LABELS[N_MAX];

bool USED[N_MAX];
bool VISITED[N_MAX];
vector<vector<int>> adjL;

// Too slow: O(n^2 log n)

bool binSearch(int element, int l, int r) {
	int end = r;
	while (l < r) {
		int m = (l+r)/2;
		if(LABELS[m] < element) {l = m+1;}
		else r = m;
	}

	while (l < end && LABELS[l] && USED[l]) l++;
	if (LABELS[l] != element) return false;
	else {USED[l] = true; return true;}
}

bool bfs(int start, int nNodes) {
	queue<int> n;
	n.push(start);
	VISITED[start] = true;
	DIST[start] = 0;

	bool aUsed = !binSearch(0, 1, nNodes);

	while (!n.empty()) {
		int node = n.front();
		n.pop();
		for (auto& neigh : adjL[node]) {
			if (!VISITED[neigh]) {
				VISITED[neigh] = true;
				DIST[neigh] = DIST[node] + 1;
				n.push(neigh);
				if (!binSearch(DIST[neigh], 1, nNodes)) {
					if (aUsed) return false;
					aUsed = true;
				}
			}
		}
	}

	return true;
}

void solution() {
	int n; cin >> n;
	for (int i = 1; i < n; ++i) cin >> LABELS[i];

	// Sort labels
	sort(LABELS, LABELS + n);

	adjL.resize(n+1);
	for (int i = 1; i < n; ++i) {
		int s, t; cin >> s >> t;
		adjL[s].push_back(t);
		adjL[t].push_back(s);
	}

	vi good;
	for (int i = 1; i <= n; ++i) {
		if (bfs(i, n)) good.push_back(i);
		memset(VISITED, false, sizeof(VISITED));
		memset(USED, false, sizeof(USED));
	}

	cout << good.size() << "\n";
	if (good.size() != 0) {
		for (int i = 0; i <(int) good.size()-1; ++i) cout << good[i] << " ";
		cout << good[good.size()-1] << "\n";
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	solution();
	return 0;
}
