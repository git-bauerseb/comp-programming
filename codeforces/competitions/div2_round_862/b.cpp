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
    int len; cin >> len;
    string s; cin >> s;
    const int n = s.size();
    char first = s[0];
    int idx = n-1;
    char m = s[n-1];
    for (int i = n-2; i > 0; --i) {
        char curr = s[i];
        if (curr < m) {
            idx = i;
            m = curr;
        }
    }

    if (m <= s[0]) {
        // swap(s[0], s[idx]);
        string s_new = s[idx] + s.substr(0, idx) + s.substr(idx+1); 
        cout << s_new << "\n";
    } else {
        cout << s << "\n";
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
