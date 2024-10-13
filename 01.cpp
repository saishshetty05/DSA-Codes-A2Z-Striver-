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