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

const int N_MAX = 100002;

int p[N_MAX];
int q[N_MAX];

// Output
template <typename T>
void print_v(vector<T>& v) {cout << "{"; for (auto& x : v) cout << x << " "; cout << "\n";}

// Idea
// - if sum of gas >= sum of needed then it is possible
//   - If sum gas >= sum of needed, there exists a position where gas >= quantity 
//     - if it is possible to complete cycle from this position then done
//     - if not then at some point, car runs out of gas => less gas than quantity
//     - but if quantity >= gas then because overall gas >= quantity
//       there exists another position where gas >= quantity
//     - if none of those positions work, then this would mean that total sum of gas < sum of needed => contradictiion
//
//
int main() {
	cin.tie(0);
	cout.tie(0);

	int tt;
	cin >> tt;
	int ca = 1;
	while (tt--) {
		int N;
		cin >> N;
		for (int i = 0; i != N; ++i) cin >> p[i];
		for (int i = 0; i != N; ++i) cin >> q[i];
		int total = 0;
		for (int i = 0; i != N; ++i) total += p[i] - q[i];
		if (total < 0) {cout << "Case " << ca << ": Not possible\n"; ca++; continue;}
		int t = 0;
		int pos = 0;
		for (int i = 0; i != N; ++i) { t += p[i] - q[i]; if (t < 0) {t = 0; pos = i+1;}}
		cout << "Case " << ca << ": Possible from station " << (pos+1) << "\n";
		ca++;
	}

	return 0;
}
