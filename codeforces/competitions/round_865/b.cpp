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

const int N_MAX = 100'002;
int A[2][N_MAX];

void solution() {
    int n; cin >> n;
    A[0][0] = 2*n;
    A[1][0] = 1;
    A[0][n-1] = n;
    A[1][n-1] = 2*n-1;

    bool down = false;
    int rem = n+1;
    for (int i = 2; i < n; ++i) {
        A[down?1:0][i-1] = i;
        A[down?0:1][i-1] = rem;
        rem++;
        down = !down;
    }

    for (int i = 0; i < 2; ++i) {
        for (int j = 0; j < n; ++j) cout << A[i][j] << " ";
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
		solution();
	}

	return 0;
}
