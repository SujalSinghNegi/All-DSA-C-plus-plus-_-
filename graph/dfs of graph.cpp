class Solution {
  public:
    void dfs(int x, vector<int>&ans, vector<bool>&vis, vector<vector<int>>&adj){
        ans.push_back(x);
        for(auto it:adj[x]){
            if(!vis[it]){
                vis[it]=1;
                dfs(it, ans, vis, adj);}
        }
    }
    // Function to return a list containing the DFS traversal of the graph.
    vector<int> dfsOfGraph(vector<vector<int>>& adj) {
        int n= adj.size();
        vector<bool>vis(n,0);
        vector<int>ans;
        vis[0]=1;
        dfs(0, ans, vis, adj);
        return ans;
    }
};