// Link : https://practice.geeksforgeeks.org/problems/find-the-odd-occurence4820/1

/*eg : Arr[] = {1, 2, 3, 2, 3, 1, 3}
    Output: 3            */

class Solution{   
public:
    int getOddOccurrence(int arr[], int n) {
        int res = 0;
        
        for(int i=0; i<n; i++) {
            res = res^arr[i];
        }
        
        return res;
    }
};