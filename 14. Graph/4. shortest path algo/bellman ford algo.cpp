class Solution {
  public:
    /*  Function to implement Bellman Ford
     *   edges: vector of vectors which represents the graph
     *   src: source vertex
     *   V: number of vertices
     */
    vector<int> bellmanFord(int V, vector<vector<int>>& edges, int src) {
        // Code here
        int n= edges.size();
        vector<int>dist(V,1e8);
        dist[src]=0;
        for(int i=0; i<V; i++){
            for(int j=0; j<n; j++){
                int a= edges[j][0];
                int b = edges[j][1];
                int d= edges[j][2];
                if(dist[a] != 1e8 && d+ dist[a] < dist[b] ){
                    if(i==V-1) return {-1};
                    dist[b]= dist[a]+d;
                }
            }
        }
        
        return dist;
    }
};

// do the iteration V-1 times because the shortest path can have at most V-1 edges
// if we find a shorter path in the Vth iteration, then there is a negative cycle in the graph
// Time Complexity: O(V*E) where V is the number of vertices and E is the number of edges in the graph
// Space Complexity: O(V) where V is the number of vertices in the graph