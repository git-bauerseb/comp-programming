#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {

    public:
        int strStr(string haystack, string needle) {

            for (int idx = 0; idx < haystack.size(); ) {

                if (haystack[idx] == needle[0]) {
                    int match = 0;
                    int oIdx = idx;
                    while (idx < haystack.size()
                       && match < needle.size()
                       && haystack[idx] == needle[match]) {
                        idx++; match++;
                    }

                   if (match == needle.size()) return oIdx;
                   else idx = oIdx+1; 
                } else {
                    idx++;
                }
            }

            return -1;
        }
};
