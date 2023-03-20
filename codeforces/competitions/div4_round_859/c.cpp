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
	int n; cin >> n;
	string s; cin >> s;

	bool zero = true;
	for (int i = 0; i != n; ++i) {
		char ch = s[i];
		if (s[i] != '0' && s[i] != '1') {
			replace(s.begin(), s.end(), ch, zero ? '0' : '1');
		}
		zero = !zero;
	}

	// Check
	zero = true;
	bool poss = true;
	for (int i = 0; i != n; ++i) {
		if (s[i] == '0' && !zero) {poss = false; break;}
	    if (s[i] == '1' && zero) {poss = false; break;}
		zero = !zero;	
	}

	if (poss) cout << "YES\n";
	else cout << "NO\n";
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
