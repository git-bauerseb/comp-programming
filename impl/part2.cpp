#include <iostream>
#include <vector>

using namespace std;

// Least significant bit set
#define LSOne(x) ((x) & (-x))

// A Fenwick tree holding n elements used for dynamic range sum queries
// Operations:
//   rsq(i): Calculate the cumulative sum from a[0] to a[i-1] (a[i] not included)
//   rsq(i,j): Calculate cumulative sum from a[i] to a[j-1] (a[j] not included)
//   adjust(i,v): set ith element of original array to value v
class FenwickTree {
	public:
		FenwickTree(int n) {
			m_ft.resize(n);
			m_n = n;
		}

		FenwickTree(vector<int>& v) {
			m_ft.resize(v.size());
			m_n = v.size();
			
			int idx = 0;
			for (auto& e : v)
				adjust(idx++, e);
		}

		void adjust(int idx, int value) {
			idx++;
			while (idx <= m_n) {
				// Fenwick tree operates on array starting at 1
				// thus subtract 1 to get index where element is stored
				m_ft[idx-1] += value;
				idx += LSOne(idx);
			}
		}

		// Range sum query
		//   Description: Calculate the cumulative sum from a[0], ..., a[idx-1]
		int rsq(int idx) {
			int csum = 0;
			while (idx > 0) {
				csum += m_ft[idx-1];
				idx -= LSOne(idx);
			}
			return csum;
		}

		int rsq(int i, int j) {
			return rsq(j) - (i == 0 ? 0 : rsq(i-1));
		}

	private:
		vector<int> m_ft;
		int m_n;
};

int main() {

	vector<int> nums{2,4,5,5,6,6,6,7,7,8,9};
	FenwickTree t(11);

	for (int i = 0; i != 11; ++i) t.adjust(nums[i]-1, 1);

	printf("%d\n", t.rsq(0,0));
	printf("%d\n", t.rsq(0,2));
	printf("%d\n", t.rsq(0,6));
	printf("%d\n", t.rsq(0,10));
	printf("%d\n", t.rsq(3,6));
	t.adjust(4,2);
	printf("%d\n", t.rsq(0,10));

	return 0;
}
