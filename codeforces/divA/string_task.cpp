#include <iostream>
#include <string>
#include <cctype>
#include <algorithm>
#include <vector>

using namespace std;

int main() {

	vector<char> vowels{'A','E', 'I', 'O', 'U', 'Y'};

	string s;
	cin >> s;

	string r1;

	for (char c : s) {
		if (!binary_search(vowels.begin(), vowels.end(), toupper(c))) {
			r1.push_back(tolower(c));
		}
	}

	string result;
	for (char c : r1) {
		result.push_back('.');
		result.push_back(c);
	}

	cout << result << "\n";
	

	return 0;
}
