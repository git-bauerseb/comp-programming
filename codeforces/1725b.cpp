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
#define vll vector<long long>

#define si set<int>
#define sl set<long>

// Output
template <typename T>
void print_v(vector<T>& v) {cout << "{"; for (auto& x : v) cout << x << " "; cout << "\n";}

// Solution using Two Pointer
// Time complexity: O(n)
//
// Idea:
//  - Sort array s.t. p0 <= p1 <= ... <= p{n-1}
//  - Iterate from back (largest player)
//      - determine how many players need to be in team to be > d
//      - update lower bound to search for players as the players
//        taken in previous round are not available
//      - do until there are no more players OR
//        in one operation we cannot form a team
//        (because the numbers are sorted, any player with <= skill
//        also cannot form team)
void solution() {
    ll n, d; cin >> n >> d;
    vll p(n);

    for (int i = 0; i < n; ++i) cin >> p[i];
    if (n == 1) {cout << (p[0] > d ? 1 : 0) << "\n"; return;}

    sort(p.begin(), p.end());

    int r = n-1;
    int l = 0;
    ll teams = 0;

    while (r >= l) {
        if (p[r] > d) {r--; teams++; continue;}
        int start = l;
        while (l < r && (l-start+2)*p[r] <= d) {l++;} 
        if (l < r && (l-start+2)*p[r] > d) {r--; l++; teams++;}
        else break;
    }


    cout << teams << "\n";
}

// Solution using binary search
void solution2() {


}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	solution();	
	return 0;
}
