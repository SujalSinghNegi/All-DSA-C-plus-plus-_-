class Solution {
public:
    vector<int> findOrder(int n, vector<vector<int>>& p) {
           vector<vector<int>>adj(n);
        vector<int>indegree(n,0);
        for(int i=0; i<p.size(); i++){
            adj[p[i][1]].push_back(p[i][0]);   
            indegree[p[i][0]]++;
           
        }
        // now apply any dfs or bfs to check the cycle
      
        queue<int>q; 
        for(int i=0; i<n; i++){
           if(indegree[i]==0)q.push(i);
        }
      vector<int>topo;
        while(!q.empty()){
            int node= q.front();
            q.pop();
           
            for(auto it:adj[node]){
                indegree[it]--;
                if(indegree[it]==0)q.push(it);
            }
             topo.push_back(node);
        }
       if (!(topo.size()==n))return {};
       return topo;
    }
};