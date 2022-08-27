// Link : https://practice.geeksforgeeks.org/problems/array-of-alternate-ve-and-ve-nos1401/1

class Solution{
public:

	void rearrange(int arr[], int n) {
	    
	    vector<int> pos_arr;        //store positive elements;
	    for(int i=0; i<n; i++) {
	        if(arr[i] >= 0) {
	            pos_arr.push_back(arr[i]);
	        }
	    }
	    vector<int> neg_arr;         //store negative elements;
	    for(int i=0; i<n; i++) {
	        if(arr[i] < 0) {
	            neg_arr.push_back(arr[i]);
	        }
	    }
	    
	    int i=0, j=0, k = 0;
	    
        while(i<pos_arr.size() && j<neg_arr.size()) {
            arr[k++] = pos_arr[i++];
            arr[k++] = neg_arr[j++];
        }
        while(i < pos_arr.size()) {
            arr[k++] = pos_arr[i++];
        }
        while(j < neg_arr.size()) {
            arr[k++] = neg_arr[j++];
        }
        
	}
};


/*
9 4 -2 -1 5 0 -5 -3 2 5 2

pos_array =  9  4  5  0  2 5 2
neg_array = -2 -1 -5 -3
*/