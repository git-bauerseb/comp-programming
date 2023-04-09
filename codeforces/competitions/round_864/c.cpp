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

const int N_MAX = 300'002;
ll NUMS[N_MAX];

// 5 4 3 2 1
// 6 5 3 2 1
// 6 7 5 2 1
// 6 7 8 5 1
// 6 7 8 9 5
//
// 6 7 4 5 5
// 3 4 4 5 5
void solution() {
    int n; cin >> n;
 
    for (int i = 0; i < n; ++i) {   
        cin >> NUMS[i];
    }

    
    for (int i = 0; i < n-2; ++i) {
        if (NUMS[i] > NUMS[i+1]) {
            ll diff = NUMS[i] - NUMS[i+1];
            NUMS[i+1] += diff;
            NUMS[i+2] += diff;
        }
    }
    
    // a_{i-2}, a_{i-1}, a_{i}
    for (int i = n-1; i > 1; --i) {
        if (NUMS[i-1] > NUMS[i]) {
            ll diff = NUMS[i]-NUMS[i-1];
            NUMS[i-1] += diff;
            NUMS[i-2] += diff;// NUMS[i]-NUMS[i-1];
        }
    }



    for (int i = 0; i < n-1; ++i) {
        if (NUMS[i] > NUMS[i+1]) {cout << "NO\n"; return;}
    }

    cout << "YES\n";
   
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
