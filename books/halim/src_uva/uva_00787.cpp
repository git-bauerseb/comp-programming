#include <iostream>
#include <algorithm>
#include <vector>
#include <set>

using namespace std;

// Constants
// Simple types
#define ll long long
#define ld long double

// Aggeragte types
#define pii pair<int,int>
#define pll pair<long,long>

#define vi vector<int>
#define vl vector<long>

#define si set<int>
#define sl set<long>

// Output
template <typename T>
void print_v(vector<T>& v) {cout << "{"; for (auto& x : v) cout << x << " "; cout << "\n";}

int maxProd(vector<int>& nums) {
    int max_ = nums[0];
    int cNeg = nums[0];
    int cPos = nums[0];
    for (int i = 1; i < nums.size(); ++i) {
        int oPos = cPos, oNeg = cNeg;
        cPos = max(max(nums[i], cPos * nums[i]), oNeg * nums[i]);
        cNeg = min(min(nums[i], cNeg * nums[i]), oPos * nums[i]);       
        max_ = max(max_, cPos);
    }
    return max_;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
    vector<int> numbers;
    int num;
    while (scanf("%d", &num) != EOF) {
        if (num == -999999) {
            cout << maxProd(numbers) << "\n";
            numbers.clear();
            continue;
        }
        numbers.push_back(num);
    }    

	return 0;
}
