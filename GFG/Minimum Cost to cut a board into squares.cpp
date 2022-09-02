// Link : https://practice.geeksforgeeks.org/problems/minimum-cost-to-cut-a-board-into-squares/1


class Solution {
public:
    int minimumCostOfBreaking(vector<int> X, vector<int> Y, int m, int n){
        //Write your code here
        int cnt = 0;
        
        sort(X.begin(), X.end(), greater<int>());
        sort(Y.begin(), Y.end(), greater<int>());

        
        int i=0, j=0;
        int h=1, v=1;
        
        while(i!=n && j!=m) {
            
            if(X[i] < Y[j]) {
                cnt += (Y[j++] * h);
                v++;
            }
            else {
                cnt += (X[i++] * v);
                h++;
            }
        }
        while(i!=n) {
            cnt += (X[i++] * v);
        }
        while(j!=m)
        {
            cnt += (Y[j++] * h);
        }
        
        return cnt;
    }
};
