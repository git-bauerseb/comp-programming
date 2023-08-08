/*

   3, 4, -1, 1

   -1, 4, 3, 1
       
   -1, 1, 3, 4


   VERY IMPORTANT:
    When do swap, don't increment index

*/
class Solution {

    public:
        int firstMissingPositive(vector<int>& nums) {
            int v = 0;
            int idx = 1;
            for (auto& e : nums) {
                if (e > 0) {
                    v ^= e;
                }
                v ^= idx;
                ++idx;
            }
        }
};
