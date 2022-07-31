// Link : https://leetcode.com/problems/minimum-operations-to-make-the-array-increasing/

class Solution {
public:
    int minOperations(vector<int>& nums) {
        int cnt = 0;
        
        if(nums.size() == 1) return 0;
        
        for(int i=1; i<nums.size(); i++) {
            if(nums[i] > nums[i-1]) continue;
            else {
                int to_be = nums[i-1] + 1;
                cnt += to_be - nums[i];
                nums[i] = to_be;
            }
        }
        return cnt;
    }
};