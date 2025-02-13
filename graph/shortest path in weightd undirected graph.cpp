class Solution {
  public:
    vector<int> shortestPath(int n, int m, vector<vector<int>>& edges) {
        // Code here
       
       vector<vector<pair<int,int>>>adj(n+1);
       for(int i=0; i<edges.size(); i++){
           adj[edges[i][0]].push_back({edges[i][1], edges[i][2]});
            adj[edges[i][1]].push_back({edges[i][0], edges[i][2]});
       }
        vector<int>dist(n+1,1e9);
        vector<int>parent(n+1);
        for(int i=0; i<=n; i++)parent[i]=i;
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>>pq;
        pq.push({0,1});
        dist[1]=0;
        parent[1]=1;
        while(!pq.empty()){
            auto a= pq.top();
            pq.pop();
            int curwt=a.first;
            int node=a.second;
            for(auto it:adj[node]){
                int to=it.first;
                int d=it.second;
                if(curwt+d < dist[to]){
                    dist[to]=curwt+d;
                    parent[to]=node;
                    pq.push({dist[to], to});
                }
            }
        }
        vector<int>ans;
        int node= n; ans.push_back(node);
        while(parent[node]!= node){
          ans.push_back(parent[node]);
          node=parent[node];
        }
        ans.push_back(dist[n]);
        reverse(ans.begin(), ans.end());
        if(node!=1)return {-1};
        return ans;
        
    }
};