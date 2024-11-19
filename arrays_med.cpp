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

//-------------KADANE Algorithm-------------

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int sum=0;
        int temp=INT_MIN;
        for(auto it:nums)
        {
            sum+=it;
            temp=max(sum,temp);
            if(sum<0)sum=0;
    
        }
    return temp;
    }

};

	
//---Print subarray with maximum subarray sum (extended version of above problem)
class Solution {
  public:
    int pairWithMaxSum(vector<int> &nums) {
        int temp = INT_MIN;
        
     
        for (int i = 0; i < nums.size() - 1; i++) {
            int sum = nums[i] + nums[i + 1]; 
            
            if (sum > temp) {
                temp = sum;
            }
        }
        
        return temp;
    }
};

// Rearrange Array Elements by Sign

class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        int n=nums.size();
        int posIndex=0 , negIndex=1;
        vector <int> temp(n);
        for(int i=0;i<n;i++)
        {
            if(nums[i]>0)
            {
                temp[posIndex]=nums[i];
                posIndex+=2;
            }
            else
            {
                temp[negIndex]=nums[i];
                negIndex+=2;
            }
        }
        return temp;

    }
};

// next permutation

class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n=nums.size(),index=-1;
        for(int i=n-2;i>=0;i--)
        {
            if(nums[i]<nums[i+1])
            {
                index=i;
                break;
            }

        }
        if(index==-1)
        {
            reverse(nums.begin(),nums.end());
            return;
        }
        for(int i=n-1;i>=0;i--)
        {
            if(nums[i]>nums[index])
            {
                swap(nums[i],nums[index]);
                break;
            }
        }
        reverse(nums.begin()+index+1,nums.end());
    }
};
// -------------------longest consecutive sequence-----------

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int n=nums.size();
        if(n==0) return 0;
        sort(nums.begin(),nums.end());
        int last_smaller=INT_MIN;
        int longest=1,count=0;
        for(int i=0;i<n;i++)
        {
            if(nums[i]-1==last_smaller)
            {
                count+=1;
                last_smaller=nums[i];
            }
            else if(last_smaller!=nums[i])
            {
                count=1;
                last_smaller=nums[i];
            }
            longest=max(longest,count);
        }
        return longest ;
    }
};

// --------------------rotate a matrix by 90 
class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n=matrix.size();
        for(int i=0;i<n-1;i++)
        {
            for(int j=i+1;j<n;j++)
        {
            swap(matrix[i][j],matrix[j][i]);
            }
        }
        for(int i=0;i<n;i++)
        {
            reverse(matrix[i].begin(),matrix[i].end());
        }
    }
}
