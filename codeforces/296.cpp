#include <bits/stdc++.h>

typedef long long ll;

using namespace std;

#define LSOne(x) ((x) & (-x))

const int N = 100'003;
ll ft1[N];
ll ft2[N];

void adjust1(int idx, int del) {
	while (idx <= N) {
		ft1[idx] += del;
		idx += LSOne(idx);
	}
}

ll rsq1(int idx) {
	int csum = 0;
	while (idx > 0) {
		csum += ft1[idx];
		idx -= LSOne(idx);
	}

	return csum;
}

void adjust2(int idx, int del) {
	while (idx <= N) {
		ft2[idx] += del;
		idx += LSOne(idx);
	}
}

ll rsq2(int idx) {
	int csum = 0;
	while (idx > 0) {
		csum += ft2[idx];
		idx -= LSOne(idx);
	}
	return csum;
}


ll nums[N];
ll ops[N][3];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int n,m,k;
	cin >> n >> m >> k;

	for (int i = 1; i <= n; ++i)
	   cin >> nums[i];	

	for (int i = 1; i <= m; ++i) {
		cin >> ops[i][0];
		cin >> ops[i][1];
		cin >> ops[i][2];
	}


	for (int i = 0; i != k; ++i) {
		int x,y;
		cin >> x >> y;
		adjust2(x, 1L);
		adjust2(y+1, -1L);
	}


	// Calculate how often operations are applied
	for (int i = 1; i <= m; ++i) {
		ft2[i] = rsq2(i);
		adjust1(ops[i][0],ft2[i]*ops[i][2]);
		adjust1(ops[i][1]+1,-ft2[i]*ops[i][2]);
	}


	for (int i = 1; i <= n; ++i) {
		ft1[i] = rsq1(i);
		cout << (nums[i] + ft1[i]) << " "; 
	}

	cout << "\n";
	return 0;
}
