#include <iostream>

using namespace std;

// Disjoint Set Union
//
// make_set(v) - create new set consisting of element v
// union_sets(a,b) - merge two specified sets
// find_set(v) - returns representative of the set that contains the element

// Idea: Store in form of trees
//  -> path compression

class DSU {
	public:
		// Create DSU that supports disjoint set union with elements
		// 0, ..., capacity-1
		DSU(int capacity) {
			m_capacity = capacity;
			m_elements = new int[m_capacity];
			m_size = new int[m_capacity]();
		}

		void make_set(int v) {
			m_elements[v] = v;
			m_size[v] = 1;
		}

		int find_set(int v) {
			if (v == m_elements[v]) return v;
			// Path compression -> leads to O(log n)
			m_elements[v] = find_set(m_elements[v]);
			return m_elements[v];
		}

		void union_sets(int a, int b) {
			a = find_set(a);
			b = find_set(b);
			if (a != b) {
				if (m_size[a] < m_size[b])
					swap(a,b);
			
				m_elements[b] = a;
				m_size[b] += a;
			}
		}

		~DSU() {
			if (m_elements != nullptr) {
				delete[] m_elements;
			}
		}

	private:
		int m_capacity;
		int* m_elements;
		int* m_size;		// Size of each tree
};



int main() {

	DSU dsu(4);
	dsu.make_set(0);
	dsu.make_set(1);
	dsu.make_set(2);
	dsu.make_set(3);

	dsu.union_sets(0,1);
	dsu.union_sets(2,3);

	// Belong to same set so same representative
	cout << dsu.find_set(2) << "\n";
	cout << dsu.find_set(3) << "\n";

	return 0;
}
