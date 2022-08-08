// Link : https://leetcode.com/problems/longest-increasing-subsequence/

class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        
        vector<int> lis(n+1, 1);
        
        for(int i=1; i<n; i++) {
            for(int j=0; j<i; j++) {
                if(nums[i] > nums[j]) {
                    lis[i] = max(lis[i] , lis[j]+1);            //update length of the subsequence
                }
            }
        }
        
        int ans = *max_element(lis.begin(), lis.end());
        return ans;
    }
};