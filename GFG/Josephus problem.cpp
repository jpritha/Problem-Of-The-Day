// Link : https://practice.geeksforgeeks.org/problems/josephus-problem/1
// Video: https://www.youtube.com/watch?v=ltuzsSJ_vSU&ab_channel=SagarMalhotra

class Solution
{
    public:
    int solve(int n, int k) {
        if(n == 1) return 0;
        
        return (solve(n-1, k)+k)%n;
    }
    int josephus(int n, int k)
    {
       return solve(n,k)+1;
    }
};
