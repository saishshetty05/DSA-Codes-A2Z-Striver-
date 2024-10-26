//------------ Sqaure root of number------------------

class Solution {
public:
    long long int floorSqrt(long long int x) {
        // Edge case
        if (x == 0) return 0;
        
        long long int low = 1;
        long long int high = x;
        long long int ans = 1;
        
        while (low <= high) {
            long long int mid = low + (high - low) / 2;
            
            if (mid <= x / mid) {  
                ans = mid;
                low = mid + 1;
            }
            else {
                high = mid - 1;
            }
        }
        
        return ans;
    }
};