#include <iostream>
#include <algorithm>
#include <vector>
#include <set>

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

const int N_MAX = 51;
bool OCC[N_MAX][N_MAX];

bool canPlace(int i, int j) {
    return !OCC[i][j] && !OCC[i+1][j]
       && !OCC[i-1][j] && !OCC[i][j+1] && !OCC[i][j-1]; 
}

void solution() {
    int n; cin >> n;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            char c; cin >> c;
            OCC[i][j] = c == '#';
        }
    }

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (i > 0 && i < n-1 && j > 0 && j < n-1) {
                if (canPlace(i,j)) {
                    OCC[i][j] = OCC[i+1][j] = OCC[i-1][j] = OCC[i][j-1] = OCC[i][j+1] = true;
                }
            }
        }
    }

    bool p = true;

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (!OCC[i][j]) {p = false; break;}
        }

        if (!p) break;
    }

    if (p) cout << "YES\n";
    else cout << "NO\n";
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

    solution();
	return 0;
}
