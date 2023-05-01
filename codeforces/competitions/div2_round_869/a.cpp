#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <bitset>

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

void solution() {
    int n,k;
    cin >> n >> k;

    vector<string> ops;
    ops.resize(n);
    for (int i = 0; i < n; ++i) {
        cin >> ops[i];
    }

    int stay = n;
    bitset<1001> left;

    for (int v = 0; v < k; ++v) {

        for (int j = 1; j < n; ++j) {
            if (!left[j]) {
                if (ops[j][v] != ops[0][v]) {
                    left[j] = true;
                    stay--;
                }
            }
        }
    }

    cout << stay << "\n";
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
