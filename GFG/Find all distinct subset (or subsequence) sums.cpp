// Link : https://practice.geeksforgeeks.org/problems/find-all-distinct-subset-or-subsequence-sums4424/1

class Solution {
public:
    void solve(int ind, int sum, vector<int>& nums, set<int>& s, vector<vector<bool>>& dp) {
        if(ind >= nums.size()) {
            s.insert(sum);
            return;
        }
        
        if(dp[ind][sum] == true) return;      //Avoid duplicate
        
        //Not Pick 
        solve(ind+1, sum, nums, s, dp);
        //Pick
        solve(ind+1, sum+nums[ind], nums, s, dp);
        
        dp[ind][sum] = true;
    }
    
    //Main Function
	vector<int> DistinctSum(vector<int>nums)
	{
	    vector<int> ans;
	    set<int> s;
	    
	    vector<vector<bool>> dp(nums.size()+1, vector<bool>(10001, false));
	    //vector<int>dp;
	    
	    int sum = 0;
	    solve(0, sum, nums, s, dp);
	    
	    for(auto& it : s) {
	        ans.push_back(it);
	    }
	  
	    return ans;
	}
};

/*-------------------------------------------------------------------------------------------  
                        ADITYA VERMA (SUBSET SUM PROBLEM) APPROACH
class Solution {
public:
    vector<int> DistinctSum(vector<int>nums) 
    {
        int n = nums.size();
        
        int sum = accumulate(nums.begin(), nums.end(), 0);
        
        vector<vector<bool>> dp(n+1, vector<bool>(sum+1, false));
        
        for(int i=0; i<n+1; i++) {              //ind (size of nums array)
            for(int j=0; j<sum+1; j++) {        //sum for tht ind
            
                if(i == 0) {                //empty array
                    dp[i][j] = false;       //canot contain sum when no elements in array
                }
                if(j == 0) {                //Zero Sum
                    dp[i][j] = true;        //Zero sum is possible with any number of elements
                }
            }
        }
        
        for(int i=1; i<n+1; i++) {
            for(int j=1; j<sum+1; j++) {
                
                if(nums[i-1] <= j) {
                    dp[i][j] = dp[i-1][j-nums[i-1]] || dp[i-1][j];
                }
                else {
                    dp[i][j] = dp[i-1][j];
                }
            }
        }
        
        vector<int>ans;
	    for(int i=0;i<=sum;i++)
	    {
	        if(dp[n][i]==true)
	        {
	            ans.push_back(i);
	        }
	    }
	    return ans;
    }
}

// Link : https://www.youtube.com/watch?v=_gPcYovP7wc&ab_channel=AdityaVerma
*/