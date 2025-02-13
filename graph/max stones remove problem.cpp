class DisjointSet{
    private:
    vector<int>parent, size;
    public:
    DisjointSet(int n){
        parent.resize(n+1);
        size.resize(n+1,1);
        for(int i=0; i<=n; i++){
            parent[i]=i;
        }
    }
    int findUPair(int node){
        if(parent[node]==node) return node;
        return parent[node]=findUPair(parent[node]);
    }

    void unionBySize(int u, int v){
        u= findUPair(u);
        v= findUPair(v);
        if(u==v) return;
        if(size[u]< size[v]){
            parent[u]=v;
            size[v]+=size[u];
        }
        else{
            parent[v]=u;
            size[u]+=size[v];
        }
    }
};
class Solution {
public:
    int removeStones(vector<vector<int>>& stone) {
        int n=0, m=0;
        for(auto it: stone){
            n= max(n, it[0]);
            m= max(m, it[1]);
        }
         DisjointSet ds(n+m+1);
         unordered_map<int,int>mpp;
        for(auto it: stone){
          int row = it[0];
          int col= it[1]+n+1;
          ds.unionBySize(row, col);
          mpp[row]=1;
          mpp[col]=1;
        }
        int s= stone.size(),cnt=0;
        for(auto it:mpp){
            if(ds.findUPair(it.first)==it.first){
                cnt++;
            }
        }
    return s-cnt;
    }
};