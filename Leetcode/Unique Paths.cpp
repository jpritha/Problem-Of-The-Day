// Link : https://leetcode.com/problems/unique-paths/    
            
            //TOP DOWN 

class Solution {
public:
    int solve(int i, int j, int m, int n, vector<vector<int>>& dp) {
        if(i==m-1 && j==n-1) {
            return 1;          //We have reached using 1 path
        }
        if(i<0 || i>=m || j<0 || j>=n) return 0;
        
        if(dp[i][j] != -1) return dp[i][j];
        
        int down = solve(i+1, j, m, n, dp);
        int right = solve(i, j+1, m, n, dp);
        
        return dp[i][j] = down + right;
    }
    int uniquePaths(int m, int n) {
        
        vector<vector<int>> dp(m+1, vector<int>(n+1, -1));
       
        return solve(0, 0, m, n, dp);
    }
};



                 //      BOTTOM-UP        //

class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(m+1 , vector<int>(n+1, 1) );
        
        dp[0][0] = 1;          // we start from (1,1)
        
        
        for(int i=1; i<m; i++){
            for(int j=1; j<n; j++){
                
                dp[i][j] = dp[i-1][j] + dp[i][j-1];          //dp[2][2] = dp[1][2] + dp[2][1]
            }
        }
        return dp[m-1][n-1];
    }
};

//dp[2][2] = dp[1][2] + dp[2][1]
//dp[1][2] = dp[0][2] + dp[1][1] = 0 + 1 = 1



                            // OR 
// class Solution {
// public:
//     int uniquePaths(int m, int n) {
//         vector<vector<int>> dp(m+1 , vector<int>(n+1, 1) );
        
//         dp[1][1] = 1;          // we start from (1,1)
        
        
//         for(int i=2; i<=m; i++){
//             for(int j=2; j<=n; j++){
                
//                 dp[i][j] = dp[i-1][j] + dp[i][j-1];        //dp[2][2] = dp[1][2] + dp[2][1]
//             }
//         }
//         return dp[m][n];
//     }
// };
