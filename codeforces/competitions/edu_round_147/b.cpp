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

// 1 2 3 4 5 6 7 8 9
//
// Old: 1 2 3 4 5 7 9 6 8 10 11
// New: 1 2 3 4 5 6 7 8 9 11 10
//
// If sorted => entire array (1,n)
// 
void solution() {
    int n; cin >> n;
    vi original(n); for (int i = 0; i < n; ++i) cin >> original[i];
    
    bool sorted = true;
    vi ne(n); for (int i = 0; i < n; ++i) {
        cin >> ne[i];
        sorted &= i == 0 || ne[i] >= ne[i-1];
    }

    if (sorted) {printf("%d %d\n", 1, n); return;}

    int gStart = 0;
    int gEnd = 0;

    int start = 0;
    int end = 0;

    int gLen = 0;
    int len = 0;

    bool inArray = false;

    for (int i = 0; i < n; ++i) {
        // Array changed and we started new array
        if (!inArray && ne[i] != original[i]) {
            inArray = true;
            start = end = i;
            len = 1;
        } else if (inArray && ne[i] >= ne[i-1]) {
            len++;
            end++;
        } else if (i == 0 || ne[i] < ne[i-1]) {
            inArray = false;
            if (len > gLen) {
                gLen = len;
                gStart = start;
                gEnd = end;
            }
        }
    }

    if (len > gLen) {gStart = start; gEnd = end; gLen = len;}

    while (gStart > 0 && ne[gStart] >= ne[gStart-1]) gStart--;
    while (gEnd < n-1 && ne[gEnd] <= ne[gEnd+1]) gEnd++;


    printf("%d %d\n", gStart+1, gEnd+1);
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
