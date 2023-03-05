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

const int N_MAX = 100'002;
int B[N_MAX];
int NU[N_MAX];

void solution2() {
	int n;
	cin >> n;
	for (int i = 0; i != n; ++i) cin >> NU[i];

	int j = n-1;
	for (int i = n-1; i >= 0; i--) {
		while (NU[j] / (i-j+1) > 0) {j--;}
		B[i] = i-j;
	}	

	for (int i = 0; i != (n-1); ++i) cout << B[i] << " ";
	cout << B[n-1] << "\n";
}

// Improved version of Problem C using Two pointer
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int tt;
	cin >> tt;
	while (tt--) {
		solution2();
	}

	return 0;
}
