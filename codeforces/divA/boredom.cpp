#include <iostream>
#include <vector>
#include <map>
#include <utility>
#include <bitset>

using namespace std;

#define SET(x) (used[(x)/29] = used[(x)/29] | (1 << ((x) % 29)))
#define GET(x) (used[((x)/29)] & (1 << ((x) % 29)))
#define DELETE(x) (used[((x)/29)] &= (~(1 << ((x) % 29))))

int used[32];

int main() {

	map<int,int> occ;

	int N;
	int unique = 0;
	cin >> N;
	
	vector<int> nums;

	for (int i = 0; i != N; ++i) {
		int num;
		cin >> num;

		if (occ.count(num) <= 0) unique++;

		occ[num]++;
	}

	int max = 0;

	for (auto it = occ.begin(); it != occ.end(); ++it) {
		int key = it->first;

		cout << key << " occ " << occ[key] << "\n";

		if (GET(key-1) || GET(key+1)) {
			int oldVal = 0;
			
			if (GET(key-1))
				oldVal += occ[key-1]*(key-1);
			   
			if (GET(key+1))
				oldVal += occ[key+1]*(key+1);
			int newVal = occ[key]*key;

			if (newVal > oldVal) {
				max = max - oldVal + newVal;
				if (GET(key-1))
				DELETE(key-1);
				if (GET(key+1))
				DELETE(key+1);
				SET(key);
			}
		} else {
			max += occ[key]*key;
			SET(key);
		}
	}

	cout << max << "\n";

	return 0;
}
