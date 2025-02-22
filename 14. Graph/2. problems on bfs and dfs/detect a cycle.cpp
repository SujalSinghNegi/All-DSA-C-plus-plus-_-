class node{
    public:
    int val, from;
    node(int v, int f):val(v), from(f){}
};
class Solution {
  public:
    // Function to detect cycle in an undirected graph.
    
    bool isCycle(vector<vector<int>>& adj) {
      int n= adj.size();
       vector<bool>vis(n,0);
        queue<node>q;
        for(int j=0; j<n; j++){
            if(!vis[j]){
                q.push({j, -1});
                vis[j]=1;
                while(!q.empty()){
                    node t= q.front();
                    q.pop();
                    vis[t.val]=1;
                     int s= adj[t.val].size();
                    for(int i=0; i<s; i++){
                      if(!vis[adj[t.val][i]]){
                      q.push({adj[t.val][i], t.val});
                      vis[adj[t.val][i]]=1;
                      }
                      else if(t.from!=adj[t.val][i])return true;
                    }
                }
            }
                
        }
        
        
        return false;
    }
};