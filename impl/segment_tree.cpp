// Author: Sebastian Bauer
// Date: Feb 27, 2023

#include <iostream>
#include <vector>

using namespace std;

// Segment Tree
//
// RMQ(i,j): Index of minimum element in range(i,j)
//
//
// Simple: Iterate from [i,j] O(n)
//
// Root of segment tree: [0, n-1]
//   - for each seg
//
class SegmentTree {
	public:
		SegmentTree(const vector<int>& arr) {
			m_arr = arr;
			m_size = arr.size();
			m_segtree.assign(4 * m_size, 0); 
		
			build(1, 0, m_size-1);
		}

		build(int p, int l, int r) {
			if (l == r)
				m_segtree[p] = L;
			else {
				build(left(p), l, (l + r) / 2);
				build(right(p), (l + r) / 2 + 1, r);

				int p1 = m_segtree[left(p)];
				int p2 = m_segtree[right(p)];

				m_segtree[p] = (m_arr[p1] <= m_arr[p2]) ? p1 : p2;
			}
		}

	private:

		int left(int p) {return p << 1;}
		int right(int p) {return (p << 1) + 1;}

		vector<int> m_segtree;
		const vector<int> m_arr;
		int m_size;
};

int main() {


	return 0;
}
