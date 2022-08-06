// Link : https://practice.geeksforgeeks.org/problems/x-total-shapes3617/1

                   // Same as Number of Islands : Leetcode
#include<bits/stdc++.h>
using namespace std;

class Solution
{
    public:
    void dfs(int i, int j, vector<vector<char>>& grid) {
        int rows = grid.size(), cols = grid[0].size();
        
        if(i<0 || i>=rows || j<0 || j>=cols) return;
        
        if(grid[i][j] != 'X') return;         //i.e grid[i][j] == '0'
        
        grid[i][j] = 0;
        dfs(i, j-1, grid);
        dfs(i, j+1, grid);
        dfs(i-1, j, grid);
        dfs(i+1, j, grid);
    }
    
    //Function to find the number of 'X' total shapes.
    int xShape(vector<vector<char>>& grid) 
    {
        int rows = grid.size(), cols = grid[0].size();
        int cnt = 0;
        
        for(int i=0; i<rows; i++) {
            for(int j=0; j<cols; j++) {
                if(grid[i][j] == 'X') {
                    cnt++;
                    dfs(i, j, grid);
                }
            }
        }
        return cnt;
    }
};