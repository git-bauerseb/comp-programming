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

// Description
//
//  n shops
//  xi: price in i-th shop
//
//  q consecutive days
//  mi: spend coins on ith day

void solution() {
    int n; cin >> n;
    vi nums(n); for (int i = 0; i < n; ++i) cin >> nums[i];
    sort(nums.begin(), nums.end());
    int m; cin >> m;
    for (int i = 0; i < m; ++i) {
        int mo; cin >> mo;
        auto it = upper_bound(nums.begin(), nums.end(), mo);
        int idx = (int)(it-nums.begin());
        cout << idx << "\n";
    } 
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
    solution();
	return 0;
}
