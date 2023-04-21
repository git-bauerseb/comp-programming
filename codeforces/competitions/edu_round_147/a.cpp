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

    if (n == 1 && s[0] == '?') {cout << "9\n"; return;}//return 9;
    if (s[0] == '0') {cout << "0\n"; return;}

    ll matches = 1LL;
    if (s[0] == '?') matches += 8LL;


    for (int i = 1; i < n; ++i) {
        if (s[i] == '?') matches *= 10;
    }

    cout << matches << "\n";

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
