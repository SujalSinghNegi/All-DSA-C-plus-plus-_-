class DisjointSet{
  
  public:
  vector<int>parent, size;
  DisjointSet(int n){
      parent.resize(n+1);
      size.resize(n+1, 1);
      for(int i=0;i<=n;i++)parent[i]=i;
      
  }
  int findUPair(int u){
      if(parent[u]==u)return u;
      return parent[u]=findUPair(parent[u]);
  }
  void unionBySize(int u, int v){
      int pu= findUPair(u);
      int pv= findUPair(v);
      if(pu==pv)return;
      if(size[pu]<size[pv]){
          parent[pu]=pv;
          size[pv]+=size[pu];
      }
      else{
          parent[pv]=pu;
          size[pu]+=size[pv];
      }
  }
};
class Solution {
  public:
    int numProvinces(vector<vector<int>> adj, int V) {
        // code here
        // the no. of ulp are themself it means there are those num of disjoints
        int cnt=0;
        DisjointSet ds(V);
        for(int i=0; i<V; i++){
            for(int j=0; j<V; j++){
                if(adj[i][j]==1)ds.unionBySize(i,j);
            }
        }
        for(int i=0; i<V; i++){
                if(ds.parent[i]==i)cnt++;
        }
        return cnt;
    }
};