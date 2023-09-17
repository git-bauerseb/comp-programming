#include <iostream>
#include <map>

using namespace std;

/*
class Solution {
public:

    map<int,int> memo;

    int integerReplacement(int n) {

        for (int i = 0; i < 32 && (1 << i) < n; ++i) {
            memo[1 << i] = i;
        }

        return rec(n);
    }

    int rec(long long n) {
        if (memo.count(n) > 0) {return memo[n];}
        if (n == 1) {return 0;}

        if ((n & 1) == 0) {
            memo[n] = 1 + rec(n / 2);
        } else {
            memo[n] = 1 + min(rec(n+1), rec(n-1));
        }

        return memo[n];
    }
};
*/

class Solution2 {
    public:

        int fac(long long x){
            int factoftwo=0;
            while(x%2==0){
                factoftwo++;
                x/=2;
            }
            
            return factoftwo;
        }

        int integerReplacement(int n) {
            long long n_ = n;
            int op = 0;

            while (n_ != 1) {

                if (n_ == 3) {
                    op += 2;
                    break;
                }

                if ((n_ % 2) == 0) {
                    n_ /= 2;
                } else {
                    if (fac(n_ + 1) > fac(n_ - 1)) {n_ += 1;}
                    else {n_ -= 1;}
                }

                op++;
            }

            return op;
        }
};

int main() {
    Solution2 s{};
    cout << s.integerReplacement(13727384) << "\n";
    return 0;
}
