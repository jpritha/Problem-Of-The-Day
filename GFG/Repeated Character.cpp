// Link : https://practice.geeksforgeeks.org/problems/repeated-character2058/1

#include<bits/stdc++.h>
using namespace std;

class Solution
{
  public:
    char firstRep (string s)
    {
        vector<int> freq(26, 0);
                            
        for(int i=0; i<s.length(); i++) {
            freq[s[i]-'a']++;
        }  
        char res;
        
        for(int i=0; i<s.length(); i++) {
            if(freq[s[i]-'a'] > 1) {
                return s[i];
            }
        }
        return '#';
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        string s; cin >> s;
        Solution ob;
        char res = ob.firstRep (s);
        if (res == '#') cout << -1 << endl;
        else cout << res << endl;
    }
    return 0;
}



// } Driver Code Ends