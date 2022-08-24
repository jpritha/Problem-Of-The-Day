// Question Link : https://practice.geeksforgeeks.org/problems/generate-ip-addresses/1
// Video Link : https://www.youtube.com/watch?v=DFTF5yMjHoM&ab_channel=CodeFreaks
// GFG REFERENCE : https://www.geeksforgeeks.org/program-generate-possible-valid-ip-addresses-given-string/


class Solution{
  public:
    bool isValid(string str) {
        int n = str.length();
        if(n==0 || n>3 || (str[0]=='0' && n>1) || stoi(str)>255) {
            return false;
        }
        return true;
    }
    //Main function
    vector<string> genIp(string &s) {
        vector<string> ans;
        
        int n = s.length();
        if(n > 12) return ans;
        
        for(int i=1; i<n-2; i++) {                      //till n-3
            for(int j=i+1; j<n-1; j++) {                //till n-2
                for(int k=j+1; k<n; k++) {              //till n-1
                    
                    string a = s.substr(0, i);          //i length
                    string b = s.substr(i, j-i);        //j-i length
                    string c = s.substr(j, k-j);        //k-j length
                    string d = s.substr(k, n-k);        //n-k length
                    
                    if(isValid(a) && isValid(b) && isValid(c) && isValid(d)) {
                        ans.push_back(a + "." + b + "." + c + "." + d);
                    }
                }
            }
        } 
        return ans;
    }
};