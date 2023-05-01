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

// Two numbers given (a,b), a > b
//
// (a,b) -> (a-b,b)
//
// Observation:
//  - Decreasing one side until its smaller than other side
//      - after that, switch sides
//
//  - If a > b, then he can make (a/b) ships until a <= b
void solution() {
    ll a,b; cin >> a >> b;
    ll ships = 0;
    while (a > 0 && b > 0) {
        if (a > b) {
            ll d = a/b;
            ships += d;
            a -= b*d;
        } else {
            ll d = b/a;
            ships += d;
            b -= a*d;
        }
    }
    cout << ships << "\n";
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
    solution();
	return 0;
}
