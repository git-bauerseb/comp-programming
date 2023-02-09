#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>

using namespace std;

int main() {
	int n, m;

	while (true) {
		cin >> n >> m;
		if (n == 0 && m == 0) break;
	
		int nums[n];

		for (int i = 0; i != n; ++i)
			nums[i] = i;

		int arr = 0;

		vector<int> constraints(3*m);

		for (int i = 0; i != m; ++i)
			cin >> constraints[3*i] >> constraints[3*i+1] >> constraints[3*i+2];

		do {
			int sat = 0;
		
			for (int i = 0; i != m; ++i) {
				int a,b,c;
				a = constraints[3*i];
				b = constraints[3*i+1];
				c = constraints[3*i+2];

				for (int f = 0; f != n; ++f)
					for (int s = f+1; s != n; ++s)
						if ((nums[f] == a && nums[s] == b)
								|| (nums[f] == b && nums[s] == a)) {
							if (c > 0 && abs(s-f) <= c) sat += 1;
							if (c < 0 && abs(s-f) >= -c) sat += 1;
						}
			}

			arr += sat == m ? 1 : 0;
		} while (next_permutation(nums, nums+n));
	
		cout << arr << "\n";
	}

	return 0;
}
