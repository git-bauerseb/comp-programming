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

// Two pointer approach
/*
bool subSeq(vector<int>& nums, int& lPos, int& rPos, int k) {
    const int n = nums.size();
    if (lPos > rPos) return false;
    while (lPos >= 0 && nums[lPos] != k) lPos--;
    while (rPos < n && nums[rPos] != n-k+1) rPos++;

    if (lPos < 0 || rPos >= n) return false;
    return true;
}

void solution() {
    int n; cin >> n;
    int k = (n % 2 == 0) ? n / 2 : (n+1)/2;
    int lPos, rPos;
    vi nums(n);

    for (int i = 0; i < n; ++i) {
        int num; cin >> num;
        if (num == k) lPos = i;
        if (num == n-k+1) rPos = i;
        nums[i] = num;
    }


    while (subSeq(nums, lPos, rPos, k)) {
        k--;
    }

    cout << k << "\n";
}
*/

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
