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
      // to jo sbse end pe hoga wo push ho jayega, mtlb ki jispe se koi edge nhi jari hogi, sari edge ari hongi wo push hoga, 
      // mtlb ki jiski indegree max hogi.
      // or phir jb stack ko reverse karenge to topological sort mil jayega
      // reverse mtlb hai ki stack ko kisi vector me ek ek krke push krenge
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
