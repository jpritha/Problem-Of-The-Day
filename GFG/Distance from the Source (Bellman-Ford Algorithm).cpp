// Link : https://practice.geeksforgeeks.org/problems/distance-from-the-source-bellman-ford-algorithm/1
// Video : https://www.youtube.com/watch?v=75yC1vbS8S8&ab_channel=takeUforward


class Solution{
	public:
	/*  Function to implement Dijkstra
    *   adj: vector of vectors which represents the graph
    *   S: source vertex to start traversing graph with
    *   V: number of vertices
    */
    vector <int> bellman_ford(int V, vector<vector<int>> adj, int S) {
        vector<int> dist(V, 1e8);
        dist[S] = 0;
        
        for(int i=0; i<V-1; i++) {
            
            for(auto& it : adj) {
                if(dist[it[0]] != INT_MAX && dist[it[0]] + it[2] < dist[it[1]]) {
                    
                    dist[it[1]] = dist[it[0]] + it[2];
                }
            }
        }
        
        return dist;
    }
};