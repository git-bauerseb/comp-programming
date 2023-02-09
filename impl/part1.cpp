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

#include <cstdlib>

using namespace std;

// UTILITY

void swap(int& a, int& b) {
	int tmp = a;
	a = b;
	b = tmp;
}


// QUICKSORT
// Quicksort partition
int partition(vector<int>& numbers, int l, int r) {
	int pivot = numbers[r-1];
	int lIdx = l;

	for (int i = l; i <= r-2; ++i) {
		if (numbers[i] <= pivot) {
			swap(numbers[lIdx], numbers[i]);
			lIdx++;
		}
	}

	swap(numbers[lIdx], numbers[r-1]);
	return lIdx;
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


// Test for correct implementation of sorting algorithm
template<typename F>
void testSortingAlgorithm(int tests, F sAlg) {
	vector<int> nums;
	
	while (tests--) {
		int num = rand() % 20;
		nums.resize(num);

		for (int i = 0; i != num; ++i)
			nums[i] = (rand() % 300);

		sAlg(nums, 0, nums.size());
		bool success = true;

		// Check if resulting vector is sorted
		for(int i = 1; i < num; ++i) {
			if (nums[i] < nums[i-1]) {
				cout << "[ERRROR|Testcase " << (i+1) << "]::Sorting algorithm\n";
				success = false;
				break;
			}
		}

		if (!success) {
			for (auto& e : nums)
				cout << e << " ";
			cout << "\n";
			break;
		}

		nums.clear();
	}
}


// MERGESORT
void merge(vector<int>& numbers, vector<int>& aux, int l, int m, int r) {
	int lPtr = l;
	int rPtr = m;

	int idx = l;
	while (lPtr < m && rPtr < r) {
		if (numbers[lPtr] <= numbers[rPtr]) {aux[idx++] = numbers[lPtr++];}
		else {aux[idx++] = numbers[rPtr++];}
	}

	while (lPtr < m) {aux[idx++] = numbers[lPtr++];}
	while (rPtr < r) {aux[idx++] = numbers[rPtr++];}

	swap(aux, numbers);
}


void mergesort(vector<int>& numbers, vector<int>& aux, int l, int r) {
	if (l >= r)
		return;

	int m = (l + r) / 2;

	// Recurse on numbers[l], ..., numbers[m-1]
	mergesort(numbers, aux, l, m);
	// Recurse on numbers[m], ..., numbers[r-1]
	mergesort(numbers, aux, m + 1, r);

	// Merge sorted subarrays
	merge(numbers, aux, l, m, r);
}

void mergesort(vector<int>& numbers, int l, int r) {
	vector<int> aux;
	aux.resize(r-l);
	mergesort(numbers, aux, l, r);
}




int main() {
	srand(42);
	
	auto mSort = [](vector<int>& numbers, int start, int end) {
		mergesort(numbers, 0, numbers.size());
	};

	testSortingAlgorithm(1,mSort);
	return 0;
}
