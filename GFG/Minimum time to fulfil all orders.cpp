// Link : https://practice.geeksforgeeks.org/problems/minimum-time-to-fulfil-all-orders/1

class Solution{
    public:
    
    bool isPossible(int n, vector<int>&arr, int L,int m){
       int count=0;
       for(int i=0;i<L;i++){
           int sum=0;
           int p=arr[i];
           while((sum+p)<=m){
               count++;
               sum+=p;
               p+=arr[i];
               if(count>=n)
               return 1;
           }
       }
       return 0;
   }
   int findMinTime(int n, vector<int>&arr, int L){
       int ans=-1;
       int l=0,r=100000000;
       while(l<=r){
           int m=(l+r)/2;
           if(isPossible(n,arr,L,m)){
               ans=m;
               r=m-1;
           }
           else
           l=m+1;
       }
       return ans;
   }
};