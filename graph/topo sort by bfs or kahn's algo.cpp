// topo sort by bfs or kahn's algo
class Solution {
  public:
    // Function to return list containing vertices in Topological order.
    vector<int> topologicalSort(vector<vector<int>>& adj) {
        // Your code here
        // topological sort is valid for Directed acyclic graph
        // for undirected, a to b , there is a edge from b to a, so must be directed
        // and acyclic, - not a cycle
        // ex- a to b , b to c, c to a, so not possible a to c and c to a at a same time
        
        
        // now by bfs - kahn's algo topo sort
        
        int n= adj.size();
        vector<int>indegree(n,0);
        // insert all nodes with indegree 0, take the out the queue and reduce the adjcaent indegree =
        vector<int>ans;
        for(int i=0; i<n; i++){
            int m= adj[i].size();
            for(int j=0; j<m; j++){
                indegree[adj[i][j]]++;
            }
        }
         queue<int>q;
        for(int i=0; i<n; i++){
            if(indegree[i]==0){
                q.push(i);
            }
        }
        while(!q.empty()){
            int node= q.front();
            q.pop();
             ans.push_back(node);
            for(auto it:adj[node]){
              indegree[it]--;
                if(indegree[it]==0) q.push(it);
            }
        }
        return ans;
    }
};