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

ll gcd(ll a, ll b) {
    if (b == 0) return a;
    else return gcd(b, a % b);
}

void solution() {
    ll a, b; cin >> a >> b;

    if (gcd(a,b) == 1) {
        cout << "1\n" << a << " " << b << "\n";
    } else {
        
        ll xA = 0;
        ll yA = 0;
        bool found = false;
        for (ll x = max(1LL, a-1000); x <= min(1'000'000'000LL, a+1000); ++x) {
            for (ll y = max(1LL, b-1000); y <= min(1'000'000'000LL, b+1000); ++y) {
                if (gcd(x,y) == 1 
                        && gcd(x >= a ? x - a : a - x, y >= b ? y - b : b - y) == 1) {
                    found = true;
                    xA = x;
                    yA = y;
                    break;
                }
            }

            if (found) {
                break;
            }
        }

        cout << "2\n" << xA << " " << yA << "\n";
        cout << a << " " << b << "\n";
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
