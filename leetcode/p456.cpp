#include <iostream>
#include <vector>
#include <stack>

using namespace std;

/*
class Solution {

    public:
        bool find132pattern(vector<int> nums) {
            const int n = nums.size();
            if (n < 3) {return false;}

            // Index of number that came previously and is smaller
            vector<int> pr(n,-1);

            // Monotonic Decreasing stack - Store indices
            // When inserting element, pop all elements <= current element 
            stack<int> ms;

            for (int i = 0; i < n; ++i) {
                while (ms.size() > 0) {
                    int top = nums[ms.top()];
                    if (top < nums[i]) {
                        if (pr[i] == -1) {
                            pr[i] = ms.top();
                        }
                        ms.pop();
                    } else {
                        if (top > nums[i] && pr[ms.top()] != -1
                                && nums[pr[ms.top()]] < nums[i]) {return true;}
                        break;
                    }
                }

                ms.push(i);
            }
            return false;
        }
};
*/

/*
class Solution {

    public:
        bool find132pattern(vector<int> nums) {
            const int n = nums.size();
            
            if (n < 3) {return false;}

            vector<int> ms;

            for (int i = 0; i < n; ++i) {

                // Do binary search
                if (ms.size() > 1) {
                    int idx = (int)(lower_bound(ms.begin(), ms.end(), nums[i]) - ms.begin());
                    if (idx < ms.size() && idx > 0 && ms[idx] > nums[i]) {return true;}
                }

                while (ms.size() > 0) {
                    if (ms[ms.size()-1] >= nums[i]) {ms.pop_back();}
                    else {break;}
                }

                ms.push_back(nums[i]);
            }

            return false;
        }
};
*/

class Solution {
    public:
        bool find132pattern(vector<int> nums) {
            const int n = nums.size();
            vector<int> mLeft(n, 1'000'000'001);

            for (int i = 1; i < n; ++i) {
                mLeft[i] = min(mLeft[i-1], nums[i-1]);
            }

            stack<int> ms;

            for (int i = n-1; i > 0; --i) {
                while (ms.size() > 0 && ms.top() <= nums[i]) {
                    if (ms.top() != nums[i] && ms.top() > mLeft[i]) {return true;}
                    ms.pop();
                }
                ms.push(nums[i]);
            }

            return false;
        }
};

int main() {
    vector<int> nums{-2,1,1};
    Solution solution{};
    bool f = solution.find132pattern(nums);
    cout << f << "\n";
    return 0;
}
