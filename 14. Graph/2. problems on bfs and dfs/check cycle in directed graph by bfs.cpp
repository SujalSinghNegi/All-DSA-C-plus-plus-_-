// check cycle by toposort
class Solution {
  public:
    // Function to detect cycle in a directed graph.
    bool isCyclic(int V, vector<vector<int>> adj) {
        // code here
        // using bfs, check the cycle in directed graph , by kahn's algo
        // initialise indegree, queue, insert the zero indegree in queue, and then pop, and decrese the indegree
        // you will see the toposort will not get all the element, the queue will empty before, the all nodes
        // it means it have a cycle,  if toposrt have all elements then no cycle
        
        // topo sort the linear ordering sort, 
        int n= adj.size();
        vector<int>indegree(n,0);
        // vector<int>topo;
        int topo=0;
        for(int i=0; i<n; i++){
            for(auto it:adj[i]){
                indegree[it]++;
            }
        }
        queue<int>q;
        for(int i=0; i<n; i++){
            if(indegree[i]==0) q.push(i);
        }
        while(!q.empty()){
            int node= q.front();
            q.pop();
            // topo.push_back(node);
            topo++;
            for(auto it:adj[node]){
                if(indegree[it]){
                    indegree[it]--;
                    if(indegree[it]==0) q.push(it);
                }
            }
        }
        return !(topo==n);
    }
};
