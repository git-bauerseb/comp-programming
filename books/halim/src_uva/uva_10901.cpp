#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <queue>

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

const int N_MAX = 10001;

// Number of minutes waited by each car
int WAITING[N_MAX];

void solution() {
	int n, t, m;
	cin >> n >> t >> m;
	char ferryPos = 'l';

	queue<pair<int,int>> wLeft;		// (CarIdx, Arrival) at left side
	queue<pair<int,int>> wRight;	// (CarIdx, Arrival) at right side

	for (int i = 0; i != m; ++i) {
		int  w;
		string side;
		cin >> w >> side;
		if (side == "left") wLeft.push({i, w});
		else wRight.push({i,w});
	}

	int cTime = 0;
	while (!wLeft.empty() && wRight.empty()) {
		// Ferry at left side and there are cars
		if (ferryPos == 'l' && !wLeft.empty()) {
			int loaded = 0;
			cTime += t;
			while (loaded <= n && !wLeft.empty() && wLeft.front().second <= cTime-t) {
				loaded++;
				auto e = wLeft.front(); wLeft.pop();
				WAITING[e.first] = cTime;
			}
			ferryPos = 'r';
		} // Ferry at right side and there are cars
		else if (ferryPos == 'r' && !wRight.empty()) {
			int loaded = 0;
			cTime += t;
			while (loaded <= n && !wRight.empty() && wRight.front().second <= cTime-t) {
				auto e = wRight.front(); wRight.pop();
				WAITING[e.first] = cTime;
			}
			ferryPos = 'l';
		} // Ferry at right side and cars at left
		else if (ferryPos == 'r' && !wLeft.empty()) {
			int loaded = 0;
			cTime += 2*t;
			while (loaded <= n && !wLeft.empty() && wLeft.front().second <= cTime-t) {
				auto e = wLeft.front(); wLeft.pop();
				WAITING[e.first] = cTime;
			}
		} else if (ferryPos == 'l' && !wRight.empty()) {
			int loaded = 0;
			cTime += 2*t; 
			while (loaded <= n && !wRight.empty() && wRight.front().second <= cTime-t) {
				auto e = wRight.front(); wRight.pop();
				WAITING[e.first] = cTime;
			}
		}		
	}

	for (int i = 0; i != m; ++i) {
		cout << WAITING[i] << "\n";
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int tt;
	cin >> tt;
	while (tt--) {
		solution();
		if (tt > 0)
		cout << "\n";
	}

	return 0;
}
