#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <tuple>

using namespace std;

#define LSOne(x) (x & (-x))

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

class FenwickTree {

    public:
        FenwickTree(int size) {
            m_size = size + 2;
            m_elements.resize(m_size, 0);
        }

        ll rsq(int idx) {
            ll sum = 0;

        }

    private:
        int m_size;
        vector<ll> m_elements;

};


// Each operation increases array by di
//  => applying this operation k times increases by di * k
void solution() {
    int n, m, k; cin >> n >> m >> k;
    vector<ll> numbers(n); for (int i = 0; i < n; ++i) cin >> numbers[i];

    vector<tuple<int,int,ll>> op(m);
    for (int i = 0; i < m; ++i) {
        cin >> get<0>(op[i]); cin >> get<1>(op[i]); cin >> get<2>(op[i]);
    }

    // FenwickTree t1(m);

    // Delta coding
    vector<ll> oApplied(m+3, 0);

    for (int i = 0; i < k; ++i) {
        int x,y; cin >> x >> y;
        x--;
        y--;
        // Delta coding 
        oApplied[x] += 1;
        oApplied[y+1] -= 1;
    }

    vector<ll> total(n+3,0);
    ll amount = 0;
    for (int i = 0; i < m; ++i) {
        int l = get<0>(op[i]);
        int r = get<1>(op[i]);
        ll del = get<2>(op[i]);
        amount += oApplied[i];
        l--;
        r--;
        total[l] += del * amount;
        total[r+1] -= del * amount;
    }

    ll inc = 0;
    for (int i = 0; i < n; ++i) {
        inc += total[i];
        cout << numbers[i] + inc << " ";
    }

    cout << "\n";
}

void solution2() {

}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	// solution();
    solution2();

	return 0;
}
