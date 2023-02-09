#include <bits/stdc++.h>

using namespace std;

/*
 	Bruteforce:

		- for each pair (i,j) i <= j compute number of ones
		- keep track of the maximum
*/

int main() {

	int N;
	cin >> N;

	vector<int> nums(N,0);
	for (int i = 0; i != N; ++i)
		cin >> nums[i];

	int maxNum = -1;

	for (int i = 0; i != N; ++i)
		for (int j = i; j != N; ++j) {
			int sum = 0;


			for (int k = 0; k != N; ++k)
				sum += k >= i && k <= j ? 1 - nums[k] : nums[k];

				maxNum = max(maxNum, sum);

		}

	cout << maxNum << "\n";

	return 0;
}
