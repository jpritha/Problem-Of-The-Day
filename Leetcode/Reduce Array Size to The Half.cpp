// Link : https://leetcode.com/problems/reduce-array-size-to-the-half/

class Solution {
public:
    int minSetSize(vector<int>& arr) {
        
        unordered_map<int, int> mp;
        for(int it : arr) {
            mp[it]++;
        }
        
        priority_queue<int> pq;
        for(auto it : mp) {
            pq.push(it.second);
        }
        
        int ans = 0, sum = 0;
        while(!pq.empty()) {
            ans++;
            sum += pq.top();
            pq.pop();
            
            if(sum >= arr.size()/2) {
                return ans;
            }
        }
        return -1;
    }
};