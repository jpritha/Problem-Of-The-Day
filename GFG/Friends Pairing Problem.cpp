// Link : https://practice.geeksforgeeks.org/problems/friends-pairing-problem5425/1

class Solution
{
public:
    int countFriendsPairings(int n) 
    { 
        long mod = 1e9+7;
        
        if(n == 1 || n == 2) return n;
        
        int cnt = 2;                   //since cnt is atleast 2 till n=2
        int prev = 1;                  //cnt = 1 for n=1, that is prev of n=2
        
        for(int i=3; i<=n; i++) {
            int temp = cnt;
            cnt = (cnt + (((i-1)%mod) * prev)%mod )%mod;
            prev = temp;
        }
        
        return cnt;
    }
};