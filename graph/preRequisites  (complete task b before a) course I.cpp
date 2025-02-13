class Solution {
public:
    bool canFinish(int n, vector<vector<int>>& p) {
        
        // first we make a grpah from the prerequisite, as this is like a toposort of a graph , so we can make a graph
        vector<vector<int>>adj(n);
        vector<int>indegree(n,0);
        for(int i=0; i<p.size(); i++){
            adj[p[i][0]].push_back(p[i][1]);   
            indegree[p[i][1]]++;
           
        }
        // now apply any dfs or bfs to check the cycle
      
        queue<int>q; 
        for(int i=0; i<n; i++){
           if(indegree[i]==0)q.push(i);
        }
        int topo=0;
        while(!q.empty()){
            int node= q.front();
            q.pop();
            topo++;
            for(auto it:adj[node]){
                indegree[it]--;
                if(indegree[it]==0)q.push(it);
            }
        }
        return (topo==n);
    }
};