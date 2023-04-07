#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <cmath>

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

inline int gcd(int a, int b) {
    while (b) {
        a %= b;
        swap(a,b);
    }
    return a;
}

inline int is_prime(int n) {
    if (n == 2 || n == 3) return true;
    if (n <= 1 || n % 2 == 0 || n % 3 == 0) return false;
    for (int i = 5; i * i <= n; i += 6) {
        if (n % i == 0 || n % (i+2) == 0) return false;
    }
    return true;
}

int detOpt(int num, int step) {
    int oCost = num / step;
    for (int i = step+1; i <= num; ++i) {
        if (num % i == 0) {
            oCost = min(oCost, (num / i) + (i - step));
        }
    }

    return oCost;
}

void solution() {
    ll a,b; cin >> a >> b;
    ll cost = 1E15;
    int bound = static_cast<int>(sqrt(a+b));
    for (int t = max(0, bound - 50000); t <= bound + 50000; ++t) {
        ll nCost = t + (a+t)/(t+1) + (b+t)/(t+1);
        cost = min(cost, nCost);
    }

    cout << cost << "\n";
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
