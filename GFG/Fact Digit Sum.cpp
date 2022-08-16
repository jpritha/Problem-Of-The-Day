// Link : https://practice.geeksforgeeks.org/problems/fact-digit-sum4125/1
// Video : https://www.youtube.com/watch?v=kSITU3PZomo&ab_channel=SagarMalhotra


class Solution{
	public:
	vector<int> FactDigit(int N)
	{
	    vector<int> ans;
	    
	    vector<int> dp(9, 1);          //0! = 1,  1! = 1
	    
	    for(int i=2; i<=9; i++) {
	        dp[i] = dp[i-1] * i;
	    }    
        
        for(int i=9; i>=1; i--) {
            if(dp[i] <= N) {
                N -= dp[i];
                ans.push_back(i);
                i++;                //for test case when n=4 
            }
        }
        
        reverse(ans.begin(), ans.end());
	    return ans;
	}
};