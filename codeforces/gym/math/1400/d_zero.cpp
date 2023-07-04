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
    ll n, k; cin >> n >> k;
    vector<ll> nums(n,0);
    bool allMult = true;
    for (int i = 0; i < n; ++i) {
        ll num; cin >> num;
        num = num % k;
        allMult &= (num == 0);
        nums[i] = num;
    }

    if (allMult) {cout << "0\n"; return;}

    sort(nums.begin(), nums.end());


    ll minOp = 0;

    // 2 - 1 +   1*3 + 3 - 1 = 1 + 3 + 2 = 6

    for (int i = n-1; i >= 0;) {
        ll cRem = nums[i];
        if (cRem == 0) {break;}
        ll numSame = 0;
        while (i >= 0 && nums[i] == cRem) {--i; numSame++;}
        minOp = max(minOp, (numSame-1L)*k + k - cRem + 1L);
    }

    cout << minOp << "\n";
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
