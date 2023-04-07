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

// k = 3,
//
// 2 + 3 = 5,
// 2 + 3 + 3 = 8,
// 2 + 2 + 3 = 7,
void solution() {
    ll n;
    ll k;
    cin >> n;
    cin >> k;
    if (n % 2 == 0 || (k % 2 == 1 && n >= k)) cout << "YES\n";
    else cout << "NO\n";
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
