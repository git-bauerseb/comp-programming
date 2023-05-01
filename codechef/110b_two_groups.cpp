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

// Groups equal
//
//  G1 = G2
//
// If total sum odd => return false
//
// Else total sum: S = G1 + G2
//
// - If S/2 can be reached -> possible
//
//
//
// Another approach:
//   
//   Cases
//      a b c   odd  => one 1, one 2 and 1 three can be partitioned into 1&2  | 3 => true
//      a       odd  => not possible, total sum is odd => false
//      a b     odd  => Can partition if num of 1s = 2 * num of 2s
//      b       odd  => 
//      b c     odd  =>
//      a c     odd  =>
//      ()      odd  => possible (split)
//
//  Case 1
//   - a,b,c even -> split => true
//
//  Case 2
//   - c odd 
//       => one group gets one more 3
//       => other group needs one more 1&2
//         => only possible if c odd and a,b odd and a == b 
//   
//  Case 3
//   - b odd, c even
//      => one group gets one more 2
//      => other group needs 2 more 1
//
//  Case 4
//   - b odd, c odd
void solution() {
    int a,b,c; cin >> a >> b >> c;

    bool aOdd = a % 2 == 1;
    bool bOdd = b % 2 == 1;
    bool cOdd = c % 2 == 1;

    if (aOdd && bOdd && cOdd) cout << "YES\n";
    else if (aOdd && !(bOdd || cOdd)) cout << "NO\n";
    else if (aOdd && bOdd && !cOdd) {
        if (a == 2*b) cout << "YES\n";
        else cout << "NO\n";
    }

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
