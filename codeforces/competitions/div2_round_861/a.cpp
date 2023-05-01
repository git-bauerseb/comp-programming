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

inline int luckiness(int n) {
    int largest = -1;
    int smallest = 10;

    while (n > 0) {
        int dig = n % 10;
        largest = max(dig, largest);
        smallest = min(dig, smallest);
        n /= 10;
    }

    return largest - smallest;
}

void solution() {
    int l, r;
    cin >> l >> r;

    int m_ = -1;
    int num_ = -1;
    for (int i = l; i <= min(l+110, r); ++i) {
        if (luckiness(i) > m_) {
            m_ = luckiness(i);
            num_ = i;
        }
    }

    cout << num_ << "\n";
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
