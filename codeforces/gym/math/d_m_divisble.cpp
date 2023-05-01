#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
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

// Idea:
//  - Store #count of numbers modulo m
//  - Start with arbitrary number with smallest modulo (i.e. i)
//  - Search for element that has modulo m-i
//      - if it exists, continue with i := m-i
//      - if it not consists, increment number of arrays used and go to smallest remaining modulo
//
// Proof (Optimality):
//  Suppose for contradiction, there exists partition into smaller number of arrays
//  => one array has bigger length than in partition described above
//  => let starting element of bigger array be s

const int N_MAX = 100'005;
int MODS[N_MAX];

//
// 1 1 1 
//
//
void solution() {
    int n,m; cin >> n >> m;

    for (int i = 0; i < n; ++i) {
        int num; cin >> num;
        MODS[num % m]++;
    }

    int arrays = MODS[0] > 0 ? 1 : 0;
    int lo = 1;
    int hi = m-1;

    while (lo <= hi) {
        
        if (!MODS[hi]) {arrays += MODS[lo];}
        else if (!MODS[lo]) {arrays += MODS[hi];}
        else {
            int ma = max(MODS[lo], MODS[hi]);
            int mi = min(MODS[lo], MODS[hi]);
            if (ma == mi) arrays += 1;
            else arrays += ma - mi;
        }
        lo++;
        hi--;
    }

    cout << arrays << "\n";
}

int main() {
//	ios_base::sync_with_stdio(false);
//	cin.tie(0);
//	cout.tie(0);

	int tt;
	cin >> tt;
	while (tt--) {
		solution();
        memset(MODS, 0, sizeof MODS);
	}

	return 0;
}
