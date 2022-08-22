// Link : https://leetcode.com/problems/power-of-three/

class Solution {
public:
    bool isPowerOfThree(int n) {
        if(n < 0) return false;
        if(n == 1) return true;
        
        int rem = 0;
        while(n > 1) {
            rem = n%3;
            if(rem != 0) return false;            //divisible but not power of 3
            n = n/3;
        }
        
        if(n == 1 && rem == 0) return true;
        return false;
    }  
};



/*                         Optimised Way
class Solution {
public:
    bool isPowerOfThree(int n) {
        if(n < 0) return false;
        
    // 1162261467 is 3^19,  3^20 is bigger than int  
        return ( n>0 &&  1162261467 % n == 0);
    }  
};
*/

