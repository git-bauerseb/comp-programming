#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <bitset>

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

int cycle(ll n, ll& dSum) {
    bitset<12> used;
    int init = (n % 10);
    int cLength = 0;
    int cur = 12;
    while (!used[cur]) {
        used[cur] = true;
        cur = ((cLength+1)* init) % 10;
        dSum += cur; 
        cLength++;
    }
    
    dSum -= init;
    return cLength-1;
}

ll simSteps(ll n, ll k) {
    int init = (n % 10);
    int cLength = 0;
    ll sum = 0;

    int cur = 12;
    while (k--) {
        cur = ((cLength+1) * init) % 10;
        sum += cur;
        cLength++;
    }

    return sum;
}

void solution() {
    ll n,m; cin >> n >> m;
    ll dSum = 0;
    ll cLength = cycle(m,dSum);
    ll multiples = (n-(n%m)) / m;
    ll r = multiples % cLength;
    ll result = dSum * (multiples - r) / cLength; 
    cout << simSteps(m, r) + result << "\n";
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
