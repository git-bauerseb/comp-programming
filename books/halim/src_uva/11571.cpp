#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;

int main() {
	int N;
	scanf("%d\n", &N);

	for (int i = 0; i != N; ++i) {
		long A, B, C;
		scanf("%ld %ld %ld\n", &A, &B, &C);

		int xLim = ceil(pow(static_cast<double>(B), 1.0/3.0));
		int yLim = ceil(sqrt(static_cast<double>(C)));
		
		int x, y, z;
		bool solution = false;
		for (x = -xLim; x != xLim; ++x) { if (x*x < C && x != 0)
			for (y = -yLim; y != yLim; ++y) if (y != x && x*x + y*y <= C) {
				z = A - x - y;
				if (x ^ y
					&& y ^ z
					&& x ^ z 
					&& x * y * z == B
					&& x*x + y*y + z*z == C) {
						long vals[3] = {x,y,z};
						sort(vals, vals+3);
						printf("%ld %ld %ld\n", vals[0], vals[1], vals[2]);
						solution = true;
						goto endloop;
				}
			}
		}

endloop:
		if (!solution)
		printf("No solution.\n");
	}

	return 0;
}
