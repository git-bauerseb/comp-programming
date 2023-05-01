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

// 2 2 1
//
// prev = inf       Output: 2
// prev = 2         Output: 2 
//
void solution() {
    int n; cin >> n;

    vector<int> b(n-1); for (int i = 0; i < n-1; ++i) cin >> b[i];
    
    int prev = 2E9;

    for (int i = 0; i < n-1; ++i) {
        int same = 0;
        int num = b[i];


        while (i < n-1 && b[i] == num) {same++; ++i;}
        --i;
        
        int next = i == n-2 ? 2E9 : b[i+1];

        // Both ends are greater
        //  => add additional number to maintain the number in b
        int numToPrint = same;
        
        if (prev > num && next > num) {
            numToPrint++;

        // One end is greater, other end is less
        //  => Print same number as on the end with the less number,
        //  an additional number is gained and at the other end a number is lost
        } else if (prev > num && next < num
                || prev < num && next > num) {
        // Both ends are smaller so print one number less
        } else {
            numToPrint--;
        }

        for (int k = 0; k < numToPrint; ++k) cout << num << " ";
        prev = num;
    }

    cout << "\n";
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
