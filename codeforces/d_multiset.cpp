#include <bits/stdc++.h>
using namespace std;

#define LSOne(x) ((x) & (-x))

const int N = 1'000'001;
int m_ft[N];

void adjust(int idx, int v) {
	while (idx <= N) {
		m_ft[idx-1] += v;
		idx += LSOne(idx);
	}
}

int rsq(int idx) {
	int csum = 0;
	while (idx > 0) {
		csum += m_ft[idx-1];
		idx -= LSOne(idx);
	}
	return csum;
}


int main() {
	
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	int n, q;
	cin >> n >> q;
 	for (int i = 0; i != n; ++i) {
		int num;
		cin >> num;
		adjust(num, 1);
	}

	for (int i = 0; i != q; ++i) {
		int qu;
		cin >> qu;
		
		// Incremeent occurrence of 'abs(qu)' by one
		if (qu > 0) {
			adjust(abs(qu), 1);
		} else {
			int l = 1;
			int r = n+1;

			while (l <= r) {
				int m = (l + r) / 2;
			
				if (rsq(m) < abs(qu)) {
					l = m + 1;
				} else if (rsq(m) >= abs(qu) && rsq(m-1) < abs(qu)) {
					adjust(m, -1);
					break;
				} else {
					r = m;
				}
			}
		}
	}

	if (rsq(n+1) > 0) {
		for (int i = 1; i != n+1; ++i) {
			if (rsq(i) - rsq(i-1) > 0) {
				cout << i << "\n";
				return 0;
			} else if (rsq(n-i+1) - rsq(n-i) > 0) {
				cout << (n-i+1) << "\n";
				return 0;
			}
		}
	} else {
		cout << "0\n";
	}

	return 0;
}

