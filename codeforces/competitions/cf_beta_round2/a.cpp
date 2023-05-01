#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
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



void solution() {
    int n; cin >> n;
    vector<pair<string,int>> scores;

    int max_ = -1E7;
    map<string,int> m1;
    for (int i = 0; i < n; ++i) {
        string s; int p; cin >> s >> p;
        m1[s] += p;
        scores.push_back({s,p});
    }

    for (auto& e : m1) {max_ = max(max_, e.second);}

    map<string,int> m2;
    for (auto& e : scores) {
        m2[e.first] += e.second;
        if (m2[e.first] >= max_ && m1[e.first] == max_) {
            cout << e.first << "\n";
            return;
        }
    }
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
    solution();
	return 0;
}
