// Link : https://practice.geeksforgeeks.org/problems/count-occurences-of-a-given-word-in-a-2-d-array/1


class Solution{
    public:
    void dfs(int i, int j, vector<vector<char>>& mat, string target, int ind, int& ans) 
    {
        
        if(i<0 || i>=mat.size() || j<0 || j>=mat[0].size() || (target[ind]!=mat[i][j]) ) {
            return;
        }
        
        if(ind == target.length()-1) {
            ans++;
        }
        
        char temp = mat[i][j];
        mat[i][j] = '0';
        dfs(i-1, j, mat, target, ind+1, ans);
        dfs(i+1, j, mat, target, ind+1, ans);
        dfs(i, j-1, mat, target, ind+1, ans);
        dfs(i, j+1, mat, target, ind+1, ans);
        
        //BackTrack : Since the same letter can be used in some other word going by that path 
        mat[i][j] = temp;
    }
    
    //Main Function
    int findOccurrence(vector<vector<char> > &mat, string target){
        
        int ans = 0;
        
        for(int i=0; i<mat.size(); i++) {
            for(int j=0; j<mat[0].size(); j++) {
                
                dfs(i, j, mat, target, 0, ans);
            }
        }
        
        return ans;
    }
};