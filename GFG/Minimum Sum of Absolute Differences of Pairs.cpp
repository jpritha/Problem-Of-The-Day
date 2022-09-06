// Link : https://practice.geeksforgeeks.org/problems/minimum-sum-of-absolute-differences-of-pairs/1

class Solution{
public:
    long long findMinSum(vector<int> &A,vector<int> &B,int N){
        sort(A.begin(), A.end());
        sort(B.begin(), B.end());
        
        int i = A.size()-1, j = B.size()-1;
        long long sum = 0;
        while(i>=0 && j>=0) {
            sum += abs(A[i] - B[j]);
            i--;
            j--;
        }
        
        return sum;
    }
};


// Difference between two large numbers is always the smallest