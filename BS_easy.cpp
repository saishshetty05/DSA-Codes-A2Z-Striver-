// ---binary search 

class Solution {
public:
    int search(vector<int>& nums, int target) {
        int left = 0;
        int right = nums.size() - 1;
        
        while (left <= right) {
            int mid = left + (right - left) / 2;
            
            if (nums[mid] == target) {
                return mid;
            } else if (nums[mid] < target) {
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }
        
        return -1;
    }
};

// -----------------upper bound------------




class Solution {
public:
    // Function to find floor of x
    // n: size of vector
    // x: element whose floor is to find
    int findFloor(vector<long long> &v, long long n, long long x) {
        int low = 0, high = n - 1;
        int floor = -1;
        
        while (low <= high) {
            int mid = low + (high - low) / 2;
            
            if (v[mid] <= x) {
                floor = mid;
                low = mid + 1;  // Look for a potentially larger floor value
            } else {
                high = mid - 1;  // Look in the lower half
            }
        }
        
        return floor;
    }
};

// -------------------------------upper bound and lower bound-------------------




class Solution {
public:
    // Function to find floor of x
    // n: size of vector
    // x: element whose floor is to find
    int findFloor(vector<long long> &v, long long n, long long x) {
        int low = 0, high = n - 1;
        int floor = -1;
        
        while (low <= high) {
            int mid = low + (high - low) / 2;
            
            if (v[mid] <= x) {
                floor = mid;
                low = mid + 1;  // Look for a potentially larger floor value
            } else {
                high = mid - 1;  // Look in the lower half
            }
        }
        
        return floor;
    }
};

