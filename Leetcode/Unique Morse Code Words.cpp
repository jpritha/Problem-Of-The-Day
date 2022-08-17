// Link : https://leetcode.com/problems/unique-morse-code-words/


class Solution {
public:
    int uniqueMorseRepresentations(vector<string>& words) {
        if(words.size() == 1) return 1;
        
        vector<string> morse_code = {".-","-...","-.-.","-..",".","..-.","--.","....","..",".---","-.-",".-..","--","-.","---",".--.","--.-",".-.","...","-","..-","...-",".--","-..-","-.--","--.."};
        
        unordered_set<string> st;
        
        for(int i=0; i<words.size(); i++) {
            string word = words[i];
            string code = "";
            
            for(int j=0; j<word.size(); j++) {
                code += morse_code[word[j]-'a'];
            }
            st.insert(code);
        }
        return st.size();
    }
};