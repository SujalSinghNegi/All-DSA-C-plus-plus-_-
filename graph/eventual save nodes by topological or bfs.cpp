class Solution {
  public:
    vector<int> eventualSafeNodes(int V, vector<int> adj[]) {
        // code here
        // by using the topological or say by bfs, we have to do only one thing
        //1- reverese the graph direction , and caluclate the indegree and then at queue store the elments that poped
        // those are your safe nodes
        vector<int>adjRev[V];
        vector<int>indegree(V,0);
        for(int i=0; i<V; i++){
            for(auto it:adj[i]){
                adjRev[it].push_back(i);
                indegree[i]++;
            }
        }
        queue<int>q ;
        for(int i=0; i<V; i++){
            if(indegree[i]==0)q.push(i);
        }
        vector<int>check(V,0);
        while(!q.empty()){
            int node= q.front();
            q.pop();
            check[node]=1;
            for(auto it:adjRev[node]){
                indegree[it]--;
                if(indegree[it]==0)q.push(it);
            }
        }
        vector<int>ans;
        for(int i=0; i<V; i++){
            if(check[i])ans.push_back(i);
        }
        return ans;
        
    }
};
