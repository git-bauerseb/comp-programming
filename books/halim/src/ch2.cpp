#include <iostream>
#include <vector>
#include <bitset>

using namespace std;

int remainder_bit(int s, int n) {
	// s = 111; n = 100; r = 100
	// s = 110; n = 100; r = 10
	// s = 0; n = 100; r = 0
	// => Keep last two bits
	return (s & (n-1));
}

bool is_power_2(int n) {
	// Determine if last bit set is only bit
	return (n & (-n)) == n;
}

int turn_last_off(int n) {
	return n ^ (n & (-n));
}

int turn_last_zero_on(int n) {
	// n = 41 = 101001
	// n+1 = 101010
	//
	// n = 39 = 100111
	// n+1 = 101000
	return n | (n+1);
}

int turn_consec_off(int n) {
	// n = 1101 1100
	// output = 1100 0000
	return n & (n+1);
}

int main() {
	
	// Test remainder
	/*
	for (int i = 0; i < 10; i++)
		cout << remainder_bit(i, 4) << " ";
	cout << "\n";

	for (auto& e : {2,4,8,16,31})
		cout << is_power_2(e) << " ";
   	cout << "\n";	

	cout << turn_last_off(40) << "\n";
	cout << turn_last_zero_on(41) << "\n";
	*/
	cout << turn_consec_off(55) << "\n";


	return 0;
}
