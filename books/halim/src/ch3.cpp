#include <iostream>

using namespace std;

void first() {
	for (int N = 2; N <= 79; ++N)
		for (int fghij = 1234; fghij <= 98765/N; ++fghij) {
			int abcde = fghij * N;

			int digitsUsed = 0;
			int tmp = fghij;

			while (tmp) {
				digitsUsed |= (1 << (tmp % 10));
				tmp /= 10;
			}

			tmp = abcde;
			while (tmp) {
				digitsUsed |= (1 << (tmp % 10));
				tmp /= 10;
			}

			if (digitsUsed == (1 << 10) - 1) {
				printf("%d / %d = %d\n", abcde, fghij, N);
			}
		}
}

void second(int k) {
	int S[k];

	for (int i = 0; i != k; ++i)
		scanf("%d", &S[i]); 

	for (int a = 0; a < k - 5; ++a)
		for (int b = a + 1; b < k - 4; ++b)
			for (int c = b + 1; c < k - 3; ++c)
				for (int d = c + 1; d < k - 2; ++d)
					for (int e = d + 1; e < k - 1; ++e)
						for (int f = e + 1; f < k; ++f)
							printf("%d %d %d %d %d %d\n", S[a], S[b], S[c], S[d], S[e], S[f]);
}

void third(int A, int B, int C) {
	bool solution;
	int x,y,z;
	for (x = -57; x != 57; x++)
		for (y = -57; y != 57; y++)
			for (z = -57; z != 57; z++)
				if ((x ^ y) && (y ^ z) && (x ^ z) &&
						x + y + z == A &&
						x * y * z == B &&
						x*x + y*y + z*z == C) {
					printf("%d %d %d\n", x, y, z);
					break;
				}
}

int main() {
	// first();
	// second(12);
	third(10+23+9, 10*23*9, 10*10+23*23+9*9);
	return 0;
}
