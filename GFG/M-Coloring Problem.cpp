// Question Link : https://practice.geeksforgeeks.org/problems/m-coloring-problem-1587115620/1

/* Video Link : 1> https://www.youtube.com/watch?v=iSs1goch7To&ab_channel=CodeFreaks
                2> https://www.youtube.com/watch?v=p3iBXvb3EJg&ab_channel=CodewithAlisha
                3> https://www.youtube.com/watch?v=wuVwUK25Rfc&ab_channel=takeUforward
*/

class Solution{
public:
    bool isValid(int ind, int j, bool graph[101][101], int V, vector<int>& color) {
        
        //Checking if I can assign color 'j' to node 'ind'
        
        //No other neighbour of ind should have the same color
        for(int k=0; k<V; k++) {
            
            if(graph[ind][k] == 1 && color[k] == j) { 
            //it is a Neighbour   && same color
                return false;
            }
        }
        return true;
    }
    bool solve(int ind, bool graph[101][101], int m, int V, vector<int>& color) {
        if(ind == V) {            // We have reached beyond the last index
            return true;
        }
        
        for(int j=1; j<=m; j++) {       //colors ->for all colors , check on an index
        
            if(isValid(ind, j, graph, V, color)) {  //if true
            
                color[ind] = j;
                
                if(solve(ind+1, graph, m, V, color) == true) {
                    return true;
                }
                
                color[ind] = -1;
            }
        }
        return false;
    }
    
    // Function to determine if graph can be coloured with at most M colours such
    // that no two adjacent vertices of graph are coloured with same colour.
    bool graphColoring(bool graph[101][101], int m, int V) {
        
        vector<int> color(V, -1);
        
        return solve(0, graph, m, V, color);
                // source = 0
    }
};