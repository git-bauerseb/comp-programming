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

int solution() {
    string s; cin >> s;
    int mOp = 0;

    if (s.size() == 1) return s[0] == '_' ? 2 : 1;

    for (int i = 0; i < s.size()-1; ++i) {
        mOp += (s[i] == s[i+1] && s[i] == '_');
    }

    if (s[0] != '^') mOp++;
    if (s[s.size()-1] != '^') mOp++;
    return mOp;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int tt;
	cin >> tt;
	while (tt--) {
		int ans = solution();
	    cout << ans << "\n";
    }

	return 0;
}
