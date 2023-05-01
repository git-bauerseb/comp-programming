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


enum {
	// 11 -> right & up
	UR = 3,
	// 10 -> right & down
	DR = 2,
	// 01 -> left & up
	UL = 1,
	// 00 -> left & down
	DL = 0
};

// xy
// x = 1: right, x = 0: left
//
// y = 1: up, y = 0: down

int CHANGE[4][2] =
 {
 	{1,-1}, // DL
	{-1,-1}, // UL
	{1,1},  // DR
	{-1,1} // UR
 };


void solution() {
	int n,m;
	int i1, j1;
	int i2, j2;
	int dir = 0;
	string d;
	cin >> n >> m >> i1 >> j1 >> i2 >> j2 >> d;

	if (!d.compare("DR")) dir = DR;
	else if (!d.compare("DL")) dir = DL;
	else if (!d.compare("UR")) dir = UR;
	else dir = UL;

	int steps = 0;
	int bounces = 0;
	bool found = false;
	while (steps < n*m) {
		if (i1 == i2 && j1 == j2) {found = true; break;}
		// Check if in corner change direction
		int oldDir = dir;
		// Right side -> move to the left 
		if (j1 == m) dir &= 1;
		
		// Left side -> move to the right
		if (j1 == 1) dir |= 2;

		// Top -> Move down
		if (i1 == 1) dir &= 2;

		// Bottom -> Move up
		if (i1 == n) dir |= 1;
		bounces += (oldDir != dir) ? 1 : 0;
		i1 += CHANGE[dir][0];
		j1 += CHANGE[dir][1];
		steps++;
	}

	if (found)
	cout << bounces << "\n";
	else
		cout << "-1\n";
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
