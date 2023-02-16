#include <bits/stdc++.h>

using namespace std;


int main() {

	char* line = NULL;
	size_t num = 0;

	while (getline(&line, &num, stdin) > 0) {
		int k;
		sscanf(line, "%d\n", &k);
	
		vector<pair<long,long>> sols;

		for (long y = k+1; y <= 2*k; y++) {
			long x = k*y/(y-k);
			if (x*y % (x+y) == 0 && x*y / (x+y) == k && y <= x)
				sols.push_back({x,y});
		}

		sort(sols.begin(), sols.end(),
				[](pair<long,long>& a, pair<long,long>& b) {return a.first > b.first;});
	
		cout << sols.size() << "\n";
		for (auto& s : sols) {
			printf("1/%ld = 1/%ld + 1/%ld\n", k, s.first, s.second);
		}
	}

	if (line != NULL)
		delete[] line;

	return 0;
}
