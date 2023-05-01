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
    int n, m; cin >> n >> m;
    vector<vector<ll>> nums(m, vector<ll>(n));
    for (int i = 0; i < n*m; ++i) {
        cin >> nums[i%m][i/m];
    }

    for (int i = 0; i < m; ++i)
    sort(nums[i].rbegin(), nums[i].rend());

    ll total = 0;

    for (int j = 0; j < m; ++j) {
        ll pSum = nums[j][0];
        ll abs = 0;

        for (int i = 1; i < n; ++i) {
            abs += pSum - i*nums[j][i];
            pSum += nums[j][i];
        } 
        total += abs;
    }

    cout << total << "\n";
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
