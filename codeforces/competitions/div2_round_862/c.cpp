#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <cmath>

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

void solution() {
    int n, m; cin >> n >> m;

    vector<long double> ks (n);
    for (int i = 0; i < n; ++i) cin >> ks[i];
    sort(ks.begin(), ks.end());

    for (int i = 0; i < m; ++i) {
        long double a,b,c; cin >> a >> b >> c;

            if (a * c < 0) {
                cout << "NO\n";
            } else {

                long double uBound =  static_cast<double>(b) + 2 * std::sqrt(a*c);
                long double lBound = static_cast<double>(b) - 2 * std::sqrt(a*c); 


                /*
                auto it = find_if(ks.begin(), ks.end(), [=](const long double value) {
                    return value > lBound && value < uBound;     
                });
                */

                // element < uBound -> First element >= uBound
                auto it1 = lower_bound(ks.begin(), ks.end(), uBound); 
                // Search for element s.t. element > lBound
                auto it2 = upper_bound(ks.begin(), it1, lBound);


                if (it2 < it1) {
                    cout << "YES\n";
                    cout << static_cast<long>(*(--it1)) << "\n";
                } else {
                    cout << "NO\n";
                }
        }
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
