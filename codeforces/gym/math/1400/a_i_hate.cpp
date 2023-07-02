#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>

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

// Naive Top-Down DP solution (Brute Force + Lookup)
map<int,int> memo;
bool can(int x) {
    if (memo.count(x) > 0) return memo[x];
    if (x < 0) return false;
    if (x == 0) return true;
    if (x % 11 == 0) return true;
    if (x % 111 == 0) return true;
    memo[x] = can(x - 11)
        || can(x - 111);

    return memo[x];
}
void solution1() {
    int x; cin >> x;
    cout << (can(x) ? "YES\n" : "NO\n");
}

// Only 11, 111 relevant
//
// Write a number as X = 11(A + 111C) + 111D
// where 0 < D < 11
//
// Check if any D value yields a number s.t.
//  X - 111D
// is divisible by 11
void solution2() {
    int x; cin >> x;

    bool can = false;
    for (int d = 0; d < 11; ++d) {
        if ((x - d*111) >= 0 && (x-d*111) % 11 == 0) {can = true; break;}
    }


    cout << (can ? "YES\n": "NO\n");
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int tt;
	cin >> tt;
	while (tt--) {
		solution2();
	}
	return 0;
}
