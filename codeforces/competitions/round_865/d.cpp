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

const int N_MAX = 1003;
int PERM[N_MAX][2];

int LOOKUP[N_MAX];

int q1(int x) {
    cout << "+ " << x << "\n";
    cout.flush();
    int ret; cin >> ret;
    return ret;
}

int q2(int i, int j) {
    cout << "? " << i << " " << j << "\n";
    cout.flush();
    int ret; cin >> ret;
    return ret;
}

// 7
// 1,2,3
void lookup(int n) {
    int in = 1;
    int de = n;
    for (int i = 1; i <= n; i+=2) {
        LOOKUP[i] = in;
        LOOKUP[i+1] = de;
        in++;
        de--;
    }
}

// 1 4 2 5 3 6
//
// 1 - 6 - 2 - 5 - 3 - 4
//
//
//
//
void solution() {
    int n; cin >> n;
    lookup(n);
    
    // Build chain
    q1(n+1);
    q1(n+2);

    int k = -1;
    int m = -1;
    for (int i = 2; i <= n; ++i) {
        int res = q2(1,i);
        if (res > m) {
            k = i;
            m = res;
        } 
    }

    PERM[k][0] = LOOKUP[n];
    PERM[k][1] = LOOKUP[1];

    // printf("MAX is at position %d\n", k);

    for (int i = 1; i <= n; ++i) {
        if (i == k) continue;
        int dist = q2(k,i);   
        // printf("Distance: %d\n", dist);
        // printf("Choice 1: %d\nChoice 2: %d\n", LOOKUP[dist+1], LOOKUP[n-dist]);
        PERM[i][1] = LOOKUP[dist+1];
        PERM[i][0] = LOOKUP[n-dist];
    }

    cout << "! ";
    for (int j = 0; j < 2; ++j) {
    for (int i = 1; i <= n; ++i) cout << PERM[i][j] << " ";
    }
    cout << "\n";
    cout.flush();
}

int main() {
	int tt;
	cin >> tt;
	while (tt--) {
		solution();
        int res; cin >> res;
        if (res == -2) return 0;
	}
	return 0;
}
