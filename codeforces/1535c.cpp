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

void solution() {
    string s; cin >> s;
    const int n = s.size();
    int l = 0;
    int r = 0;
    ll res = 0;
    char last = '-';
    while (l < n) {
        while (r == 0 || (r < n && last != s[r] || last == '?')) {
            r++;
            last = s[r];
        }
        res += (r-l+1)*(r-l+2)/2;
        l = r+1;
        r = l;
    }

    cout << res << "\n";
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
