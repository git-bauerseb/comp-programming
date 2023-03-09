#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <cstring>

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

const int N_MAX = 101;
int MA[N_MAX];
int MI[N_MAX];

void solution() {
	int n; cin >> n;

	int nPos = 0;
	int nNeg = 0;

	for (int i = 0; i != n; ++i) {
		int num; cin >> num;
		nPos += (num > 0) ? 1 : 0;
		nNeg += (num < 0) ? 1 : 0;
	}

	MA[0] = 1;
	MI[0] = 1;

	int poTmp = nPos;
	int neTmp = nNeg;

	int poTmp2 = nPos;

	for (int i = 1; i != n; ++i) {
		if (poTmp2 > 1) {MA[i] = MA[i-1]+1; poTmp2--;}
		else {MA[i] = MA[i-1]-1;}
		
		if (MI[i-1] == 0) MI[i] = 1;
		else if (MI[i-1] == 1 && neTmp > 0) {MI[i] = 0; neTmp--;}
		else {MI[i] = MI[i-1]+1;}
	}

	for (int i = 0; i != n-1; ++i) {cout << MA[i] << " ";} cout << MA[n-1] << "\n";
	for (int i = 0; i != n-1; ++i) {cout << MI[i] << " ";} cout << MI[n-1] << "\n";	

	memset(MA, 0, sizeof(MA));
	memset(MI, 0, sizeof(MI));
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
