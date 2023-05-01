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
    vector<int> numbers(n); for (int i = 0; i < n; ++i) cin >> numbers[i];

    for (int i = 0; i < n-1; ++i) {
        int c = numbers[i];
        int cp = numbers[i+1];

        if (abs(c-cp) > 1) {
            cout << "YES\n";
            cout << (i+1) << " "  << (i+2) << "\n";
            return;
        }
    }

    cout << "NO\n";
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
