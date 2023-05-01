#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;


int main() {

	while (true) {
		int N;
		cin >> N;

    	if (N == 0) break;

    	vector<pair<int,int>> img;
    	int minSpaces = 26;
    	for (int i = 0; i != N; ++i) {
		
			string s;
			cin >> s;

			int fLen = 0;
			while (fLen < s.length() && s[fLen] == 'X') fLen++;

			int spaces = 0;

			if (fLen != 25) {
				int idx = fLen;
				while (idx < s.length() && s[idx] == 'B') idx++;
				spaces = idx - fLen;				
				img.push_back({fLen, 25 - fLen - spaces});
				minSpaces = min(spaces, minSpaces);
			} else {
				img.push_back({25,0});
			}
		}




    	int totalRemaining = 0;
    	for (auto& p : img) {
			if (minSpaces > 25) {
				totalRemaining += 25 - (p.first + p.second);
			} else 
    			totalRemaining += (25 - (p.first + p.second)) - minSpaces;
    	}

    	cout << totalRemaining << "\n";
	}


	return 0;
}
