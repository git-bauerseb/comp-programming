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

// Idea:
//  - If both words start with same character, then solution is <first-character>*
//  - If both words end with same character, then solution is *<last-character>
//  - If both words have a common substring of length >= 2 then
//    a solution would be *<common-substring>*
//
//


// Output
template <typename T>
void print_v(vector<T>& v) {cout << "{"; for (auto& x : v) cout << x << " "; cout << "\n";}

void solution() {

}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int tt;
	cin >> tt;
	while (tt--) {
		string a,b;
		cin >> a >> b;

		if (a[0] == b[0]) cout << "YES\n" << a[0] << "*\n";
		else if (a[a.size()-1] == b[b.size()-1]) cout << "YES\n*" << a[a.size()-1] << "\n";
		else {
			bool found = false;
			for (int i = 0; i < a.size()-1; i++) {
				string sub = a.substr(i,2);

				if (b.find(sub) != string::npos) {
					cout << "YES\n*" << sub << "*\n";
				   	found = true;
					break;	
				}
			}

			if (!found) cout << "NO\n";
		}
	}

	return 0;
}
