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

// Greedy solution:
//
// Smallest:
//   i) Fill string of length m with '1' -> if sum > s then print -1
//   ii) While digit sum is not s, fill from end with smallest next digit '2', then '3', ...
//       until sum of digits == s
//
// Largest:
//   analog

void solution() {
    int m,s; cin >> m >> s;
    string sm(m, '0');

    int mSum = 0;

    if (s == 0 && m == 1) {cout << "0 0\n"; return;}
    if (s > m*9) {cout << "-1 -1\n"; return;}
    if (s == 0) {
        cout << "-1 ";
    } else {
        sm[0] = '1'; mSum = 1;
        for (int i = m-1; i >= 0 && mSum < s; --i) {
            int largestInc = min(9,s-mSum);
            sm[i] = sm[i] + largestInc;
            mSum += largestInc;
        }

        cout << sm << " ";
    }

    mSum = 0;
    string smax(m, '0');
    if (s == 0) {
        cout << "-1\n";
    } else {
        for (int i = 0; i < m && mSum < s; ++i) {
            int largestInc = min(9, s-mSum);
            smax[i] = smax[i] + largestInc;
            mSum += largestInc;
        }

        cout << smax << "\n";
    }
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	solution();

	return 0;
}
