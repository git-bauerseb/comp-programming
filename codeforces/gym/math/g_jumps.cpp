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

// Nice problem!
// - after wrong approach figured out correct one
int solution() {
    int x; cin >> x;
    
    if (x == 0) { return 0; }
    else {

        int y = 0;
        int steps = 0;
        int inc = 1;

        while (y < x) {
            y += inc;
            steps++;
            inc++;
        }

        if (y == x+1) {return steps+1;}
        else return steps;
    }
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int tt;
	cin >> tt;
	while (tt--) {
		printf("%d\n", solution());
	}

	return 0;
}
