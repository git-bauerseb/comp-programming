#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <string>
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


// deletions(9) = 1 + deletions(4) = 2 + deletions(2) = 4
// deletions(4) = 1 + deletions(2) = 3
int deletions(int n) {
    if (n == 0) return 0;
    if (n == 1) return 1;
    if (n == 2) return 2;
    return 1 + deletions(n/2);
}


int M_DIST[26];
int PREV_OCC[26];
int LAST_OCC[26];
int FIRST_OCC[26];

void solution() {
    string s; cin >> s;
    const int n = s.size();

    for (int i = 0; i < n; ++i) {
        int cChr = s[i] - 'a';
    
        if (LAST_OCC[cChr] >= 0) {
            M_DIST[cChr] = max(M_DIST[cChr], i - LAST_OCC[cChr] - 1);
        } else {
            FIRST_OCC[cChr] = i;
        }

        LAST_OCC[cChr] = i;
    }

    int minDel = 200'003;
    for (int i = 0; i < 26; ++i) {
        if (FIRST_OCC[i] >= 0) {
            int maxDist = max(
                FIRST_OCC[i],
                max(
                    n-LAST_OCC[i]-1,
                    M_DIST[i]
                )
            );

            minDel = min(minDel, deletions(maxDist));
        }
    }

    printf("%d\n", minDel);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int tt;
	cin >> tt;
	while (tt--) {
        memset(M_DIST, -1, sizeof M_DIST);
        memset(PREV_OCC, -1, sizeof PREV_OCC);
        memset(LAST_OCC, -1, sizeof LAST_OCC);
        memset(FIRST_OCC, -1, sizeof FIRST_OCC);
        solution();
	}

	return 0;
}
