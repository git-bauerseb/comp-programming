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
    while (b) {a %= b; swap(a,b);}
    return a;
}


void solution() {
    ll n; cin >> n;
    if (n == 1) cout << "1\n";
    else if (n == 2) cout << "2\n";
    else if (n == 3) cout << "6\n";
    else {
        if (n % 2) {
            cout << n*(n-1)*(n-2) << "\n";
        } else {
            if (n % 3) 
                cout << n*(n-1)*(n-3) << "\n";
            else 
                cout << (n-1)*(n-2)*(n-3) << "\n";
        }
    }
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
    solution();
	return 0;
}
