#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>


using namespace std;

int main() {

	int n, l;
	cin >> n >> l;

	vector<int> lPos;
	for (int i = 0; i != n; ++i) {
		int lP;
		cin >> lP;
		lPos.push_back(lP);
	}

	sort(lPos.begin(), lPos.end());

	double maxRadius = abs(lPos[0]);

	for (int i = 1; i != n; ++i) {
		double nMinRadius = abs(lPos[i] - lPos[i-1]) / 2.0;
		maxRadius = max(maxRadius, nMinRadius); 
	}

	// Check if last covers end
	maxRadius = max(static_cast<double>(abs(lPos[n-1] - l)), maxRadius);
	printf("%.10f\n", maxRadius);

	return 0;
}
