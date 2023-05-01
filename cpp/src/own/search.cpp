#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

// Own lower_bound implementation
//template<typename ForwardIt, class T, class Compare>
template<typename Compare>
int o_lower_bound(vector<int>& nums, int l, int r, int value, Compare comp) {
	while (l < r) {
		int m = l + (r - l) / 2;
		// True if nums[m] < value (with custom less operation)
		if (comp(nums[m], value)) {
			l = m + 1;
		} else {
			r = m;
		}
	}

	return l;
}	

template<typename Compare>
int o_lower_bound2(vector<int>& nums, int l, int r, int value, Compare comp) {

}

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

	// Reverse container - 9,8,8,8,8,7,6,6
	// Search for first element !(el > 4) = el <= 4
	auto it2 = lower_bound(nums.rbegin(), nums.rend(), -1, [](int el, int val) {
		return el > 4;
	});

	cout << "Offset " << it2 - nums.rbegin() << "\n";
}

void own_lowerbound() {
	vector<int> nums {2,2,3,3,3,4,4,5,5,5,5,6,6,6,7,8,8,8,8,9};
	int idx = o_lower_bound(nums, 0, nums.size(), -1, [](int el, int val) {
		return el < 10;	
	});

	auto it = lower_bound(nums.begin(), nums.end(), -1, [](int el, int val) {
		return el < 10;
	});

	cout << "Own lower bound " << idx << "\n";
	cout << "lower bound " << it - nums.begin() << "\n";
}


void iterators() {
	vector<int> nums{2,2,3,3,3,4,4,5,5,5,5,6,6,6,7,8,8,8,8,9};
	// Reverse order
	for (auto it = nums.rbegin(); it != nums.rend(); ++it)
		cout << *it << " ";
	cout << "\n";
}

int main() {
	// iterators();
	// lowerbound();
	own_lowerbound();
	return 0;
}
