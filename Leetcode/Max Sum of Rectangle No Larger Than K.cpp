/* Link : https://leetcode.com/problems/max-sum-of-rectangle-no-larger-than-k/
Video : 1> https://www.youtube.com/watch?v=IDv9yvQN3Uc&ab_channel=CodingDecoded
        2> https://www.youtube.com/watch?v=VsBXWpBbuig&ab_channel=CodingDecoded
        3> https://www.youtube.com/watch?v=oiyXT0PddGM&ab_channel=CodeChef
*/

class Solution {
public:
    int maxSumSubmatrix(vector<vector<int>>& matrix, int k) {
        int res = INT_MIN;
        int row = matrix.size(), col = matrix[0].size();
        
        for(int L=0; L<col; L++) {          //L = Left
            
            vector<int> rowsum(row, 0);
            for(int R=L; R<col; R++) {      //R = Right
                
                for(int i=0; i<row; i++) {
                    rowsum[i] += matrix[i][R];
                }
                
                // Find the max subarray no more than K
                set<int> s;
                s.insert(0);
                int currsum = 0;
                for(int sum : rowsum) {
                    currsum += sum;
                    auto it = s.lower_bound(currsum - k);
                    if(it != s.end()) {
                        res = max(res , currsum - *it);
                    }
                    s.insert(currsum);
                }
            }
        }
        return res;
    }
};