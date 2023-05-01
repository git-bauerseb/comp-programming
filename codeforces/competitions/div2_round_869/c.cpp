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

const int N_MAX = 200'003;
// int ft[N_MAX];

#define LSOne(x) (x & (-x))

/*
int rsq(int b) {
    int sum = 0;
    for (; b; b -= LSOne(b)) sum += ft[b];
    return sum;
}

void adjust(int k, int v) {
    for (; k < N_MAX; k += LSOne(k)) ft[k] += v;
}

int rsq(int a, int b) {
    return rsq(b) - (a == 1 ? 0 : rsq(a-1));
}
*/

// Output
template <typename T>
void print_v(vector<T>& v) {cout << "{"; for (auto& x : v) cout << x << " "; cout << "\n";}

/*
void solution() {
    int n, q; cin >> n >> q;

    if (n < 3) {
        for (int i = 0; i < q; ++i) {
            int l,r; cin >> l >> r;
            cout << n << "\n";
        }
        return;
    }

    vector<ll> numbers(n);

    cin >> numbers[0];
    cin >> numbers[1];

    ll pp = numbers[0];
    ll p = numbers[1];

    for (int i = 2; i < n; ++i) {
        cin >> numbers[i];
        if (numbers[i] <= p && p <= pp) {
            adjust(i+1, 1);
        }
        pp = p;
        p = numbers[i];
    }

    
    for (int qu = 0; qu < q; ++qu) {
        int l,r; cin >> l >> r;

        int toRemove = 0;
        if (r - l > 1) {
            int first = rsq(r-1);
            int second = rsq(l+1);
            toRemove = first - second;
        }

        cout << (r - l + 1 - toRemove) << "\n";
    }
    
}
*/


void solution2() {
    int n,q; cin >> n >> q;
    vector<int> nums(n);

    for (int i = 0; i < n; ++i) cin >> nums[i];

    vector<int> prefix(n-1);

    for (int i = 1; i < n-1; ++i) {
        // d = 1 iff nums[i] is an inner element
        int d = nums[i-1] >= nums[i] && nums[i] >= nums[i+1];
        prefix[i] = prefix[i-1] + d;
    }

    while (q--) {
        int l,r; cin >> l >> r;
        --l; --r;
        if (l == r) cout << "1\n";
        else cout << (r-l + 1 - prefix[r-1] + prefix[l]) << "\n";
    }
}


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	solution2();

	return 0;
}
