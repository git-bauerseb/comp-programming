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

bool check(vector<int>& nums);

void solution() {
    int n; cin >> n;
    if (n == 1) {cout << "1\n"; return;}
    else if (n % 2 == 1) {cout << "-1\n"; return;}
    else {
        vector<int> nums(n);

        int prev = n-1;
        int curr = n;

        int idx = 0;
        while (prev >= 1) {
            nums[idx] = prev;
            nums[idx+1] = curr;
            idx += 2;
            prev -= 2;
            curr -= 2;
        }

        for (auto& e : nums) cout << e << " ";
        cout << "\n";
    }
}

bool check(vector<int>& nums) {
    for (int r = 0; r < nums.size(); ++r) {
        for (int l = 0; l < r; ++l) {
            int sum = 0;
            for (int i = l; i <= r; ++i) sum += nums[i];
            if (sum % (r - l + 1) == 0) return false;
        }
    }

    return true;
}

void brute_force(int n) {
    vector<int> nums(n);
    for (int i = 1; i <= n; ++i) nums[i-1] = i;
    do {

       if (check(nums)) {
           cout << "Possible\n";
           for (auto& e : nums) cout << e << " ";
           cout << "\n";
       }
    } while (next_permutation(nums.begin(), nums.end()));
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
