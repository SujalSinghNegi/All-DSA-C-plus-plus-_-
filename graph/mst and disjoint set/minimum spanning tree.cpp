class Solution {
  public:
    // Function to find sum of weights of edges of the Minimum Spanning Tree.
    int spanningTree(int V, vector<vector<int>> adj[]) {
        // code here
        // adj matrix is in the vector form, index is the from node, adj[i][0] is the to node,
        // adj[i][1] is the weight
    
        priority_queue<pair<int,int>, vector<pair<int,int>> , greater<pair<int,int>>>q;
        q.push({0,0});
        int sum=0;
        vector<int>vis(V,0);
        
        while(!q.empty()){
            auto a=q.top();
            q.pop();
            int wt= a.first;
            int node= a.second;
            if(vis[node]==1) continue;
            vis[node]=1;
            sum+=wt;
            
            for(auto it:adj[node]){
                int to=it[0];
                int d= it[1];
                if(!vis[to]){
                    q.push({d, to});
                }
            }
        }
   
   return sum;
    }
};

// the idea is the min edge is come on the top then the algo will find the distance according to them
