#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <cstring>

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
//  - ai & aj = ai ^ aj <=> ai = aj = 0
//      - Keep track of zeros
//      - everytime zero is encountered, add number of zeros up to that point to number
//      - increment zero
//      - but only positive
//
//  - ai & aj > ai ^ aj 
const int N_MAX = 40;
int BITS_SET[N_MAX];

ll solution() {

    int n; cin >> n;
    ll pairs = 0LL;

    for (int i = 0; i < n; ++i) {
        int num; cin >> num;

        int lIdx = 0;
        int numTmp = num;
        while (numTmp >>= 1) {lIdx++;}

        pairs += BITS_SET[lIdx];
        BITS_SET[lIdx]++;
    }

    return pairs;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int tt;
	cin >> tt;
	while (tt--) {
    	ll ans = solution();
        printf("%lld\n", ans);
        memset(BITS_SET, 0, sizeof BITS_SET);
	}

	return 0;
}
