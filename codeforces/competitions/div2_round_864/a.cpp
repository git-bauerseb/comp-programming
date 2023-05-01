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
    int n,m; cin >> n >> m;
    int x1, y1, x2, y2;
    cin >> x1 >> y1 >> x2 >> y2;

    int max_ = min(n,m);

    // Corner case
    if ((x1 == n && y1 == m)
    || (x1 == 1 && y1 == m)
    || (x1 == n && y1 == 1)
    || (x1 == 1 && y1 == 1)) {
        max_ = min(2, max_);
    }



    if ((x2 == n && y2 == m)
    || (x2 == 1 && y2 == m)
    || (x2 == n && y2 == 1)
    || (x2 == 1 && y2 == 1)) {
        max_ = min(2,max_);
    }


    // Side case
    if ((x1 == 1) 
    || (x1 == n)
    || (y1 == 1)
    || (y1 == m)) {max_ = min(3,max_);}
    
    
    if ((x2 == 1) 
    || (x2 == n)
    || (y2 == 1)
    || (y2 == m)) {max_ = min(3,max_);}

    max_ = min(4,max_);
    cout << max_ << "\n";
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
