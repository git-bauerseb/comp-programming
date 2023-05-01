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

ll nextElement(ll n) {

    ll maxDigit = -1;
    ll minDigit = 10;

    ll nCpy = n;

    while (nCpy > 0) {
        ll digit = nCpy % 10;
        maxDigit = max(digit, maxDigit);
        minDigit = min(digit, minDigit);
        nCpy /= 10;
    }

    return n + maxDigit * minDigit;
}

void solution() {

    ll n, k; cin >> n >> k;
    ll prev = -1;

    while (k-- > 0) {
        prev = n;
        n = nextElement(n);
    
        if (prev == n) {cout << n << "\n"; return;}
    }

    cout << prev << "\n";
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
