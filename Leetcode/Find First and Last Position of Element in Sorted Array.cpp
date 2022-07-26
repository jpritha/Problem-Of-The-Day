// Link : https://leetcode.com/problems/find-first-and-last-position-of-element-in-sorted-array/

class Solution {
public:
    int firstOccurance(vector<int>& nums, int target) {
        int low = 0, high = nums.size()-1;
        int ans = -1;
        
        while(low <= high) {
            int mid = low + (high - low)/2;
            
            if(nums[mid] == target) {
                ans = mid;
                high = mid - 1;     //Look on the left side now
            }
            else if(nums[mid] < target) {
                low = mid + 1;
            }
            else {
                high = mid - 1;
            }
        }
        return ans;
    }
    int lastOccurance(vector<int>& nums, int target) {
        int low = 0, high = nums.size()-1;
        int ans = -1;
        
        while(low <= high) {
            int mid = low + (high - low)/2;
            
            if(nums[mid] == target) {
                ans = mid;
                low = mid + 1;      //Look on the right side now
            }
            else if(nums[mid] < target) {
                low = mid + 1;
            }
            else {
                high = mid - 1;
            }
        }
        return ans;
    }
    
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> res;
        
        res.push_back(firstOccurance(nums, target));
        res.push_back(lastOccurance(nums, target));
        return res;
    }
};
