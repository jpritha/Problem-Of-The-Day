// LINK : https://practice.geeksforgeeks.org/problems/longest-sub-array-with-sum-k0809/1

                                //    Longest Sub-Array with Sum K

class Solution{
    public:
    int lenOfLongSubarr(int A[],  int N, int K) 
    { 
        
        int maxLen = 0;
        int sum = 0 ;
        unordered_map<int,int> mp;
        
        for(int i =0;i<N;i++){
            sum += A[i];
            
            if(sum == K) {
                maxLen = max(maxLen , i+1);
            }
            if(mp.find(sum - K) != mp.end()) {      //map contains sum-K
                maxLen = max(maxLen , i - mp[sum - K]);
            }
            if(mp.find(sum) == mp.end()) {          //map does not contain sum, so add in map
                mp[sum] = i;
            }
        }
        return maxLen;
    }
};

//map contains sum-K, which means if sum-k already exists in map, then the rest is K in sum.

//DO DRY RUN TO UNDERSTAND BETTER
