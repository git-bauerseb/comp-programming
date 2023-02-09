#include <bits/stdc++.h>

using namespace std;


bool recSolution(string& s, string& t, int s_ptr, int t_ptr, bool r) {

	// Possible values to go left
	stack<pair<int,int>> possL;

	// Go to the right
	if (r) {
		while (s_ptr < s.size()
				&& t_ptr < t.size()
				&& s[s_ptr] == t[t_ptr]) {
			
			if (s_ptr > 0 && t_ptr < t.size() && s[s_ptr-1] == t[t_ptr+1]) {
				possL.push({s_ptr-1, t_ptr+1});
			}
			
			s_ptr++;
			t_ptr++;
		}

		if (t_ptr == t.size()) {return true;}

		// Go to the left after going to the right
		s_ptr--;
		s_ptr--;

		if (s_ptr <= 0) {
			while (!possL.empty()) {
				auto p = possL.top();
				possL.pop();
				if (recSolution(s, t, p.first, p.second, false)) {
					return true;
				}
			}
			return false;
		}

		while (s_ptr >= 0 && t_ptr < t.size() && s[s_ptr] == t[t_ptr]) {
			s_ptr--;
			t_ptr++;
		}

		if (t_ptr != t.size()) {
			while (!possL.empty()) {
				auto p = possL.top();
				possL.pop();
				if (recSolution(s, t, p.first, p.second, false)) {
					return true;
				}
			}
			return false;
		} else {
			return true;
		}

	// Go to the left
	} else {
		while (s_ptr >= 0 && t_ptr < t.size() && s[s_ptr] == t[t_ptr]) {
			s_ptr--;
			t_ptr++;
		}

		return t_ptr == t.size();
	}


	return false;
}


int main() {
	int q;
	cin >> q;

	while (q--) {
	
		string s, t;
		cin >> s >> t;

		vector<int> pos;
		for (int i = 0; i < s.size(); ++i)
			if (s[i] == t[0])
				pos.push_back(i);

		if (pos.size() == 0) {cout << "NO\n"; continue;}

		int s_ptr = 1;
		int t_ptr = 0;

		bool found = false;

		for (auto& p : pos) {
			s_ptr = p;

			if (recSolution(s, t, p, 0, true)) {
				found = true;
				cout << "YES\n";
				break;
			}

		}


		if (!found) {
			cout << "NO\n";
		}
	}

	return 0;
}
