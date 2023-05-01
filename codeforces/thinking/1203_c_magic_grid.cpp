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

const int N_MAX = 1002;
int DP[N_MAX][N_MAX];

bool check(int n) {
    int xor_ = 0;
    for (int i = 0; i < n; ++i) {
        xor_ ^= DP[0][i];
    } 

    for (int i = 1; i < n; ++i) {
        int cXor = 0;
        for (int j = 0; j < n; ++j) {
            cXor ^= DP[i][j];
        }

        if (cXor != xor_) {cout << "ERROR\n"; return true;}
    }

    return true;
}

void solution() {
    int n; cin >> n;
    int blockX = 0;
    int blockY = 0;
    for (int i = 0; i < n*n; i += 4) {
        DP[blockY][blockX] = i;
        DP[blockY][blockX+1] = i+1;
        DP[blockY+1][blockX] = i+2;
        DP[blockY+1][blockX+1] = i+3;
        blockX += 2;
        if (blockX >= n) {
            blockX = 0;
            blockY += 2;
        }
    }

    
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cout << DP[i][j] << " ";
        }

        cout << "\n";
    }

    // check(n);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
    solution();
	return 0;
}
