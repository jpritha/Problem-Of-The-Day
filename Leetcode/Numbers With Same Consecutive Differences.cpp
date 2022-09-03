// Link : https://leetcode.com/problems/numbers-with-same-consecutive-differences/


class Solution {
public:
    vector<int> numsSameConsecDiff(int n, int k) {
        vector<int> curr = {1, 2, 3, 4, 5, 6, 7, 8, 9};
        
        for(int i=2; i<=n; i++) {         //It has to be 2 at first to make a difference
            
            vector<int> temp;
            
            for(int& x : curr) {
                int y = x%10;
                
                if(y+k < 10) {
                    temp.push_back(x*10 + (y+k));
                }
                
                if(k>0 && y-k>=0) {
                    temp.push_back(x*10 + (y-k));
                }
            }
            curr = temp;
        }
        
        return curr;
    }
};