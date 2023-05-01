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
    int n; cin >> n;

    vector<int> used;
    int applied = 0;

    if (n % 2 == 0) {cout << "-1\n"; return;}

    while (n > 3 && applied < 40) {
        if (((n-1)/2) % 2 == 0) {
            n = (n+1)/2;
            applied++;
            used.push_back(1);
        } else {
            n = (n-1)/2;
            applied++;
            used.push_back(2);
        }
    }

    if (applied == 40) { cout << "-1\n"; return;}
    else {
        if (n == 3) {
            if (applied == 40) {cout << "-1\n"; return;}  
            used.push_back(2);
        } else if (n == 2) {cout << "-1\n"; return;}

        cout << used.size() << "\n";
        reverse(used.begin(), used.end());
        for (auto& e : used) cout << e << " ";
        cout << "\n";
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
