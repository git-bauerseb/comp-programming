/**
 * // This is the MountainArray's API interface.
 * // You should not implement it, or speculate about its implementation
 * class MountainArray {
 *   public:
 *     int get(int index);
 *     int length();
 * };
 */

class Solution {
public:
    int findInMountainArray(int target, MountainArray &mA) {
        const int n = mA.length();

        // Value at peak
        int vPeak = -1;

        // Index at peak
        int iPeak = -1;

        // Find peak
        int left = -1;
        int right = n;

        while (right - left > 1) {
            int m = left + (right - left) / 2;
            
            int query = mA.get(m);
            bool q1 = m == 0 
                || (mA.get(m-1) < query);
            if (q1) {left = m; vPeak = query;}
            else {right = m;}
        }

        iPeak = (right-1);

        // Target in left part, so to normal binary search
        left = -1;
        right = iPeak;

        while (right - left > 1) {
            int m = left + (right - left) / 2;
            if (mA.get(m) < target) {left = m;}
            else {right = m;}
        }

        if (mA.get(right) == target) return right;

        left = iPeak-1;
        right = n;
        while (right - left > 1) {
            int m = left + (right - left) / 2;
            if (mA.get(m) > target) {left = m;}
            else {right = m;}
        }
        return (right < n && mA.get(right) == target) ? right : -1;
    }
};
