
class Solution {
  public:
    bool dfs(int node, int col, vector<int>&color, vector<vector<int>>&adj){
        color[node]=col;
        
        for(auto it:adj[node]){
           if(color[it]==-1){
           if(!dfs(it,!col,color,adj)) return false;}
           else if(color[it]==col){
               return false;
           }
        }
        return true;
    }
    bool isBipartite(vector<vector<int>>& adj) {
        // Code here
        int V= adj.size();
        vector<int>color(V,-1);
        for(int i=0; i<V; i++){
            if(color[i]==-1){
                if(!dfs(i,0,color,adj))return false;
            }
        }
        return true;
        
    }
};