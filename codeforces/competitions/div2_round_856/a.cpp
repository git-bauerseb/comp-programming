#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <string>

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

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int tt;
	cin >> tt;
	while (tt--) {
		
		int n;
		cin >> n;
		bool isP = true;
		if (n == 2) {
			string s1, s2;
			cin >> s1 >> s2;
			isP = s1 == s2;
		} else {
		vector<string> prefixes;
		for (int i = 0; i < 2 * n - 2; ++i) {string s; cin >> s; prefixes.push_back(s);}
		sort(prefixes.begin(), prefixes.end());
		for (int i = 0; i < 2 * n - 2; ++i) {
			string s = prefixes[i];
			string r = s;
			reverse(r.begin(), r.end());
			bool contains = binary_search(prefixes.begin(), prefixes.end(), r);
			if (!contains) {
				isP = false;
				break;
			}
		}
		}

		cout << (isP ? "YES\n" : "NO\n");
	}

	return 0;
}
