// Link : https://practice.geeksforgeeks.org/problems/smallest-sum-contiguous-subarray/1

class Solution{
    public:
    int smallestSumSubarray(vector<int>& a){
        int ans = a[0];
        int minimum = a[0];
      
        for(int i=1; i<a.size(); i++) {
            minimum = min(a[i] , minimum+a[i]);
            ans = min(ans, minimum);
        }
        return ans;
    }
};

/* -----------------------------------------------------------------------------------------------
                        JUST LIKE KADANE's Algo : MaxSUM SUBARRAY
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int currsum = 0, maxsum = INT_MIN;
        
        for(int i=0; i<nums.size(); i++) {
            
            currsum = max(currsum+nums[i] , nums[i]);
            
            maxsum = max(maxsum , currsum);
        }
        return maxsum;
    }
};
*/