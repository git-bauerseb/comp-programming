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

const int N_MAX = 26*26;
int OCC[N_MAX];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int len; cin >> len;
	string s; cin >> s;

	for (int i = 0; i < len-1; ++i) {
		char fC = s[i];
		char sC = s[i+1];

		OCC[(fC - 'A')*26+(sC - 'A')]++;
	}

	int max = -1;
	int idx = -1;
	for (int i = 0; i != N_MAX; ++i) {
		if (OCC[i] > max) {max = OCC[i]; idx = i;}
	}

	char fC = (idx / 26) + 'A';
	char sC = (idx % 26) + 'A';
	cout << fC << sC << "\n";

	return 0;
}
