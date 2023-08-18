class Solution {
public:
    int longestString(int x, int y, int z) {

        int l = 6 * min(x, min(y,z));
        
        // Limiting factor was 'AA'
        if (min(x, min(y,z)) == x) {
            if (y - x > 0) {
                l += 2;
                l += 2 * max(0, z - (l-2)/6);
            } else {
                l += 2 * max(0, z - l/6);
            }
        // Limiting factor was 'BB'
        } else if (min(x, min(y,z)) == y) {    
            int added = 0;        
            if (x > min(x, min(y,z))) {l += 2; added++;}
            if (z > min(x, min(y,z))) {l += 2; added++; z--;}
            l += 2 * max(0, z - (l-added)/6);
        // Limiting factor was 'AB'
        } else if (min(x, min(y,z)) == z) {
            l += 4 * max(0, min(x - l/6 , y - l/6));
            if (x > y || y > x) l += 2;
        }

        return l;
    }
};
