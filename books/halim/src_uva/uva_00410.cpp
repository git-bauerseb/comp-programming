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

void solution(int C, int case_) {
	int S; cin >> S;
	float am = 0;
	vector<int> masses(2*C); for (int i = 0; i != S; ++i) {cin >> masses[i]; am += masses[i];}
	am /= C;
	sort(masses.begin(), masses.end());
	
	int l,r; l = 0, r = 2*C-1;
	float imb = 0;

	printf("Set #%d\n", case_);
	int idx = 0;
	while (l <= r) {
		imb += abs(masses[l] + masses[r] - am);
		if (masses[l] == 0 && masses[r] == 0)
			printf(" %d:\n", idx);
		else if (masses[l] == 0)
			printf(" %d: %d\n", idx, masses[r]);
		else if (masses[r] == 0)
			printf(" %d: %d\n", idx, masses[l]);
		else
			printf(" %d: %d %d\n", idx, masses[l], masses[r]);
		idx++;
		l++; r--;
	}
	printf("IMBALANCE: %.5f\n", imb);
}

int main() {
	int idx = 1;
	int C;
	while (scanf("%d", &C) != EOF) {
		if (idx != 1) cout << "\n";
		solution(C, idx++);
	}

	return 0;
}
