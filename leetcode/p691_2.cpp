#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <bitset>
#include <cstring>

using namespace std;

class Solution {
    public:
        map<string,int> memo;

        int minStickers(vector<string>& stickers, string target) {
            const int n = stickers.size();
            const int m = target.size();
            vector<string> nStickers;

            // Remove all unnecessary characters from stickers
            for (auto& e : stickers) {
                string nSticker;
                for (auto& c : e) {
                    bool occ = false;

                    for (auto& tc : target) { if (tc == c) {occ = true; break;} }
                    if (occ) { nSticker += c; }
                }

                nStickers.push_back(nSticker);
            }


            int result = rec(nStickers, target, 0);
            return result == 1'000'000 ? -1 : result;
        }

        int rec(vector<string>& stickers, string rem, int u__) {
            if (rem.size() < 1) {return u__;}
            
            if (memo.count(rem) > 0) {
                return memo[rem];
            }
            

            int minimum = 1'000'000;

            // Iterate over each sticker
            for (auto& st : stickers) {
                bitset<16> used;
                string newS;
                bool stickerUsed = false;
                for (int i = 0; i < rem.size(); ++i) {
                    bool charRemains = true;

                    for (int j = 0; j < st.size(); ++j) {
                        if (!used[j] && st[j] == rem[i]) {charRemains = false; stickerUsed = true; used[j] = 1; break;}
                    }

                    if (charRemains) {newS += rem[i];}
                }                    

                if (stickerUsed) {
                    memo[newS] = rec(stickers, newS, u__);
                    minimum = 1 + min(minimum, memo[newS]);
                }
            }

            return minimum;
        }
};

int main() {

    vector<string> st{"with", "example", "science", "helloworld"};

    Solution solution{};
    int n = solution.minStickers(st, "woooalll");
    cout << n << "\n";

    return 0;
}
