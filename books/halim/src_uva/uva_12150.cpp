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

const int N_MAX = 1002;

int S[N_MAX];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	while (true) {
		int N;
		cin >> N;
		if (N == 0) break;

		bool SET[N_MAX] = {false};
		int idx = 1;
		bool valid = true;

		for (int i = 0; i != N; ++i) {
			int C, P;
			cin >> C >> P;

			int sPos = idx + P;

			if (sPos < 1 || sPos > N || SET[sPos]) {
				valid = false;
			} else {
				SET[sPos] = true;
				S[sPos] = C;
			}
			idx++;
		}


		if (valid) {
			for (int i = 1; i <= N; ++i) {
				if (SET[i]) {cout << S[i]; if (i != N) cout << " ";}
			}
		} else {
			cout << "-1";
		}

		cout << "\n";
	}

	return 0;
}
