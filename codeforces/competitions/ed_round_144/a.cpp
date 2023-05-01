#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <string>

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

}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);


	string pattern("FBFFBFFBFBFFBFFBFB");

	int tt;
	cin >> tt;
	while (tt--) {
	
		int k;
		cin >> k;
		string s;

		cin >> s;
	
		if (pattern.find(s) != std::string::npos) {
			cout << "YES\n";
		} else {
			cout << "NO\n";
		}
	}

	return 0;
}
