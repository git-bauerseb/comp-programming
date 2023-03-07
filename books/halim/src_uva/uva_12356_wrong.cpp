#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <list>

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

const int N_MAX = 100005;
int LEFT[N_MAX];
int RIGHT[N_MAX];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	while (true) {
	int S,B;
	cin >> S >> B;
	if (S == 0 && B == 0) break;
	for (int i = 1; i <= S; ++i) LEFT[i] = RIGHT[i] = i; 

	for (int i = 0; i != B; ++i) {
		int l, r;
		cin >> l >> r;
		int newLBound = l-1 >= 1 ? LEFT[l-1] : -1;
		int newRBound = r+1 <= S ? RIGHT[r+1] : -1;
		LEFT[l] = newLBound;
		LEFT[r] = LEFT[l];
		RIGHT[r] = newRBound;
		RIGHT[l] = RIGHT[r];

		if (l-1 >= 1 && RIGHT[l-1] == l) {
			RIGHT[l-1] = newRBound;
			if (LEFT[l-1] >= 1)
			RIGHT[LEFT[l-1]+1] = newRBound;
		} else if (r+1 <= S && LEFT[r+1] == r) {
			LEFT[r+1] = newLBound;
			if (LEFT[r+1] <= S)
				LEFT[RIGHT[r+1]-1] = newLBound;
		}

		if (LEFT[l] == -1) cout << "* ";
		else cout << LEFT[l] << " ";

		if (RIGHT[r] == -1) cout << "*\n";
		else cout << RIGHT[r] << "\n";
	}
		cout << "-\n";
	}
	
	return 0;
}
