// Link : https://practice.geeksforgeeks.org/problems/pots-of-gold-game/1

// Video : https://www.youtube.com/watch?v=3c41PK2xZFU&ab_channel=SagarMalhotra

/* C++ - DP + O(n^2) ------------------------------------------------------
Consider one status of list coins [i..j]: contain all coins from index i to j.
We have 4 cases occur:
1. X choose i --> List coins become [i + 1..j]
We have 2 cases for Y:
1.1. Y choose i + 1 --> List coins become [i + 2..j]
1.2. Y choose j --> List coins become [i + 1..j - 1]
Since Y plays optimally 
--> Y will choose such that the sum of coins X get is minimum.
--> sum_X_opt1([i..j]) = coins[i] + min(sum_coin_X([i + 2..j]), 
										sum_coin_X([i + 1..j - 1]))
2. X choose j --> List coins become [i..j - 1]
We have 2 cases for Y:
2.1. Y choose i --> List coins become [i + 1..j - 1]
2.2. Y choose j - 1 --> List coins become [i..j - 2]
--> sum_X_opt2([i..j]) = coins[j] + min(sum_coin_X([i + 1..j - 1]), 
										sum_coin_X([i..j - 2]))
In 2 choice for X, we choose the maximum coins for X
sum_coin_X([i..j]) = max(sum_X_opt1, sum_X_opt2)
*/

class Solution {
public:
    int solve(int l, int r, vector<int>& A, vector<vector<int>>& dp) {
        if(l == r) return A[l];
        
        if(l > r) return 0;
        
        if(dp[l][r] != -1) return dp[l][r];
        
        // X takes from Left 
                    //X   + min(next X)
        int X_left = A[l] + min(solve(l+2, r, A, dp), solve(l+1, r-1, A, dp));
        
        // X takes from Right
        int X_right = A[r] + min(solve(l+1, r-1, A, dp), solve(l, r-2, A, dp));
        
        return dp[l][r] = max(X_left , X_right);
    }
                    
    int maxCoins(vector<int>&A,int n)
    {
        vector<vector<int>> dp(n+1, vector<int>(n+1, -1));
        
	    return solve(0, n-1, A, dp);
    }
};


