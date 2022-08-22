// Link : https://leetcode.com/problems/power-of-four/
// Reference : https://leetcode.com/problems/power-of-four/discuss/772428/C%2B%2B-Three-Solution-or-Explain-or-Naive-orBit-Manipulation


class Solution {
public:
    bool isPowerOfFour(int n) {
        if(n < 0) return false;
        if(n == 1) return true;
        
        //If it is not a Power of 2 , it is not power of 4 either
        
        int one_pos = 0; 
        if((n & n-1) == 0) {              //Then only it's Power of 2
            
            while(n) {
                one_pos++; 
                if(n & 1) { 
                    break;
                }
                n >>= 1;
            }
        }
        
        //To be power of 4 , one should be in ODD place and a power of 2
        if(one_pos & 1) {          //ODD PLACE   
            return true;
        }
        return false;
    }
};


/* -------------------------------------------------------------------------------------------------------------------
                        ANOTHER METHOD : (One Liner Formula) : 0ms
class Solution {
public:
    bool isPowerOfFour(int n) {
        return n>0 && (n & (n-1)) == 0 && (n-1) % 3 == 0;
    }
};             
*/


/* --------------------------------------------------------------------------------------------------------------------   
                        ANOTHER METHOD : (BRUTE FORCE)
class Solution {
public:
    bool isPowerOfFour(int n) {
        if(n == 1) return true;
        
        int rem = 0;
        while(n > 1) {
            rem = n%4;
            if(rem != 0) return false;
            n = n/4;
        }
        
        if(n==1 && rem==0) return true;
        return false;
    }
};             
*/
