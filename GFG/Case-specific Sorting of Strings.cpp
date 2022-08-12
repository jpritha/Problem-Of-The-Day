// Link : https://practice.geeksforgeeks.org/problems/case-specific-sorting-of-strings4845/1


class Solution
{
    public:
    //Function to perform case-specific sorting of strings.
    string caseSort(string str, int n)
    {
        string small = "", big = "";
        
        for(int i=0; i<str.length(); i++) {
            if(str[i]>='a' && str[i]<='z') {
                small += str[i];
            }
            else {
                big += str[i];
            }
        }
        
        sort(small.begin(), small.end());
        sort(big.begin(), big.end());
        
        int i = 0, j = 0;
        string res = "";
        for(int ind=0; ind<str.length(); ind++) {
            if(str[ind]>='a' && str[ind]<='z') {
                res += small[i++];
            }
            else {
                res += big[j++];
            }
        }
        return res;
    }
};