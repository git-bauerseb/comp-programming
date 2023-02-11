#include <bits/stdc++.h>

using namespace std;

#define LSOne(x) ((x) & (-x))

const int N = 200'001;
long ft[N+1];
long csum[N+1];

void adjust(int idx, long value) {
	while (idx <= N) {
		ft[idx] += value;
		idx += LSOne(idx);
	}
}

long rsq(int idx) {
	long csum = 0;
	while (idx > 0) {
		csum += ft[idx];
		idx -= LSOne(idx);
	}

	return csum;
}

int rsq(int i, int j) {
	return rsq(j) - (i == 1 ? 0 : rsq(i-1));
}

// 5 3
// 5 2 4 1 3
//
// 2 3
// 2 3
// 1 5

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n, q;
	cin >> n >> q;

	vector<int> nums(n,0);
	for (int i = 0; i != n; ++i) {cin >> nums[i];}

	while (q--) {
		int l,r;
		cin >> l >> r;
		adjust(r+1,-1);
		adjust(l, 1);
	}

	for (int i = 1; i != n+1; ++i)
		csum[i] = rsq(i);



	sort(nums.begin(), nums.end(), greater<long long>());
	sort(csum, csum+n+1, greater<long long>());

	long long mSum = 0;
	for (int i = 0; i != n; ++i) {
		mSum += static_cast<long long>(nums[i])*csum[i];
	}

	cout << mSum << "\n";

	return 0;
}
