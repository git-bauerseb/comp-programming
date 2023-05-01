#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <numeric>

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

ll binpow(ll a, ll b) {
    ll res = 1;
    while (b > 0) {
        if (b & 1) {
            res = (res * a) % MOD;
        }
        a = (a * a) % MOD;
        b >>= 1;
    }

    return res;
}

const int N_MAX = 200'010;
ll C[N_MAX];
ll B[N_MAX];

void solution() {
    int n; cin >> n;
    for (int i = 0; i < n; ++i) {
        ll a,b; cin >> a >> b;
        C[i] = a * b;
        B[i] = b;
    }

    int tags = 1;
    ll gcd_ = 0;
    ll lcm_ = 1;
    for (int i = 0; i < n; ++i) {
        if (std::gcd(gcd_, C[i]) % std::lcm(lcm_, B[i]) != 0) {
            gcd_ = 0;
            lcm_ = 1;
            tags++;
        }
        gcd_ = std::gcd(gcd_, C[i]);
        lcm_ = std::lcm(lcm_, B[i]);
    }

    cout << tags << "\n";
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
