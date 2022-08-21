// Link : https://leetcode.com/problems/split-array-into-consecutive-subsequences/
/* Video : 1> https://www.youtube.com/watch?v=Gmc-4Dpzw2g&ab_channel=CodeFreaks
           2> https://www.youtube.com/watch?v=uJ8BAQ8lASE&ab_channel=NideeshTerapalli
*/

class Solution {
public:
    bool isPossible(vector<int>& nums) {
        unordered_map<int, int> mp, tail;
        
        for(int it : nums) {
            mp[it]++;
        }
        
        for(int it : nums) {
            if(mp[it] == 0) continue;
            else {
                mp[it]--;
            }
            if(tail[it-1] > 0) {           //if one less element present in tail map
                tail[it-1]--;
                tail[it]++;
            }
            else if(mp[it+1] > 0 && mp[it+2] > 0) {
                mp[it+1]--;
                mp[it+2]--;
                tail[it+2]++;           //push the last value in tail map
            }
            else {
                return false;
            }
        }
        return true;
    }
};