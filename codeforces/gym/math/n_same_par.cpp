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

// Idea:
//  - n odd, k even => not possible
//      - because n odd, we need an odd number of odd numbers but k is even
//
//  - n odd, k odd => possible
//      - choose k 1's
//      - then n - k is even
//      - choose now two odd numbers s.t. sum is n-k
//          e.g. choose (n-k)/2 + 1 and (n-k)/2 - 1
//      - e.g. 17, 5
//          - 1,1,1,1,1 => choose two odd numbers s.t. sum is 17 - (5-2) = 14, e.g. 7,7
//              => 7,7,1,1,1
//
//  - n even, k odd => possible
//      - 
void solution() {
    ll n, k; cin >> n >> k;

    // Trivial case
    if (n == k) {
        cout << "YES\n";
        for (int i = 0; i < n; ++i) cout << 1 << " ";
        cout << "\n";
        return;
    }

    
    if (n % 2 == 1 && k % 2 == 1) {
        ll rem = n - (k-2);
        cout << "YES\n";
        for (int i = 0; i < k-2; ++i) cout << 1 << " ";

        int lo = rem/2;
        int hi = rem/2;

        while (lo % 2 == 0 || hi % 2 == 0) {lo--; hi++;}

        cout << lo << " " << hi << "\n";
  
        return;
    } 
      
  
    ll rem1 = n - (k-1);
    ll rem2 = n - (k-2);
    ll rem3 = n - (2*k - 2);

    if (rem3 > 0 && rem3 % 2 == 0) {
        cout << "YES\n"; for (int i = 0; i < k-1; ++i) cout << 2 << " ";
        if (rem3 > 0)
            cout << rem3 << "\n";
        else
            cout << "\n";
        return;
    } 
    
    
    if (rem1 % 2 == 1) {
        cout << "YES\n";
        for (int i = 0; i < k-1; ++i) cout << 1 << " ";
        cout << rem1 << "\n";
        return; 
    }
   
    if (rem2 % 2 == 0) {
        cout << "YES\n";
        for (int i = 0; i < k-2; ++i) cout << 1 << " ";
        int lo = rem2/2;
        int hi = rem2/2;
        while (lo % 2 == 0 || hi % 2 == 0) {lo--; hi++;}
        cout << lo << " " << hi << "\n";
        return;
    }

    cout << "NO\n";
}

void solution2() {
    ll n,k; cin >> n >> k;

    if (k > n) {cout << "NO\n"; return;}
    if (k == 1) {cout << "YES\n" << n << "\n"; return;}

    // 10 3
    //
    // 10 - 2 = 8
    // 10 - 1 = 9

    ll r1 = n - (k-1);
    ll r2 = n - (k-2);
    ll r3 = n - (2*k-2);

    if (r1 % 2 == 1) {
        cout << "YES\n";
        for (int i = 0; i < k-1; ++i) cout << 1 << " ";
        cout << r1 << "\n";
        return;
    }

    if (r2 % 2 == 0) {
        cout << "YES\n";
        for (int i = 0; i < k-2; ++i) cout << 1 << " ";
        int lo = r2 / 2;
        int hi = r2 / 2;
        while (lo % 2 == 0 || hi % 2 == 0) {lo--; hi++;}
        cout << lo << " " << hi << "\n";
        return;
    }

    if (r3 > 0 && r3 % 2 == 0) {
        cout << "YES\n";
        for (int i = 0; i < k-1; ++i) cout << 2 << " ";
        cout << r3 << "\n";
        return;
    }

    cout << "NO\n";
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int tt;
	cin >> tt;
	while (tt--) {
		// solution();
	    solution2();
    }

	return 0;
}
