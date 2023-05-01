#include <iostream>
#include <algorithm>
#include <vector>
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

void solution() {
    int n; cin >> n;
    ll c; cin >> c;
    ll d; cin >> d;

    vi nums(n+1); for (int i = 1; i <= n; ++i) cin >> nums[i];
    sort(nums.begin(), nums.end());
    
    ll correct = 0;
    ll dup = 0;
    ll min_ = 1E18;
    
    for (int i = 1; i <= n; ++i) {
        if (i > 1)
            dup += nums[i] == nums[i-1] ? 1 : 0;
        
        correct += !(nums[i] == nums[i-1]) ? 1 : 0;
        // Remove duplicates
        ll cCost = dup * c;
        // Insert missing elements
        cCost += (nums[i] - correct) * d;
        // Remove larger elements
        cCost += (n - correct - dup) * c;
        min_ = min(min_, cCost);
    }

    cout << min(min_, n*c + d) << "\n";
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
