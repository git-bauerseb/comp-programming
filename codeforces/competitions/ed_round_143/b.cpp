#include <bits/stdc++.h>

using namespace std;

#define LSOne(x) ((x) & (-x))

int ft[53];

void adjust(int idx, int value) {
	while (idx <= 52) {
		ft[idx] += value;
		idx += LSOne(idx);
	}
}

int rsq(int idx) {
	int csum = 0;
	while (idx > 0) {
		csum += ft[idx];
		idx -= LSOne(idx);
	}
	return csum;
}

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);


	int t;
	cin >> t;
	while (t--) {
		vector<pair<int,int>> segms;
		
		int n,k;
		cin >> n >> k;
		while (n--) {
			int l,r;
			cin >> l >> r;
			segms.push_back({l,r});
			adjust(l, 1);
			adjust(r+1, -1);
		}

		for (auto& seg : segms) {
			if (seg.first > k || seg.second < k) {
				adjust(seg.first, -1);
				adjust(seg.second+1,1);
			}
		}

		bool can = true;
		int maxPoss = rsq(k);

		for (int i = 1; i < 51; i++) {
			if (i == k) continue;
			if (rsq(i) >= maxPoss) {can = false;}
		}

		cout << (can ? "YES\n" : "NO\n");
		segms.clear();
		memset(ft, 0, sizeof(ft));
	}

	return 0;
}
