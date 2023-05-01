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

void solution() {

    int n, x; cin >> n >> x;
    int even = 0;
    int odd = 0;
    for (int i = 0; i < n; ++i) {int num; cin >> num;
        even += (num % 2 == 0) ? 1 : 0;
        odd += (num % 2 == 0) ? 0 : 1;
    }

    if (!odd) {cout << "No\n";}
    else {
        x--;
        odd--;
        while (x > 0) {
            if (x > 1 && odd > 1) {odd -= 2; x -= 2;}
            else if (even > 0) {even--; x--;}
            else break;
        }

        if (x > 0) cout << "No\n";
        else cout << "Yes\n";
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
