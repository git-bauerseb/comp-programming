#include <vector>
#include <string>
#include <iostream>
#include <algorithm>


// C libraries
#include <cstring>

using namespace std;


/*
	- Keep track of borrowed books
    - If SHELF command input then output sorted list of currently borrowed	
*/

struct Record {
	string author;
	string title;
};

int main() {

	char line[192];

	vector<Record> records;

	while ((fgets(line, 192, stdin)) != NULL) {
		
		int len = strlen(line);
		line[len-1] = '\0';

		string s_line{line};

		// Line starts with "END"
		if (s_line.length() > 2 && !s_line.compare(0, 3, "END")) {
			break;
		} else {
			int idx = s_line.find("by");
			int author_start = idx+3;
			int author_length = s_line.length() - (author_start) + 1;

			string title{};
		   	string author{};

			if (idx > 3)
				title = s_line.substr(1, idx-3);
			
			
			if (author_length > 0)
				author = s_line.substr(author_start, author_length);

			records.push_back({author, title});
		}
	}

	sort(records.begin(), records.end(), [&](Record& a, Record& b) {
		int cmp = a.author.compare(b.author);
		if (!cmp) return a.title.compare(b.title);
		return cmp;		
	});

	for (auto& r : records) {
		cout << "Title: " << r.title << " Author: " << r.author << "\n";
	}
	
	vector<int> returned{};
	
	while (fgets(line, 192, stdin) != NULL) {
		int len = strlen(line);
		line[len-1] = '\0';

		string s_line{line};

		// End of requests
		if (s_line.length() > 2 && !s_line.compare(0, 3, "END")) {
		
			cout << "END\n";
			break;
		
		} else if (s_line.length() > 5 && !s_line.compare(0,6,"RETURN")) {

			int idx = s_line.find("\"");
			
			string title = s_line.substr(idx+1, s_line.length() - (idx+1) - 1);
			
			int index = lower_bound(records.begin(), records.end(), title, [](const Record& b, string a) {return a.compare(b.title);}) - records.begin();
			
			returned.push_back(index);

		} else if (s_line.length() > 5 && !s_line.compare(0, 6, "SHELVE")) {

			for (auto it = returned.begin(); it != returned.end(); it++) {
				if (*it == 0) {
					cout << "Put \"" << records[*it].title << "\" first\n";
				} else
					cout << "Put \"" << records[*it].title << "\" after \"" << records[*it-1].title << "\"\n";
			}
		}
	}




	return 0;
}
