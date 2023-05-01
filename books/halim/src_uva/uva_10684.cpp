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

void solution(int n) {
    int gOpt = -1;
    int lOpt = -1E8;
    for (int i = 0; i < n; ++i) {
        int num; cin >> num;
        lOpt = max(num, lOpt + num);
        gOpt = max(gOpt, lOpt); 
    }

    if (gOpt <= 0) printf("Losing streak.\n");
    else printf("The maximum winning streak is %d.\n", gOpt);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

    while (true) {
	    int n;
	    cin >> n;

        if (!n) break;
        solution(n);
    }

	return 0;
}
