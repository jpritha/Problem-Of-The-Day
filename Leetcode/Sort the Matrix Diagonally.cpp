// Link : https://leetcode.com/problems/sort-the-matrix-diagonally/


/*  Time: O(MNlogX), where X is the length of diagonal with X = min(M,N).
    Space: O(MN)
*/

class Solution {
public:
    vector<vector<int>> diagonalSort(vector<vector<int>>& mat) {
        int row = mat.size(), col = mat[0].size();
        
        unordered_map<int, priority_queue<int, vector<int>, greater<int>> > mp;
                            //minheap
        
        for(int i=0; i<row; i++) {
            for(int j=0; j<col; j++) {
                
                //i-j value for every diagonal is same
                mp[i-j].push(mat[i][j]);
            }
        }
        
        for(int i=0; i<row; i++) {
            for(int j=0; j<col; j++) {
                
                mat[i][j] = mp[i-j].top();
                mp[i-j].pop();
            }
        }
        
        return mat;
    }
};

/* Notes :
1> For every element in the matrix (O(MN)) we update a priority queue of size of a        diagonal (1 such operation is O(logX), where X = min(M,N)), for a total of            O(MNlogX) operations.
2> Adding one item to a Heap or PriorityQueue is log(N) and adding N items, it would      be ~ Nlog(N). Even the poll() operation is log(N) for a single item and for all N      items it would be ~ Nlog(N). (N - being the number of items in the PriorityQueue).

3> Total Number of diagonals in a Matrix (Formula) :
   int num = M*N
   int a = num/M , b = num/N;
   Number of diagonals = a + b -1  (-1 for counting the middle diagonal twice).
*/