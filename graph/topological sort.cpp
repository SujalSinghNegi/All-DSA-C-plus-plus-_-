// topological sort
class Solution {
  public:
    // Function to return list containing vertices in Topological order.
    void dfs(int i, stack<int>&s,vector<vector<int>>& adj, vector<int>&vis){
        vis[i]=1;
      for(auto it:adj[i]){
          if(!vis[it]){
              dfs(it, s, adj, vis);
          }
      }
      s.push(i);
      
    }
    vector<int> topologicalSort(vector<vector<int>>& adj) {
        // Your code here
        stack<int>s;
        int n= adj.size();
        vector<int>vis(n,0);
        for(int i=0; i<n; i++){
            if(!vis[i])dfs(i, s, adj, vis);
        }
        vector<int>ans;
        while(!s.empty()){
            ans.push_back(s.top());
            s.pop();
        }
        return ans;
    }
};
