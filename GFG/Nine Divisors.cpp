// Link : https://practice.geeksforgeeks.org/problems/nine-divisors3751/1

//Video : https://www.youtube.com/watch?v=P-E62nwTMik&ab_channel=CodeFreaks

class Solution{   
public:
    long long int nineDivisors(long long int N){
        long long int ans = 0;
        long long int limit = sqrt(N);
        
        long long int prime[limit+1]; 
        for(int i=1; i<=limit; i++) {
            prime[i] = i;
        }
        
        for(int i=2; i*i<=limit; i++) {
            if(prime[i] == i) {
                for(int j=i*i; j<=limit; j+=i) {
                    if(prime[j] == j) {
                        prime[j] = i;      //update this multiple to its original prime, 4->2
                    }
                }
            }
        }
        
        for(int i=2; i<=limit; i++) {
            long long int p = prime[i];
            long long int q = prime[(int)i / prime[i]];
            
            if(p*q == i && q != 1 && p != q) {
                ans++;
            }
            else if(prime[i] == i) {
                if(pow(i, 8) <= N) {
                    ans++;
                }
            }
        }
        return ans;
    }
};