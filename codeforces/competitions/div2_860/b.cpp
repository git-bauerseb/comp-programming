#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
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

const int N_MAX = 50'003;
int LAST[N_MAX];

void solution() {
    int m; cin >> m;
    vector<vector<int>> part(m);
    for (int i = 0; i < m; ++i) {
        int num; cin >> num;
        for (int j = 0; j < num; ++j) {
            int p; cin >> p;
            part[i].push_back(p);
            LAST[p] = i;
        }
    }

    vi result;
    bool poss = true;
    for (int i = 0; i < m; ++i) {
        bool found = false;
        for (auto& pa : part[i]) {
            if (LAST[pa] <= i) {
                result.push_back(pa);
                found = true;
                break;
            }
        }

        if (!found) {
            poss = false;
            break;
        }
    }

    if (!poss) {cout << "-1\n";}
    else {
        for (auto& e : result) cout << e << " ";
        cout << "\n";
    }
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int tt;
	cin >> tt;
	while (tt--) {
	    memset(LAST, 0, sizeof(LAST));
        solution();
	}

	return 0;
}
