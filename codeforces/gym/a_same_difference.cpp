#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>

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

// Ideas/Observations:
//
//  Naive: Fix j
//     - iterate over all lower indices i and check if condition satisified
//   => Time O(n^2)
//
//  E.g. 1 2 3
//
//  Suppose aj - ai = j-i
//      aj - a(i+1) = j - (i+1) = j - i - 1
//      => Only true if a(i+1) is one more than a(i)
//
//      a(j+1) - ai = j+1-i
//      => Only true if a(j+1) is one more than a(i)
//
void solution() {
    /*
    int n; cin >> n;
    vector<int> nums(n);
    for (int i = 0; i < n; ++i) cin >> nums[i];

    ll poss = 0;
    for (int j = 1; j < n; ++j) {
        for (int i = 0; i < j; ++i) {
            if (j-i == nums[j]-nums[i]) poss++;
        }
    }

    cout << poss << "\n";
    */
}

//        aj - ai = j - i
//   <=>  aj - j = ai - i
// 
// 1 2 3 4 5 6
// 0 0 0 0 0 0
//
// 0s: 1
void solution2() {
    int n; cin >> n;
    
    map<int,int> counter;
    ll total = 0;

    for (int i = 0; i < n; ++i) {
        int n_;
        cin >> n_;
        int act = n_ - i-1;
        total += counter[act];
        counter[act]++;
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
		solution2();
	}

	return 0;
}
