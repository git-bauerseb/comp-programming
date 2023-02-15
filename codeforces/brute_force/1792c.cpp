#include <bits/stdc++.h>

using namespace std;

int findIdx(vector<int>& nums, int n) {
	for (int i = 0; i != nums.size(); ++i)
		if (nums[i] == n) return i;
	return -1;
}

int main() {

	int tt;
	cin >> tt;

	while (tt--) {

		int n;
		cin >> n;

		vector<int> nums(n);
		cin >> nums[0];
		bool sorted = true;
		int cMax = nums[0];
		for (int i = 1; i != n; ++i) {
			cin >> nums[i];
			if (nums[i] < cMax) {sorted = false;}
			else cMax = nums[i];
		}

		if (sorted) {cout << "0\n"; continue;}

		int k = (n+2)/2;
		
		while (k > 1 && (findIdx(nums,k-1)<findIdx(nums, k) 
    					&& findIdx(nums, n-k+2) > findIdx(nums, n-k+1))) {k--;}
		cout << k-1 << "\n";
	}

	return 0;
}
