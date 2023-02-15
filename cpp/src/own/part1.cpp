#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

// Lower bound: Iterator to first element not satisfying condition
// E.g. If condition is v > 4 then returns pointer to element for which v <= 4
void lowerbound() {
	vector<int> nums {2,2,3,3,3,4,4,5,5,5,5,6,6,6,7,8,8,8,8,9};

	auto it = lower_bound(nums.begin(), nums.end(), -1, [](int el, int val) {
		return el < 4;		
	});

	// it pointing to first element for which !(e < 4) = e >= 4
	// Thus: it points to first 4
	cout << "Offset " << it - nums.begin() << "\n"; // 5
	cout << *it << "\n";	// 4

	// DOES NOT WORK
	// Intention: it points to first element for which !(e > 4) = e <= 4
	//   => it should point to 2
	// nums need to be sorted such that all value values left evaluate to true and then false.
	// Here: false, false, false, false, ..., true, true, ..., true
	it = lower_bound(nums.begin(), nums.end(), -1, [](int el, int val) {
		return el > 4;
	});
	cout << "Offset " << it - nums.begin() << "\n"; // 20 - not found


}


int main() {
	lowerbound();
	return 0;
}
