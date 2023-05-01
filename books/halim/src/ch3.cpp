#include <iostream>
#include <algorithm>
#include <bitset>

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

void fourth() {
	int i, n = 8, p[8] = {0,1,2,3,4,5,6,7};
   	do {
		// Check condition
   	} while (next_permutation(p, p+n));	   
}

// 8 queens
int rows[8], nQ;

bool place(int r, int c) {
	// Check previously placed queens
	for (int i = 0; i != c; ++i) {
		if (rows[i] == r || abs(r - rows[i])  == abs(c - i))
			return false;
	}
	return true;
}

void backtrack(int c) {
	if (c == 8) {
		nQ++;
	}

	for (int r = 0; r != 8; ++r) {
		if (place(r, c)) {
			rows[c] = r;
			backtrack(c+1);
		}
	}
}


// rw: rows
// ld: left diagonal
// rd: right diagonal
bitset<30> rw, ld, rd;

// nfQ: number of possible ways to place queens
// nR: number of rows
int nfQ, nR;

void fasterNQueens(int c) {
	if (c == nR) {++nfQ; return;}
	for (int r = 0; r != nR; ++r)
		if (!rw[r] && !ld[r-c+nR-1] && !rd[r+c]) {
			rw[r] = ld[r-c+nR-1] = rd[r+c] = true;
			fasterNQueens(c+1);
			rw[r] = ld[r-c+nR-1] = rd[r+c] = false;
		}
}

int main() {
	// first();
	// second(12);
	// third(10+23+9, 10*23*9, 10*10+23*23+9*9);
	// backtrack(0);
	// printf("Number of ways to plaxe 8 queens on 8x8 board: %d\n", nQ);
	nR = 14;
	fasterNQueens(0);
	printf("Number of ways: %d\n", nfQ);
	
	return 0;
}
