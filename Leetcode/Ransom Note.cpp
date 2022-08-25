// Link : https://leetcode.com/problems/ransom-note/

class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        
        if(magazine.length() < ransomNote.length()) return false;
        
        unordered_map<char, int> mp;
        for(int i=0; i<magazine.length(); i++) {
            mp[magazine[i]]++;
        }
        
        for(char c : ransomNote) {
            
            if(mp[c] == 0) return false;
            
            mp[c]--;
        }
        
        return true;
    }
};