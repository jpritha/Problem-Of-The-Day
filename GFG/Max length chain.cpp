// Link : https://practice.geeksforgeeks.org/problems/max-length-chain/1


/*The structure to use is as follows
struct val{
	int first;
	int second;
};*/
                                             //GREEDY
class Solution{
public:
    static bool comp(pair<int,int> p1, pair<int,int> p2) {
        return p1.second < p2.second;
    }
    /*You are required to complete this method*/
    int maxChainLen(struct val p[],int n){
        vector<pair<int, int>> a(n);
        
        for(int i=0; i<n; i++) {
            a[i].first = p[i].first;
            a[i].second = p[i].second;
        }
        
        sort(a.begin(), a.end(), comp);
        
        stack<pair<int,int>> st;                 //We can also use a vector of pairs
        st.push(a[0]);
        
        for(int i=1; i<n; i++) {
            if(st.top().second < a[i].first) {
                st.push(a[i]);
            }
        }
        return st.size();
    }
};

/*OR
       sort(arr.begin(),arr.end(),[](pair<int,int> p1, pair<int,int> p2){
           return p1.second < p2.second;
       });
*/



// can be done using Backtracking and DP as well, using pick not pick method