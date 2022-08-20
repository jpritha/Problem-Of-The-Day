// Link : https://practice.geeksforgeeks.org/problems/sum-of-numbers-or-number1219/1

class Solution {
  public:
    string findSum(string X, string Y) {
        string res = "";
        
        int i=X.length()-1, j=Y.length()-1, carry = 0;
        
        while(i>=0 && j>=0) {
            
            int sum = (X[i]-'0') + (Y[j]-'0') + carry;
            res += to_string(sum%10);
            carry = sum/10;
            
            i--; j--;
        }
        
        // If either i finishes or j finishes first
        while(i>=0) {
            int sum = (X[i]-'0') + carry;
            res += to_string(sum%10);
            carry = sum/10;
            i--;
        }
        while(j>=0) {
            int sum = (Y[j]-'0') + carry;
            res += to_string(sum%10);
            carry = sum/10;
            j--;
        }
        
        if(carry > 0) {               //cases of all 9s
            res += to_string(carry);
        }
        
        if(res.length() == 0) return "0";
        
        reverse(res.begin(), res.end());
        
        int idx = -1;
        for(int i=res.length()-1; i>=0; i--) {
            if(res[i] != '0') {
                idx = i;
            }
        }
        if(idx == -1) {           // No numbers : no 0's and no other numbers
            return "0";
        }
        return res.substr(idx, res.length());          //else skip the front zeroes
    }
};