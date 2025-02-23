class Solution {
  public:
  void dfs(int i, vector<vector<int>> &adj, vector<int>&vis, stack<int>&st){
      vis[i]=1;
      for(auto it: adj[i]){
          if(!vis[it]){
              dfs(it, adj, vis, st);
          }
      }
      st.push(i);
  }
  void dfs2(int node, vector<vector<int>> &adjT, vector<int> &res, vector<int> &vis){
      vis[node]=1;
      res.push_back(node);
      for(auto it: adjT[node]){
          if(!vis[it])
          dfs2(it, adjT, res, vis);
      }
  }
    int kosaraju(vector<vector<int>> &adj) {
        // code here
        int n= adj.size();
        vector<int>vis(n,0);
        stack<int>st;
        for(int i=0; i<n; i++){
            if(!vis[i]){
                dfs(i, adj, vis, st);
            }
        }
        vector<vector<int>>adjT(n);
        for(int i=0; i<n; i++){
            for(auto it: adj[i]){
                adjT[it].push_back(i);
            }
        }
        vector<vector<int>>ans;
        for(int i=0; i<n; i++)vis[i]=0;
        
        while(!st.empty()){
            int node= st.top();
            st.pop();
            vector<int>res;
            if(!vis[node]){ dfs2(node, adjT,res , vis);
            ans.push_back(res);
                
            }
        }
        return ans.size();
    }
};