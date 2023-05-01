#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <set>
#include <cstring>

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

int DIGITS[11];

void solution() {
    string s; cin >> s;
    int unique = 0;
    for (auto& c : s) {
        if (!DIGITS[c - '0']) {unique++;}
        DIGITS[c-'0']++;
    }

    if (unique == 1) {cout << "-1\n";}
    else if (unique == 2) {
        bool even = false;
        for (int i = 0; i != 10; ++i)
            if (DIGITS[i] == 2) 
                {even = true; break;}
        if (even) 
            cout << "4\n";
        else
            cout << "6\n";  
    } else {cout << "4\n";}
    memset(DIGITS, 0, sizeof(DIGITS));
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
