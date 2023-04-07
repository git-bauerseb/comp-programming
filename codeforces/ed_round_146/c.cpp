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


// Idea:
//  - Sort boxes by occurrence (make pair (occ, idx))
//  - Loop over boxes and check index where to insert (robot 1: i, robot 2: j)
//      - If i * search time robot 1 < j * search time robot 2 put in robot 1 vector,
//          else in robot 2 vector
//
// Correctness:
//  - Minimal search time requires for each box to be reached in min. steps
//      - So if at any stage, boxes are not placed int
void solution() {
    int n, s1, s2; cin >> n >> s1 >> s2;

    vector<pair<int,int>> occs(n);
    for (int i = 0; i < n; ++i) {
        int occ; cin >> occ;
        occs[i] = {occ, i+1};
    }

    sort(occs.begin(), occs.end(),
            [](const pair<int,int>& a, const pair<int,int>& b) {
            return a.first > b.first;        
    });

    int i = 1;
    int j = 1;

    vi first;
    vi second;

    for (auto& e : occs) {
        if (i*s1 < j*s2) {
            first.push_back(e.second);
            i++;
        } else {
            second.push_back(e.second);
            j++;
        } 
    }

    cout << first.size() << " ";
    for (auto& e : first) cout << e << " ";
    cout << "\n" << second.size() << " ";
    for (auto& e : second) cout << e << " ";
    cout << "\n";
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
