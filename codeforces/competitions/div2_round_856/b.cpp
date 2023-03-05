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


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int tt;
	cin >> tt;
	while (tt--) {
		int n;
		cin >> n;
	
		vi nums(n);
		for (int i = 0; i != n; ++i)
			cin >> nums[i];

		for (int i = 0; i != n; ++i) if (nums[i] == 1) nums[i]++;
		for (int i = 1; i != n; ++i) if (nums[i] % nums[i-1] == 0) nums[i]++;

		for (int i = 0; i != n-1; ++i) {cout << nums[i] << " ";}
		cout << nums[n-1] <<  "\n";
	}

	return 0;
}
