class Solution {
  public:
  void dfs(int i, vector<int>&vis,stack<int>&s, vector<vector<pair<int,int>>>&adj){
      vis[i]=1;
      for(auto it:adj[i]){
          if(!vis[it.first]){
              dfs(it.first, vis, s, adj);
          }
      }
      s.push(i);
  }
    vector<int> shortestPath(int V, int E, vector<vector<int>>& edges) {
        // code here
        vector<vector<pair<int,int>>>adj(V);
        for(int i=0; i<edges.size(); i++){
            adj[edges[i][0]].push_back({edges[i][1], edges[i][2]});
        }
        stack<int>s;
        vector<int>vis(V,0);
        // for(int i=0; i<V; i++){
        //     if(!vis[i]){
        //         dfs(i, vis, s, adj);
        //     }
        // }
        dfs(0,vis,s,adj); // as the src is always zero given , so the dfs 
        // will be call from zero and the elements will be stored in the stack in toposort
        
        vector<int>dist(V,1e9); // 9 zero after 9 As the INT_MAX + any small no. go the after ward the INT_MIN so 
        // a big number like 1e9 helps
        
         dist[0]=0; // distance form the src is zero
         while(!s.empty()){
             int node= s.top();
             s.pop();
             for(auto it:adj[node]){
                 int v= it.first, wt= it.second;
                 if(dist[node]+wt<dist[v]){
                     dist[v]=dist[node]+wt;
                 }
             }
            
         }
         for(int i=0; i<V; i++){
             if(dist[i]==1e9)dist[i]=-1;
         }
         return dist;
    }
};