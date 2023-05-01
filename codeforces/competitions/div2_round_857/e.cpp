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

void solution() {
	int n; cin >> n;
	// (max, tracks)
	vector<pair<int, vector<int>>> albums;
	albums.resize(n);

	int tLen = 0;
	
	for (int i = 0; i != n; ++i) {
		// Max value of current album
		int m = -1;
		int len; cin >> len; tLen += len;
		vector<int> track; track.resize(len);
		for (int j = 0; j != len; ++j) {
			int num; cin >> num;
			track[j] = num;
			m = max(m, num);
		}
		albums[i] = {m, track};
	}


	// Sort first by max then by length
	sort(albums.begin(), albums.end(),
			[](const pair<int, vector<int>>& a,
			   const pair<int, vector<int>>& b) {
			
			if (a.first < b.first) return true;
			else if (a.first > b.first) return false;
			return a.second.size() < b.second.size();
	});


	vector<int> total;
	total.reserve(tLen);

	// Concatenate to one big vector
	for (auto& e : albums) {
		total.insert(total.end(), e.second.begin(), e.second.end());
	}


	// Longest increasing subsequence
	vector<int> a(tLen);
	a[0] = total[0];
	int len = 1;
	for (int i = 1; i < tLen; ++i) {
		auto it = lower_bound(a.begin(), a.begin()+len, total[i]);
		if (it == a.begin()+len && *it > total[i]) {
			a[len++] = total[i];
		} else {
			*it = total[i];
		}
	}

	cout << len << "\n";
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
