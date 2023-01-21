2.2.1

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


