#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <utility>

using namespace std;

int main() {

	int N, R;

	cin >> N >> R;

	vector<pair<string, vector<int>>> a(N);

	for (int i = 0; i != N; ++i) {
		cin >> a[i].first;
		
		int base, size, D;
		cin >> base;
		cin >> size;
		cin >> D;

		a[i].second.push_back(base);
		a[i].second.push_back(size);
		a[i].second.push_back(D);

		for (int j = 0; j != D; ++j) {
			int lower, upper;
			cin >> lower;
			cin >> upper;

			a[i].second.push_back(lower);
			a[i].second.push_back(upper);
		}
	}

	sort(a.begin(), a.end(), [](const pair<string, vector<int>>& a,
				pair<string, vector<int>>& b) {
		return a.first < b.first;
			});

	for (int i = 0; i != R; ++i) {
		string name;
		cin >> name;

		auto it = lower_bound(a.begin(), a.end(), name,
				[](const pair<string, vector<int>>& p, const string& n) {
			return p.first < n;
				});


		int D = it->second[2];
		vector<int> indc;

		for (int j = 0; j != D; ++j) {
			int ind_;
			cin >> ind_;
			indc.push_back(ind_);
		}


		// Perform calculation of current array
		vector<int> cDs(D+1);
		cDs[D] = it->second[1];

		// Array Bound for dim 1.: (3,4)
		// Array Bound for dim 2.: (5,6)
		for (int j = D-1;  j >= 1; --j) {
			int higherIdx = (j)*2+4;
			int lowerIdx = (j)*2+3;
			cDs[j] = cDs[j+1]*(it->second[higherIdx] - it->second[lowerIdx] + 1);
		}


		cDs[0] = it->second[0];
		for (int j = 1; j != D+1; ++j) {
			int lowerIdx = (j-1)*2+3;
			cDs[0] -= cDs[j] * it->second[lowerIdx];
		}

		int ph_addr = cDs[0];
		for (int i = 1; i != D+1; ++i)
			ph_addr += indc[i-1]*cDs[i];


		cout << name << "[";
		for (int i = 0; i != D-1; ++i)
			cout << indc[i] << ", ";
		cout << indc[D-1] << "] = " << ph_addr << "\n";
	}

	return 0;
}
