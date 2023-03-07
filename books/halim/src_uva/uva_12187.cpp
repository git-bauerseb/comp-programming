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

const int D_MAX = 100;
int CURR[D_MAX*D_MAX];
int BUFF[D_MAX*D_MAX];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	while (true) {
		// N: number of heirs
		// R,C: dimension of kingdom
		// K: number of battles
		//
		// 0 - first heir, 1 second heir, ...
		
		int N,R,C,K;
		cin >> N >> R >> C >> K;
		if (N == 0 && R == 0 && C == 0 && K == 0) break;

		for (int r = 0; r != R; ++r) {
			for (int c = 0; c != C; ++c) {
				cin >> CURR[r * C + c];	
			}
		}

		vector<pair<int,int>> off{{0,-1}, {0,1}, {-1, 0}, {1, 0}};

		// Simulate battle
		for (int i = 0; i != K; ++i) {

			for (int r = 0; r != R; ++r) {
				for (int c = 0; c != C; ++c) {
					// Attacked by
					int atBy = (CURR[r * C + c] -1 + N) % N;
					// New owner
					int owner = CURR[r * C + c];
					for (auto& o : off) {
						int cY = r + o.first;
						int cX = c + o.second;

						if (cY >= 0 && cY < R && cX >= 0 && cX < C) {
							if (CURR[cY * C + cX] == atBy) {owner = atBy; break;}
						}
					}
					BUFF[r * C + c] = owner;
				}	
			}
		
		
			swap(BUFF, CURR);
		}
			for (int r = 0; r != R; ++r) {
				for (int c = 0; c != C; ++c) {
					cout << CURR[r * C + c];
					if (c != (C-1)) cout << " ";
				}
				cout << "\n";
			}
	}

	return 0;
}
