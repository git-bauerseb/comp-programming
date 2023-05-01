# Halim - Exercises

## Chapter 2

### 2.2.1

1)
  - Sort array O(n log n)
  - Then do linear search over sorted array O(n)
    => O(n log n)

2)	
  - Sort array O(n log n)
  - Look for v - a in sorted array -> binary search O(log n)
    => O(n log n)

3)
  - Look for v - a in sorted array -> binary search
    => O(log n)

4) 
  - Sort array O(n log n)
  - Then do linear search O(n)
    => O(n log n)

5)
  - Do linear search O(n) over array
  - Store maximum length and current length so far
  - If next element is < previous then set current length to 0
    => O(n)

6)
  - Sort array O(n log n)
  - Do linear search until (n-1)/2 elements are passed; next element will be median

### 2.3.1
  - It is possible search in O(log n)
  - Insertion is not possible in O(log n) as elements need to be moved O(n)

### 2.3.3

a) Check recursively

```
	tuple<bool, int, int> check(T) {
		
		// Contains if is BST, min value, max value
		tuple<bool, int, int> left, right;
		int min, max;


		if (T.left == null && T.right == null) return {true, T.value, T.value};
		if (T.left != null) {
			left = check(T.left);
			min = left[1];
			max = left[2];	
		}
		if (T.right != null) {
			right = check(T.right);
			max = right[2];
		}
	}
```
