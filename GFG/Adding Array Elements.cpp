// Link : https://practice.geeksforgeeks.org/problems/adding-array-element4756/1

#include<bits/stdc++.h>
using namespace std;

class Solution{
  public:
    int minOperations(int arr[], int n, int k) {
        priority_queue<int, vector<int>, greater<int>> pq;
        
        for(int i=0; i<n; i++) {
            pq.push(arr[i]);
        }
        
        int cnt = 0;
        
        while(!pq.empty()) {
            if(pq.top() >= k) {
                break;
            }
            int first = pq.top();
            pq.pop();
            int second = pq.top();
            pq.pop();
            
            pq.push(first + second);
            
            cnt++;
        }
        
        return cnt;
    }
};
