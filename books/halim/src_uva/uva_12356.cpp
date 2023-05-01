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

const int N_MAX = 100003;
int LEFT[N_MAX];
int RIGHT[N_MAX];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	while (true) {
		int S, B; cin >> S >> B;
		if (S == 0 && B == 0) break;

		for (int i = 1; i <= S; ++i) {LEFT[i] = i-1; RIGHT[i] = i+1;}
		LEFT[1] = -1; RIGHT[S] = -1;

		for (int i = 0; i != B; ++i) {
			int l,r; cin >> l >> r;
			LEFT[RIGHT[r]] = LEFT[l];
			if (LEFT[l] != -1) cout << LEFT[l] << " ";
			else cout << "* ";
			RIGHT[LEFT[l]] = RIGHT[r];
			if (RIGHT[r] != -1) cout << RIGHT[r] << "\n";
			else cout << "*\n";	
		}

		cout << "-\n";
	}

	return 0;
}
