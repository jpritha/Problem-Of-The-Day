// Link : https://leetcode.com/problems/rotate-image/


// First swap, and then second Transpose(Reverse Row-wise)
class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        
        //Transpose the matrix
        for(int i=0; i<matrix.size(); i++) {
            for(int j=0; j<i; j++) {
                swap(matrix[i][j] , matrix[j][i]);
            }
        }
        
        //Reverse each row in matrix
        for(int i=0; i<matrix.size(); i++) {
            reverse(matrix[i].begin(), matrix[i].end());
        }
    }
};


/*
Swap    =>      Transpose
1 4 7           7 4 1
2 5 8           8 5 2
3 6 9           9 6 3

*/