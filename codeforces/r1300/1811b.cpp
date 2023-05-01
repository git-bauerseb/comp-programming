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

//  n = 2
//
//  P1 = (1,1) => -1, -1
//  P2 = (2,2)
//
//  D_P1 = 0
//  D_P2 = 0
//
void solution() {
    int n, x1, y1, x2, y2;
    cin >> n >> x1 >> y1 >> x2 >> y2;

    int xOrigin = 


    int p1Dist = max(0,min(abs(x1),abs(y1))-1);
    int p2Dist = max(0,min(abs(x2),abs(y2))-1);

    cout << abs(p1Dist-p2Dist) << "\n";
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
