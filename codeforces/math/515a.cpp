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

// Idea
//
//  - has to go abs(a) + abs(b) steps
//  - if s > abs(a) + abs(b) then he can decide to 
//      - reach (a,b) first
//      - then alternate between (a+1,b) <-> (a,b) until he reaches s steps
//          - if s - (abs(a)+abs(b)) is even, he can reach (a,b)
//          - otherwise, he cannot
//  

// Output
template <typename T>
void print_v(vector<T>& v) {cout << "{"; for (auto& x : v) cout << x << " "; cout << "\n";}

void solution() {
    ll a,b,s; cin >> a >> b >> s;
    ll nec = abs(a) + abs(b);

    if (s < nec) {cout << "NO\n";}
    else {
        s -= nec;
        if (s % 2 == 0) cout << "YES\n";
        else cout << "NO\n";
    }   
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
    solution();
	return 0;
}
