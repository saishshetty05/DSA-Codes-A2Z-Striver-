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
int upperBound(vector<int>& arr, int n, int x) {
        int low = 0, high = n - 1;
        int ans = n;
        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (arr[mid] > x) {
                ans = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        return ans;
    }


//-------------------------------lower bound ------------------------------
int lowerBound(vector<int>& arr, int n, int x) {
        int low = 0, high = n - 1;
        int ans = n;
        while (low <= high) {
            int mid = low + (high - low) / 2;  // to avoid overflow
            if (arr[mid] >= x) {
                ans = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        return ans;
    }

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

// ------------------------------ Search Insert Position---------------


class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int n =nums.size();
        int low = 0, high = n - 1;
      
        
        while (low <= high) {
            int mid = (low+high)/2;

            if(nums[mid]==target){return mid;}
            
            else if (nums[mid] < target) {
                                low = mid + 1; 
            } else {
                high = mid - 1;  
            }
        }
        
        return low;
    }
};

// --------------------------find the first and last occurence of the element and 
// --------------------------return index of it using binary search

class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int n = nums.size();
        int lb = lowerBound(nums, n, target);        
        if (lb == n || nums[lb] != target) {
            return {-1, -1};
        }
        return {lb,  upperBound(nums, n, target) - 1};
    }
    int lowerBound(vector<int>& arr, int n, int x) {
        int low = 0, high = n - 1;
        int ans = n;
        while (low <= high) {
            int mid = low + (high - low) / 2;  // to avoid overflow
            if (arr[mid] >= x) {
                ans = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        return ans;
    }

    // Find the position just after the last occurrence of target
    int upperBound(vector<int>& arr, int n, int x) {
        int low = 0, high = n - 1;
        int ans = n;
        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (arr[mid] > x) {
                ans = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        return ans;
    }
};
//---------------------Count occurrences of a number in a sorted array with duplicates

class Solution {
public:
    int count(int arr[], int n, int x) {
        int lw = lowerBound(arr, n, x);
        int hw = upperBound(arr, n, x);
        
        if (lw == n || arr[lw] != x) return 0;
        return hw - lw;
    }
    
    int lowerBound(int arr[], int n, int x) {
        int low = 0, high = n - 1, ans = n;
        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (arr[mid] >= x) {
                ans = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        return ans;
    }
    
    int upperBound(int arr[], int n, int x) {
        int low = 0, high = n - 1, ans = n;
        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (arr[mid] > x) {
                ans = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        return ans;
    }
};






//------------------ 	Search in Rotated Sorted Array I (unique elements)------/

class Solution {
public:
    int search(vector<int>& nums, int target) {
        int low = 0, high = nums.size()- 1;
        
        while (low <= high) {
            int mid = low + (high - low) / 2;
            
            if (nums[mid] == target) {
                return mid;
            }
            
            // Left half is sorted
            if (nums[low] <= nums[mid]) {
                if (nums[low] <= target && target < nums[mid]) {
                    high = mid - 1;
                } else {
                    low = mid + 1;
                }
            } 
            // Right half is sorted
            else {
                if (nums[mid] < target && target <= nums[high]) {
                    low = mid + 1;
                } else {
                    high = mid - 1;
                }
            }
        }
        
        return -1;
    }
};


///------------------Search in Rotated Sorted Array 2(duplicate elements)------/
class Solution {
public:
    bool search(vector<int>& nums, int target) {
        int low = 0, high = nums.size()- 1;
        
        while (low <= high) {
            int mid = low + (high - low) / 2;
            
            if (nums[mid] == target) {
                return true;
            }
            if(nums[low]==nums[mid] && nums[mid]==nums[high])
            {
                low=low+1;
                high=high-1;
                continue;
            }
            
            // Left half is sorted
            if (nums[low] <= nums[mid]) {
                if (nums[low] <= target && target < nums[mid]) {
                    high = mid - 1;
                } else {
                    low = mid + 1;
                }
            } 
            // Right half is sorted
            else {
                if (nums[mid] < target && target <= nums[high]) {
                    low = mid + 1;
                } else {
                    high = mid - 1;
                }
            }
        }
        
        return false;}
    
};

//---------------------searching of element in sorted array()-------
//---------------------using n*logn approach----------- 

class Solution {
public:
    int singleNonDuplicate(vector<int>& arr) {
        int n=arr.size();
        if(n==1) return arr[0];
        if(arr[0]!=arr[1]) return arr[0];
        if(arr[n-1]!=arr[n-2]) return arr[n-1];
        int low=1,high=n-2;
        while(low<=high)
        {
            int mid=(low+high)/2;
            if(arr[mid]!=arr[mid-1] && arr[mid]!=arr[mid+1])
            {
                return arr[mid];
            }
            if((mid %2 ==1 && arr[mid]==arr[mid-1])|| (mid%2==0 && arr[mid]==arr[mid+1])){
                low=mid+1;
            }
            else
            {
                high=mid-1;
            }
        }
        return -1;
    }
};