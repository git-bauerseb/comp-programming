#include <iostream>
#include <bitset>
#include <algorithm>
#include <vector>
#include <set>
#include <stack>
#include <string>
#include <cstring>
#include <stdlib.h>

using namespace std;

// IDEA 1:
//   - enumerate all 2^n subsets and check --> too slow
//
// IDEA 2 (Improvement):
//   - Only generate all elements with equal number of 1's/0's -> 2*n choose n possibilities

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

string output;
string input;

char WORD[255];

void backtrack(vector<string>& solutions, stack<char>& st, 
		string& current, long path, int pushes, int pops) {
	const int n = output.size();
	if (pushes == n && pops == n) {
		int idx = 1;
		int i = 0;
		string p; p.resize(2*n);
		while (idx < (1 << 2*n)) {
			p[i++] = (path & idx) ? 'i' : 'o';
			idx <<= 1;
		}
		solutions.push_back(p);
		return;
	}

	if (pushes > pops && pops < n) {
		char t = st.top();
		current.push_back(t);
		auto it = mismatch(current.begin(), current.end(), output.begin());
		if (it.first == current.end()) {
			st.pop();
			backtrack(solutions, st, current, path, pushes, pops+1);
			st.push(t);
		}
		current.pop_back();
	}

	if (pushes < n) {
		st.push(input[pushes]);
		path |= (1 << (pops+pushes));
		backtrack(solutions, st, current, path, pushes+1, pops);
		st.pop();
	}
}

bool isPerm(string& a, string& b) {
	for (char & c : a) WORD[c]++;
	for (char & c : b) WORD[c]--;
	for (int i = 0; i < 255; ++i) {
		if (WORD[i] != 0) return false;
	}
	return true;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	char* l1 = NULL;
	char* l2 = NULL;

	size_t len1 = 0;
	size_t len2 = 0;

	ssize_t r1 = 0, r2 = 0;

	while ((r1 = getline(&l1, &len1, stdin)) > 0) {
		r2 = getline(&l2, &len2, stdin);
		l1[r1-1] = '\0';
		l2[r2-1] = '\0';

		input = string(l1);
		output = string(l2);
		const int n = output.size();

		if (input.size() != output.size() || !isPerm(input, output)) {
			cout << "[\n]\n"; continue;
		}
	
		vector<string> solutions;
		stack<char> st;
		string curr;
		backtrack(solutions, st, curr, 0L, 0, 0);
		cout << "[\n";
		sort(solutions.begin(), solutions.end());
		for (int i = 0; i < solutions.size(); ++i) {
			for (int j = 0; j < 2*n; ++j) {
				cout << solutions[i][j];
				if (j != (2*n-1)) cout << " ";
			}
			cout << "\n";
		}	
		cout << "]\n";
	}

	delete[] l1;
	delete[] l2;

	return 0;
}
