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

ll f(ll arg) {return (arg+1) * (arg+1);}

ll binSearch(ll n) {
    ll left = 0;
    ll right = 1'000'000'003L;

    while (left < right) {
        ll mid = left + (right - left) / 2;
        if (f(mid) > n) right = mid;
        else left = mid+1;
    }

    return left;
}

void solution() {
    ll n; cin >> n;
    ll k = binSearch(n-1);
    cout << k << "\n";
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
