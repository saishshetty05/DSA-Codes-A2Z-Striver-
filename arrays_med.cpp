/ --------------------Dutch Flag algorithm--------------------
//low: represents the rightmost boundary of 0s
// mid: current element being examined
// high: represents the leftmost boundary of 2s
// Three-Way Partitioning:

// All elements before low are 0s
// All elements after high are 2s
// All elements between low and mid are 1s


// How it Works:

// When we find 0: swap with low pointer element and increment both low and mid
// When we find 1: just increment mid
// When we find 2: swap with high pointer element and decrement high


// Time Complexity: O(n) where n is the size of array
// Space Complexity: O(1) as we're doing it in-place

//

class Solution {
public:
    void sortColors(vector<int>& nums) {
        int low =0 , mid=0,high= nums.size() - 1;
        while(mid<=high)
        {
            if(nums[mid]==0){
                        swap(nums[low],nums[mid]);
                        low++;
                        mid++;
                }
            else if(nums[mid]==1)
            {
                mid++;
            }
            else
            {
                swap(nums[mid],nums[high]);
                high--;
            }
        }

    }
};

//--------------find the number which appear once ---------------------

// brute force

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int arr = 0, count = 0;
       for(int i = 0; i < nums.size(); i++) {
            arr = nums[i];
            count = 0;
            for(int j = 0; j < nums.size(); j++) {
                if(arr == nums[j]) {
                    count++;
                }
            }
            if(count == 1) return arr;
        }
        
        return arr;
    }
};
//------------optimal approach-----------------
// number xor number is 0 so most of the element will cancel 
// number which remains is the one who has single apperance

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int xorr=0;
        for(int i=0;i<nums.size();i++)
        {
            xorr=xorr ^ nums[i];
        }
        return xorr;
    }
};
