// Link : https://leetcode.com/problems/maximum-69-number/


#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maximum69Number (int num) {
        int n = num;
        
        int i=0, pos = 0;
        while(n) {
            int digit = n % 10;
            if(digit == 6) {
                pos = pow(10, i);
            }
            i++;
            n /= 10;
        }
        pos = pos * 3;       //+3, or +30, or +300, or + 3000
        
        num += pos;
        return num;
    }
};

/*
pos = pos * 3;
Example if input is 969 then pos is 10 , add 30 to get 999.
*/