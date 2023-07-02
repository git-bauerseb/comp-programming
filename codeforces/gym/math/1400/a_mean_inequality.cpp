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
    vector<int> nums(2*n, 0);
    for (int i = 0; i < 2*n; ++i) cin >> nums[i];
    sort(nums.begin(), nums.end());

    int bIdx = n;
    for (int i = (n % 2 == 0 ? 1 : 0); i < n; i += 2) {
        swap(nums[i], nums[bIdx]);
        bIdx += 2;
    }

    for (auto& e : nums) cout << e << " ";
    cout << "\n";
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
