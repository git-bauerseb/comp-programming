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

// k = 3
// n = 2
// (0,7), (7,0), (1,6), (6,1), (2,5), (5,2), (3,4), (4,3)
//
// n = 3
//  Elements (0,7,7) => (0,7,7), (7,0,7), (7,7,0)
//
//  Elements (1,6,7) => (1,6,7), (1,7,6), (6,1,7), (6,7,1),
//                      (7,1,6), (7,6,1)
//
//  Elements (2,5,7) => (2,5,7), (2,7,5), (5,2,7), (5,7,2),
//                      (7,2,5), (7,5,2)
//
//  Elements (3,4,7) => (3,4,7), (3,7,4), (4,3,7), (4,7,3),
//                      (7,3,4), (7,4,3)
//
// 3+6+6+6 = 21
//
// 226732710
// 857546876
void solution() {
    ll n,k; cin >> n >> k;
    
    ll result = 1;

    for (int i = 0; i < k; ++i) {
        result = (result * n) % MOD;
    }

    cout << result << "\n";
}

void check() {

    int k = 6;

    int lo = 0;
    int hi = (1 << k) - 1;

    while (lo < hi) {
        printf("%d,%d\n", lo, hi);
        lo++;
        hi--;
    }

}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

    int tt; cin >> tt;
    while (tt--)
        solution();

	return 0;
}
