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
    vector<int> numOfIslands(int n, int m, vector<vector<int>> &operators) {
        // code here
        DisjointSet ds(n*m);
        vector<vector<int>>vis(n, vector<int>(m, 0));
        int dx[]={0,0,1,-1};
        int dy[]={-1,1,0,0};
        set<int>st;
        vector<int>ans;
        int cnt=0;
        int k= operators.size();
        for(int i=0; i<k; i++){
            int x= operators[i][0];
            int y= operators[i][1];
            if(vis[x][y]){
                ans.push_back(cnt);
                continue;}
             vis[x][y]=1;
             cnt++;
            for(int j=0; j<4; j++){
                int row= x+dx[j];
                int col= y+dy[j];
                if(row>=0 && col>=0 && row<n && col<m && vis[row][col]==1){
                    if(ds.findUPair(row*m+col)!=ds.findUPair(x*m+y))cnt--;
                    ds.unionBySize(x*m+y, row*m+col);
                }
            }
            ans.push_back(cnt);
           
        }
        return ans;
    }
};