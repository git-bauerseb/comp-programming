// Author: Sebastian Bauer
// Date: 2/9/23
//
// Below is my own implementation of well-known algorithms and data structures
// as an exercise to fully understand their working. The implementation is completly on my own
// (based on the "textbook description" of the algorithm.
//
// The goal here is to come up with an implementation that fully works and to get a feeling for
// common errors (off-by-one, floor-ceiling-mistake, etc.) 

#include <iostream>
#include <vector>

using namespace std;

void swap(int& a, int& b) {
	int tmp = a;
	a = b;
	b = tmp;
}


// Quicksort partition
int partition(vector<int>& numbers, int l, int r) {
	int pivot = numbers[r-1];

	int lPtr = l;
	int rPtr = r-2;

	while (lPtr < rPtr) {
		if (numbers[lPtr] > pivot
				&& numbers[rPtr] < pivot) {
			swap(numbers[lPtr], numbers[rPtr]);
			lPtr++;
			rPtr--;
		} else if (numbers[lPtr] <= pivot) {
			lPtr++;
		} else if (numbers[rPtr] >= pivot) {
			rPtr--;
		}
	}

	if (numbers[lPtr] >= pivot) {
		swap(numbers[r-1], numbers[lPtr]);
		return lPtr;
	}

	return r-1;
}

// Quicksort
//   Description: Sorting; Divide-and-Conquer
//   Runtime: O(nlog(n))
//	 Memory: O(1)
//
// l: lower index (included)
// r: upper index (excluded)
void quicksort(vector<int>& numbers, int l, int r) {
	if (l >= r) return;

	// Partition
	int m = partition(numbers, l, r);

	// m is already at correct spot
	// thus, it doesn't need to be considered in recursion

	// Divide
	quicksort(numbers, l, m);
	quicksort(numbers, m+1, r);
}

int main() {
	vector<int> numbers{9,6,4,8,1,7,3,2,5};
	quicksort(numbers, 0, numbers.size());

	for (auto& e : numbers)
		cout << e << " ";
	cout << "\n";

	return 0;
}
