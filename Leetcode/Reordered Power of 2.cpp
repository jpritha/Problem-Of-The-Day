// Link : https://leetcode.com/problems/reordered-power-of-2/

class Solution {
public:
    bool reorderedPowerOf2(int N) {
        string N_str = sorted_num(N);
        for (int i = 0; i < 32; i++)
            if (N_str == sorted_num(1 << i)) return true;
        return false;
    }
    
    string sorted_num(int n) {
        string res = to_string(n);
        sort(res.begin(), res.end());
        return res;
    }
};


//OR
//     bool reorderedPowerOf2(int N) {
//         long c = counter(N);
//         for (int i = 0; i < 32; i++)
//             if (counter(1 << i) == c) return true;
//         return false;
//     }

//     long counter(int N) {
//         long res = 0;
//         for (; N; N /= 10) res += pow(10, N % 10);
//         return res;
//     }