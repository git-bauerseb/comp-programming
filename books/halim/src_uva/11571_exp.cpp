#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;

long long A, B, C;

#define EPS 1e-12

bool is_solution(double x, double y, double z) {
	return 
		abs(x-y) > EPS
		&& abs(x-z) > EPS
		&& abs(y-z) > EPS
		&& abs(x + y + z - A) < EPS
		&& abs(x*y*z - B) < EPS
		&& abs(x*x+y*y+z*z - C) < EPS;
}

int main() {
	int tt;
    long long x;
	scanf("%d\n", &tt);;

	while(tt--) {
		bool solution = false;
		scanf("%lld %lld %lld\n", &A, &B, &C);

		long xMax = min(min(A/3.0, ceil(pow(B, 0.34))),
				ceil(sqrt(static_cast<double>(C)/3.0))) + 4;
		
		for (x = -xMax; x != xMax; ++x) if (x*x <= C && x != 0) {
			long double discr = -2*x*x - (x-A)*(x-A) + 2*C;
			if (discr < 0) continue;

			long double y1 = 0.5*(-x + A + sqrt(discr));
			long double y2 = 0.5*(-x + A - sqrt(discr));
			if (y1 > y2) swap(y1, y2);

			if (is_solution(x, y1, A - x - y1)) { 
				long double res[3] = {static_cast<long double>(x), y1, A-x-y1};
				sort(res, res+3);
				printf("%0.Lf %0.Lf %0.Lf\n", res[0], res[1], res[2]);
				solution = true;
				goto end;	
			} else if (is_solution(x, y2, A - x - y2)) {
				long double res[3] = {static_cast<long double>(x), y2, A - x - y2};
				sort(res, res+3);
				printf("%0.Lf %0.Lf %0.Lf\n", res[0], res[1], res[2]);
				solution = true;
				goto end;
			}
		}
	
		end:
	
		if (!solution)
			printf("No solution.\n");
	}


	return 0;
}
