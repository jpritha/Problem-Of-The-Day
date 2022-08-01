/* Link : https://practice.geeksforgeeks.org/problems/egg-dropping-puzzle-1587115620/1
          https://www.youtube.com/watch?v=QB7JvntZZIo&ab_channel=SagarMalhotra
          https://www.youtube.com/watch?v=o_AJ3VWQMzA&ab_channel=GauravSen                */

// GFG Editorial : 

class Solution
{
    public:
    int dfs(int eggs, int k, vector<vector<int>>& dp) {
        if(eggs == 1) return k;
        
        if(k == 0 || k == 1) {
            return k;
        }
        //int ans = 1e9;
        if(dp[eggs][k] != 1e9) return dp[eggs][k];
        
        for(int i=1; i<=k; i++) {
            //Egg Break
            int op1 = 1 + dfs(eggs-1, i-1, dp);
            // //Egg Not Break
            int op2 = 1 + dfs(eggs, k-i, dp);
            
            // temp stores minimum moves to find thresold floor in worst case
            int temp = max(op1, op2);
            
            // we have to minimize the maximum answer
            dp[eggs][k] = min(dp[eggs][k], temp);
        }
        return dp[eggs][k];
    }
    //Function to find minimum number of attempts needed in 
    //order to find the critical floor.
    int eggDrop(int n, int k) 
    {
        vector<vector<int>> dp(n+1, vector<int>(k+1, 1e9));
        
        return dfs(n, k, dp);
    }
};