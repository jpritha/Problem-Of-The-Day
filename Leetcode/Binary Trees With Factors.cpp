// Link : https://leetcode.com/problems/binary-trees-with-factors/

// Video : https://www.youtube.com/watch?v=KdX1K2StIsA&ab_channel=CodeFreaks

class Solution {
public:

    int numFactoredBinaryTrees(vector<int>& A) {
        long long res = 0, mod = pow(10, 9) + 7;
        sort(A.begin(), A.end());
        unordered_map<long long, long long> dp;
        for (int i = 0; i < A.size(); ++i) {
            dp[A[i]] = 1;
            for (int j = 0; j < i; ++j)
                if (A[i] % A[j] == 0) {
                    dp[A[i]] = (dp[A[i]] + dp[A[j]] * dp[A[i] / A[j]]) % mod;
                                       //  dp[num1] * dp[num2]  
                }
            res = (res + dp[A[i]]) % mod;
        }
        return res;
    }
};


/*    8
    4   2        
        
    dp[8] = dp[8] + dp[4]*dp[2]
                    should be multiplication of the no. of BTs possible in both
*/