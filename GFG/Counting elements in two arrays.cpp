// Link : https://practice.geeksforgeeks.org/problems/counting-elements-in-two-arrays/1


class Solution{
  public:
    int binarySearch(int arr2[], int n, int x) {
        int l = 0, r = n-1;
        
        while(l <= r) {
            int mid = l + (r - l)/2;
            
            if(arr2[mid] <= x) {
                l = mid+1;
            }
            else 
                r = mid-1;
        }
        return l;
    }

    //Main Function
    vector<int> countEleLessThanOrEqual(int arr1[], int arr2[], 
                                 int m, int n)
    {
        vector<int> res;
        
        sort(arr2, arr2+n);
        
        for(int i=0; i<m; i++) {
            int ans = binarySearch(arr2, n, arr1[i]);
            res.push_back(ans);
        }
        
        return res;
    }
};
