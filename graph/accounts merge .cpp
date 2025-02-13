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
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
       
        vector<priority_queue<string>>q;
        unordered_map<string,int>mpp;
        int n= accounts.size();
        DisjointSet ds(n);
        for(int i=0; i<n; i++){
            for(int j=1; j<accounts[i].size(); j++){
                string it= accounts[i][j];
                if(mpp.find(it)==mpp.end()){
                    mpp[it]=i;
                }else{
                    ds.unionBySize(mpp[it], i);
                }
            }
        }
   
        vector<vector<string>>ans(n);
       for(auto it: mpp){
        int ind=ds.findUPair(it.second);
        if(ans[ind].size()==0)ans[ind].push_back(accounts[ind][0]);
        ans[ind].push_back(it.first);
       }
       vector<vector<string>>res;
       for(int i=0; i<ans.size(); i++){
            int m=ans[i].size();
            if(m>0){
                vector<string>temp= ans[i];
                sort(1+temp.begin(), temp.end());
                res.push_back(temp);
            }
        
       }
       return res;
    }
};