#include <set>
#include <vector>
#include <string>
#include <iostream>
#include <algorithm>


// C libraries
#include <cstring>

#include <cstdio>

using namespace std;


/*
	- Keep track of borrowed books
    - If SHELF command input then output sorted list of currently borrowed	
*/

struct Record {
	string author;
	string title;
};

bool compareRecord(const Record& a, const Record& b) {

	if (a.author != b.author)
		return a.author < b.author;

	return a.title < b.title;
}

int main() {

	char line[192];

	vector<Record> records;

	while (fgets(line, 192, stdin) != NULL) {
		int line_len = strlen(line);
		line[line_len-1] = '\0';
		
		string s{line};

		if (!s.compare(0, 3, "END")) break;
		else {
			int idx = s.find("\" ");
			string title = s.substr(1, idx-1);

			int author_len = s.size() - (idx+5);
			if (author_len > 0) {
				string author = s.substr(idx+5, author_len);

				Record r;
				r.author = author;
				r.title = title;
				records.push_back(r);
			}
		}
	}


	// Sort records
	sort(records.begin(), records.end(), compareRecord);

	set<int> borrowed;
	set<int> returned;

	while (fgets(line, 192, stdin) != NULL) {
		int line_len = strlen(line);
		line[line_len-1] = '\0';

		string s_line{line};

		if (!s_line.compare(0, 3, "END")) break;
		else if (s_line[0] == 'S') {

			for (auto& e : returned) {
			
				int pred = e-1;
				while (pred >= 0 
						&& (borrowed.count(pred) > 0)) pred--;

				if (pred < 0)
					cout << "Put \"" << records[e].title << "\" first\n";
				else
					cout << "Put \"" << records[e].title 
						 << "\" after \"" << records[pred].title << "\"\n";
			}
			cout << "END\n";
			returned.clear();
		} else {
		
			int idx = s_line.find("\"");
			string title = s_line.substr(idx+1, s_line.length() - idx - 2);

			int r_idx = 0;

			// Find title in records
			for (int i = 0; i < records.size(); i++) {
				if (records[i].title == title) {
					r_idx = i;
					break;
				}
			}

			// Borrow
			if (s_line[0] == 'B') {
				borrowed.insert(r_idx);
			// Return
			} else {
				borrowed.erase(r_idx);
				returned.insert(r_idx);
			}
		}
	}


	return 0;
}
