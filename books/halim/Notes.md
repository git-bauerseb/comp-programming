# Competitive Programming - Halim

## Own notes

Two complement:

S = 40 = 000...0101000
-S = -40 = 111...1010111 + 1 = 111...1011000

-7
	-> invert; then add 1
	1000 + 1 = 1001 


## Chapter 2

**Static array** int[]

**Dynamic array** vector<int>
	- better if unkown size at compile-time
	- reserve()/resize()

	Algorithms:
		- Sorting:
			O(n log n): sort(), partial_sort(), stable_sort()
		- Searching:
			O(log n): binary_search()
			O(1): hashing

	bitset
		- 32/64 bit signed integer for up to 32/64 items
			=> use for 30/62 elements to avoid problem with Two complement

		turn-on j-th item:
			S |= (1 << j)

		turn-off j-th item:
			S &= ~(1 << j)

		switch j-th item:
			S ^= (1 << j)

		get least-significant bit that is set
			T = (S & (-S))

		check j-th item:
			T = S & (1 << j)
				- T = 0 => j-th item not set
				- T != 0 => j-th item set

		turn-on all bits in a set of size n:
			S = (1 << n) - 1

**Linked list**
	- inefficient access

**stack**
	C++ STL stack
	push()/pop(); top()

**queue**
	C++ STL queue
	push()/pop(); top()

**double-ended queue**
	C++ STL queue
	push_back()/pop_front()
	push_front()/pop_back()

## Chapter 3

### 3.5 Dynamic Programming

- determine problem states and transitions between problem and sub-problem

- primarily used: optimization/counting problems
  - minimize/maximize/count -> high chance of DP
