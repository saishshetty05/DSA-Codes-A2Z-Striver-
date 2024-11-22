arrays// /=----------------------Longest subarray with given sum K(positives)'

explanation

3. **Case 2: Finding subarray with sum = k using map**:
```cpp
int rem = sum - k;  // Calculate remainder
if(mpp.find(rem) != mpp.end()) {  // If remainder exists in map
    int len = i - mpp[rem];        // Calculate length
    maxlen = max(maxlen, len);     // Update maxlen if necessary
}
```
Let's understand this with an example:
```
arr = [1, 2, 3, -3, 1, 1, 1, 4, 2, -3], k = 3

i = 2:
sum = 6 (1+2+3)
rem = 6-3 = 3
if 3 exists in map...

i = 3:
sum = 3 (1+2+3-3)
rem = 3-3 = 0
maxlen = 4 (subarray [1,2,3,-3])
```

4. **Storing sum in map**:
```cpp
if(mpp.find(sum) == mpp.end()) {  // If sum not in map
    mpp[sum] = i;                  // Store sum with current index
}
```

Complete Example:
```
arr = [10, 5, 2, 7, 1, 9], k = 15

Step by step:
i = 0: 
- sum = 10
- mpp[10] = 0

i = 1:
- sum = 15
- maxlen = 2 (sum equals k)
- mpp[15] = 1

i = 2:
- sum = 17
- mpp[17] = 2

i = 3:
- sum = 24
- rem = 24-15 = 9
- mpp[24] = 3

i = 4:
- sum = 25
- rem = 25-15 = 10
- len = 4-0 = 4 (found subarray [5,2,7,1])
- maxlen = 4
- mpp[25] = 4

i = 5:
- sum = 34
- mpp[34] = 5

Final maxlen = 4 (subarray [5,2,7,1])
```

Key Points:
1. The map stores prefix sums and their indices
2. We use `rem = sum - k` to find if there exists a prefix sum that we can subtract to get k
3. We only store the first occurrence of a sum (that's why we check if sum exists before storing)
4. maxlen is updated in two cases:
   - When current sum equals k (prefix case)
   - When we find a valid subarray using the map


// code

class Solution {
  public:
    int lenOfLongestSubarr(vector<int>& arr, int k) {
        // code here
        int maxlen=0;
        int sum=0;
        map<long long,int >mpp;
        for(int i=0;i<arr.size();i++)
        {
            sum+=arr[i];
            if(sum==k){
                maxlen=max(maxlen,i+1);
                
            }
            int rem=sum-k;
            if(mpp.find(rem)!=mpp.end()){
                int len=i-mpp[rem];
                maxlen=max(maxlen,len);
            }
            if(mpp.find(sum)==mpp.end())
            {
                mpp[sum]=i;
            }
        }
        return maxlen;
    }
};
//--------------------------optimal approach
class Solution {
public:
    int lenOfLongestSubarr(vector<int>& arr, int k) {
      
        int i=0,j=0;
        long long sum=arr[0];
        int length=0;
        int n=arr.size();
        while(j<n){
            while(i<=j && sum>k){
                sum-=arr[i];
                i++;           
            }
            if(sum==k){
                length=max(length,j-i+1);
            }
            j++;
            if(j<n)          
                sum+=arr[j];
        }
        return length;
        
    }
};