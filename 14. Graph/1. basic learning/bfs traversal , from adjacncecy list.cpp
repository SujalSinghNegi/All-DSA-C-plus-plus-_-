// bfs traversal , considering 0 baaed indexing, and given the adjacnecy list
class Solution {
  public:
    // Function to return Breadth First Traversal of given graph.
    vector<int> bfsOfGraph(vector<vector<int>> &adj) {
        // Code here
        int n= adj.size();
        vector<int>bfs;
        queue<int>q;
        q.push(0);
        vector<bool>vis(n, 0);
        vis[0]=1;
        
        while(!q.empty()){
            int a = q.front();
            q.pop();
            bfs.push_back(a);
            for(int i=0; i<adj[a].size(); i++){
                if(!vis[adj[a][i]]){
                    vis[adj[a][i]]=1;
                    q.push(adj[a][i]);
                }
            }
        }
        return bfs;
    }
};