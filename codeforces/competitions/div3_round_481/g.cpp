#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <tuple>
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

// Sort by examDate
bool examSort(const tuple<int,int,int,int>& first, const tuple<int,int,int,int>& second) {
	return get<2>(first) < get<2>(second);
}

void solution() {
	int n,m; cin >> n >> m;
	vi out(n);
	// (examId, startDate, examDate, numberOfDaysToPrepare)
	vector<tuple<int,int,int,int>> exams;
	for (int i = 0; i != m; ++i) {
		int s, d, c; cin >> s >> d >> c;
		out[d-1] = m+1;
		exams.push_back(make_tuple(i+1,s,d,c));
	}

	sort(exams.begin(), exams.end(), examSort);
	bool poss = true;

	for (int i = 1; i <= n; ++i) {
		int idx = 0;
		for (auto& el : exams) {
			if (out[i-1] != m+1 && get<1>(el) <= i && get<2>(el) > i && get<3>(el) > 0) {
				out[i-1] = get<0>(el);
				get<3>(el)--;
				if (get<3>(el) <= 0) {
					exams.erase(exams.begin()+idx);
				}
				break;	
			}

			idx++;
		}

		if (!poss) break;
	}


	if (!poss || exams.size() > 0) cout << "-1\n";
	else {
		for (auto& e : out) cout << e << " ";
		cout << "\n";
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	solution();
	return 0;
}
