class Solution {
  public:
  struct node{
      int stops, Node, dist;
  };
    int CheapestFLight(int n, vector<vector<int>>& flights, int src, int dst, int K)  {
        vector<vector<pair<int,int>>>adj(n);
        for(int i=0; i<flights.size(); i++){
            adj[flights[i][0]].push_back({flights[i][1], flights[i][2]});
            
        }
        vector<int>dist(n,1e9);
        dist[src]=0;
        queue<node>q;
        q.push({0,src,0});

        while(!q.empty()){
            auto a = q.front();
            q.pop();
            int Node = a.Node;
            int stop= a.stops;
            int cost= a.dist;
            if(stop>K) continue;
            for(auto it: adj[Node]){
                int toNode = it.first;
                int toNodeDist= it.second;
                if(cost+toNodeDist < dist[toNode] && stop<= K ){
                    dist[toNode]= cost+toNodeDist;
                    q.push({stop+1,toNode , cost+toNodeDist});
                }
              //  if()
            }
        }
     if(dist[dst]==1e9) return -1; 
     return dist[dst];
    }
};