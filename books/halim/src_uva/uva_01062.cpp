#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <stack>

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

const int N_MAX = 30;

// Keep track of what letters are used
bool USED[N_MAX];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	vector<stack<char>> stacks(N_MAX);
	int stacksUsed = 0;
	int caseIdx = 1;
	while (true) {
		string s;
		cin >> s; if (s == "end") break;

		// Count characters
		for (auto& c : s) {USED[c - 'A'] = true;};

		// Unique is number of unique characters used
		// This provides an upper bound as for every character we can use
		// own stack
		// But not optimal
		int unique = 0;
		for (int i = 0; i < N_MAX; ++i) unique += USED[i] ? 1 : 0;
		
		for (auto& c : s) {
			bool foundStack = false;
			for (int i = 0; i < stacksUsed; ++i) {
				if (stacks[i].top() >= c) {
					stacks[i].push(c);
					foundStack = true;
					break;
				}
			}

			if (!foundStack) {
				stacks[stacksUsed++].push(c);
			}
		}	

		// Clear stacks
		for (int i = 0; i < stacksUsed; ++i) {while (!stacks[i].empty()) stacks[i].pop();}
		
		// Output
		cout << "Case " << caseIdx << ": " << min(stacksUsed, unique) << "\n";
		stacksUsed = 0;
		caseIdx++;
	}

	return 0;
}
