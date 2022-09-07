// Link : https://practice.geeksforgeeks.org/problems/stack-permutations/1


class Solution{
public:
    int isStackPermutation(int N,vector<int> &A,vector<int> &B){
        stack<int> s;
        
        int i=0, j=0;
        while(i<N && j<B.size()) {
            s.push(A[i]);
            
            while(!s.empty() && s.top() == B[j]) {
                s.pop();
                j++;
            }
            i++;
        }
        
        if(s.empty()) {
            return 1;
        }
        return 0;
    }
};