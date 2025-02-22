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
    int makeConnected(int n, vector<vector<int>>& connections) {
        DisjointSet ds(n);
        int cnt=0, cp=0;
        for(int i=0; i<connections.size();i++){
            int a= connections[i][0];
            int b= connections[i][1];
            if(ds.findUPair(a)!= ds.findUPair(b)){
                ds.unionBySize(a, b);
               
                }
                else  cnt++;
        }

        for(int i=0; i<n; i++){
            if(ds.findUPair(i)==i) cp++;
        }
        if(cp-1 <= cnt) return cp-1;
        return -1;
    }
};