#include <iostream>
#include <algorithm>
#include <vector>
#include <set>

using namespace std;

// Constants
#define MOD 1000000007

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

ll inv(ll i) {
    return i <= 1 ? i : MOD - (long long)(MOD/i) * inv(MOD % i) % MOD;
}

void solution() {
    ll k, pa, pb; cin >> pa >> pb;
    ll res = (pa * inv(pb)) % MOD;
    

    
    cout << res << "\n";
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

    solution();
	return 0;
}
