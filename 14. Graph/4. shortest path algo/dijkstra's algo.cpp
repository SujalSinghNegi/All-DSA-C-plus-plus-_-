class Solution {
  public:
    // Function to find the shortest distance of all the vertices
    // from the source vertex src.
    vector<int> dijkstra(vector<vector<pair<int, int>>> &adj, int src) {
        // Code here
        // valid for the positive nodes, 
        // make a dist array and a pirority queue



        int n= adj.size();
        vector<int>dist(n,1e9);
        priority_queue<pair<int,int>>pq;
        pq.push({0,src});
        dist[src]=0;
        while(!pq.empty()){
            auto a= pq.top();
            pq.pop();
            int wt= a.first;
            int node= a.second;
            for(auto it: adj[node]){ 
                if(wt+it.second < dist[it.first]){
                    dist[it.first]=wt+it.second;
                    pq.push({dist[it.first], it.first});
                }
            }
        }
        for(int i=0; i<n; i++)if(dist[i]==1e9)dist[i]=-1;
        return dist;
        
    }
};

/*
time comp = 
queue will push at max all nodes than itself so O(n), n is the current no. of elements,  and in the priority queue take the log n time to push the one element
so for doing it for every node the n will go to n^2 so the priority queue will have the n^2 elemnts 
and the it take n^2 log n^2 time to push all the elements
so the time comp will be O(n^2 log n^2)
and n^2 log n^2 = 2n^2 log n = O(n^2 log n)
and E (no. of edges) = O(n^2) as the max no. of edges can be n(n-1)/2
so TC= O(E log n) or O(n^2 log n) at the worst case where all nodes are connected to all nodes


*/