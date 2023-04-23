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

// ones[i] := Number of intervals of size 1 up to i
int ones[200'001];
int covered[200'001];

int LEFT[200'001];
int RIGHT[200'001];

void solution() {
    int n,k; cin >> n >> k;
    for (int i = 0; i < n; ++i) cin >> LEFT[i];
    for (int i = 0; i < n; ++i) {
        cin >> RIGHT[i];

        // Calculate size 1 elements up to i
        ones[i] = (i == 0 ? 0 : ones[i-1])
                + (RIGHT[i] - LEFT[i] == 0);
        covered[i] = (i == 0 ? 0 : covered[i-1])
                + RIGHT[i] - LEFT[i] + 1;
    }

    // int idx = (int)(lower_bound(covered, covered+n, k) - covered);

    if (covered[n-1] < k) {printf("-1\n"); return;}
    else {
        ll mCost = 1E18;

    
        for (int i = 0; i < n; ++i) {
            if (covered[i] >= k) {
    
                int lo = -1;
                int hi = ones[i]+1;

                while (hi - lo > 1) {
                    int m = lo + (hi - lo) / 2;
                    if (covered[i] - m < k) {hi = m;}
                    else {lo = m;}
                }

                ll cCost = 2 * (i + 1 - hi);
                cCost += LEFT[i];
                ll kNew = k - (i == 0 ? 0 : covered[i-1]) + hi;
                cCost += (kNew);
                mCost = min(mCost, cCost);
            }
        }


        /*
        for (int i = ones[idx]; i >= 0; --i) {
            if (covered[idx] - i >= k) {
                // Number of shift operations
                // = number of intervals - number of ones excluded
                ll cCost = 2*(idx + 1 - i);
                // Cost of moving to the latest interval
                cCost += LEFT[idx];
                ll kNew = k - (idx == 0 ? 0 : covered[idx-1]) + i;
                cCost += (kNew - 1);

                mCost = min(mCost, cCost);
            }
        }
        */
            
        printf("%lld\n", mCost);
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
