// find the largest number

// User function Template for C++
#include<bits/stdc++.h>
class Solution {
public:
    int largest(vector<int>& arr) {
        int n = arr.size();
        int largest = arr[0]; // Initialize largest to the first element

        for (int i = 1; i < n; i++) {
            if (arr[i] > largest) {
                largest = arr[i];
            }
        }

        return largest;
    }
};;


//Remove Duplicates from Sorted Array 
// return i element

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int i=0;
        for(int j=1;j<nums.size();j++)
        {
            if(nums[i]!=nums[j])
            {
                nums[i+1]=nums[j];
                i++;
            }
        }return i+1;
    }
};



//linear search
class Solution {
  public:
    // Function to find element in sorted array
    // arr: input array
    // N: size of array
    // K: element to be searched
    int searchInSorted(int arr[], int N, int K) {

        for(int i=0;i<N;i++)
        {
            if(arr[i]==K) return 1;
            
        }  return -1;
    }
};

// ------------- rotate array by d spaces-----


        // brute force 
        // step 1 ; find d(number of rotation)(d=d%n) n is the size of array
        // step 2 : store rotated array elements in another variable
            //     step 3: run loop from d-1 elements till n such that element are shifted by 
            //             d spaces 
            //     step 4: add temp to end of the array

            // //
        class Solution {
        public:
            void rotate(vector<int>& nums, int k) {
                int n = nums.size(); 
                k = k % n; 
                vector<int> temp(nums.end() - k, nums.end());  
                
                // Shift the first n-k elements to the right
                for(int i = n - 1; i >= k; i--) {
                    nums[i] = nums[i - k];
                }
                
                // Place the stored k elements at the start
                for(int i = 0; i < k; i++) {
                    nums[i] = temp[i];
                }
            }
        };


        // optimal approach
        class Solution {
        public:
            void rotate(vector<int>& nums, int k) {
                int n=nums.size();
                k=k%n;
                k=k%nums.size();
                reverse(nums.begin(),nums.begin()+(nums.size()-k)); // from arr[] to arr + d  d is the rotation 

                reverse(nums.begin()+(nums.size()-k),nums.end());  //from arr[d] to arr[n] last part of array
            
                reverse(nums.begin(),nums.end()); // from start of arr to end of the array 
                }
        };

// ---------------------------union of two arrays---------------------


class Solution{
    public:
    vector<int> findUnion(int arr1[], int arr2[], int n, int m)
    {
        //Your code here
        //return vector with correct order of elements
        int i=0,j=0;
        vector<int> arr;
        
        while(i<n && j<m)
        {
            if(arr1[i]<=arr2[j])
            {
                if(arr.size()==0 || arr.back()!=arr1[i]) 
                {
                    arr.push_back(arr1[i]);
                }
                i++;
            }
            else
            {
                if(arr.size()==0 || arr.back()!=arr2[j]) 
                {
                    arr.push_back(arr2[j]);
                }
                j++;
            }
        }
        while(j<m)
        {
            if(arr.size()==0 || arr.back()!=arr2[j]) 
                {
                    arr.push_back(arr2[j]);
                }
                j++;
        }
        while(i<n)
        {
         if(arr.size()==0 || arr.back()!=arr1[i]) 
                {
                    arr.push_back(arr1[i]);
                }
                i++;   
        }
    }
};
//-------------------------move zeros to end-------------------

class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int   n=nums.size(),temp=0,j=0;
        for(int i =0;i<n;i++)
        {
            if(nums[i]==0)
            {
              i=j;
              break;
            }
        }
        
        for(int i=0;i<n;i++)
        {
            if(nums[i]!=0)
            {
                swap(nums[i],nums[j]);
                j++;
            }
        }
      
    }
};
//-----------missing number----------------

// ----------better approach
class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n=nums.size();
         vector<int> hash(n + 1, 0);
        for(int i=0;i<n;i++)
        {
            hash[nums[i]]=1;
        }
        for(int i=0;i<=n;i++)
        {
            if(hash[i]==0) return i;
        }
        return -1;
    }
};


//---------optimal approach----------------
class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int N = nums.size();    
        int XOR1 = 0, XOR2 = 0;
        for (int i = 0; i < N; i++) {
            XOR1 ^= nums[i];     
            XOR2 ^= i;           
        }
        XOR2 ^= N;
        return XOR1 ^ XOR2;
    }
};



//////-------------------- find max consecutive 1----------------

class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int temp=0;
        int count=0;
        for(int i=0;i<nums.size();i++)
        {
            if(nums[i]==1)
            {
                count++;
                temp=max(temp,count);
            }
            else
            {
                count=0;
            }
        }
        return temp;
    }
};
//---------------------	
// -----------------------Stock Buy and Sell

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int mini = INT_MAX; 
        int profit = 0;     
        for (int i = 0; i < prices.size(); i++) {
            mini = min(mini, prices[i]);
          int cost = prices[i] - mini;
            profit = max(profit, cost);
        }
        
        return profit;
    }
};

//---------------	
// ---------------------Majority Element (>n/2 times)

class Solution {
public:
    int majorityElement(vector<int>& arr) {
      int element;
      int count=0;
      for(int i=0;i<arr.size();i++)
      {
        if(count==0)
        {
            element=arr[i];
            count++;
        }
        else if (arr[i]==element)
        {
            count++;
        }
        else
        {
            count--;
        }
      }
      int x=0;
      for(int i=0;i<arr.size();i++)
      {
        if(arr[i]==element) x++;
      }
      if(x>(arr.size()/2))
      {
        return element;
      }
    return 0;
    }
};

// Leaders in array

#include<bits/stdc++.h>
class Solution {
    // Function to find the leaders in the array.
  public:
    vector<int> leaders(vector<int>& arr) {
        // Code here
        vector<int>temp;
        int n=arr.size();
        int max=arr[n-1];
        temp.push_back(arr[n-1]);
        
        for(int i=n-2;i>=0;i--)
        {
            if(arr[i]>=max)
            {
                temp.push_back(arr[i]);
                max=arr[i];
            }
        }
        reverse(temp.begin(),temp.end());
        return temp;
        
    }
};