// Link : https://leetcode.com/problems/number-of-islands/

class Solution {
private:
    void dfs(vector<vector<char>>& grid, int i, int j, int rows, int cols){
        
        //Boundary case
        if(i<0 || i>=rows || j<0 || j>=cols){
            return;
        }
        
        if(grid[i][j] != '1') return;                 //Already Visited Land:2 || Water:0
        
        //Mark current land as Visited Land
        grid[i][j] = '2';                    //or grid[i][j] = '0'(if u want)
        
        dfs(grid, i-1, j, rows, cols);
        dfs(grid, i+1, j, rows, cols);
        dfs(grid, i, j-1, rows, cols);
        dfs(grid, i, j+1, rows, cols);
        
    }
public:                                                   //main function
    int numIslands(vector<vector<char>>& grid) {
        int island = 0;
        int rows = grid.size() , cols = grid[0].size();
        
        for(int i=0; i<rows; i++){
            for(int j=0; j<cols; j++){
                
                if(grid[i][j] == '1'){                
                    island++;
                    dfs(grid, i, j , rows, cols);        //to check further land to its side
                                                         //and mark them visited: 2
                }
            }
        }
        return island;
    }
};
