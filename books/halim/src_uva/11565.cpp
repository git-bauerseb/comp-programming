#include <iostream>

using namespace std;



int main() {

	int tt;
	cin >> tt;
	for (int i = 0; i != tt; ++i) {
		int a, b, c;
		cin >> a >> b >> c;

		int x, y, z;
		bool solution = false;
		for (x = -58; x != 58; ++x)
			for (y = -58; y != 58; ++y) 
				for (z = -58; z != 58; ++z)
					if (x != z && y != z && x != z
							&& a == x + y + z
							&& b == x * y * z
							&& c == x*x + y*y + z*z) {
							solution = true;
							printf("%d %d %d\n", x, y, z);
							goto endloop;
					}

endloop:

		if (!solution)
			printf("No soluton.\n");

	}

	return 0;
}
