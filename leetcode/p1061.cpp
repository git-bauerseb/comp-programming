#include <iostream>
#include <vector>
#include <string>
#include <cstring>

using namespace std;

const int N_MAX = 100;

int dsu[N_MAX+1];
int d_size[N_MAX+1];

void make_set(int v) {d_size[v] = 1; dsu[v] = v;}

int find_set(int v) {
    if (v == dsu[v]) return v;
    return dsu[v] = find_set(dsu[v]);
}

void union_sets(int a, int b) {
    a = dsu[a];
    b = dsu[b];
    if (a != b) {
        if (d_size[b] > d_size[a])
            swap(a,b);
        dsu[b] = a;
    }
}

class Solution {

    public:
        string smallestEquivalentString(string s1, string s2, string baseStr) {
            memset(dsu, 0, sizeof(dsu));
            memset(d_size, 0, sizeof(d_size));

            bool used[27];
            memset(used, false, sizeof(used));

            for (int i = 0; i < s1.size(); ++i) {
                make_set(s1[i] - 'a');
                make_set(s2[i] - 'a');
                used[s1[i]-'a'] = true;
                used[s2[i]-'a'] = true;
            }

            for (int i = 0; i < s1.size(); ++i) {
                int r1 = find_set(s1[i] - 'a');
                int r2 = find_set(s2[i] - 'a');
                union_sets(r1, r2);
            }

            string output;

            for (int i = 0; i < baseStr.size(); ++i) {
                int ref = baseStr[i] - 'a';
                if (!used[ref]) { output += static_cast<char>(ref + 'a'); continue;}
                int set1 = find_set(ref);
                for (int ch = 0; ch <= ref; ++ch) {
                    if (used[ch] && find_set(ch) == set1) {
                        output += static_cast<char>(ch + 'a');
                        break;
                    }
                }
            }
            return output;
        }
};

int main() {

    Solution solution{};
    string o = solution.smallestEquivalentString("hello", "world", "hold");
    cout << o << "\n";
    return 0;
}
