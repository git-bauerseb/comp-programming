#include <iostream>
#include <algorithm>
#include <vector>
#include <set>

using namespace std;

// Constants
#define MOD 1'000'000'007

#define BIL 1'000'000'000


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

}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int n, k; cin >> n >> k;
	vi nums(n);
	for (int i = 0; i != n; ++i) cin >> nums[i];

	sort(nums.begin(), nums.end());

	int num = nums[k-1];

	if (k == 0) cout << (nums[0] == 1 ? -1 : 1) << "\n";
	else if (k <= n-1 && nums[k] == num) cout << -1 << "\n";
	else cout << min(BIL, num) << "\n";

	return 0;
}
