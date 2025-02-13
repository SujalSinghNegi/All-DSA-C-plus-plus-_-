//number of provinces or say the disconned graph
class Solution {
public:
void dfs(int node, vector<bool>&vis, vector<vector<int>>&isConnected, int n){
    for(int j=0; j<n; j++){
       if(j==node-1)continue;
       int c= isConnected[node-1][j];
       if(c && !vis[j+1]){
        vis[j+1]=1;
        dfs(j+1, vis, isConnected,n);
        
        
       }
    }
}
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n= isConnected.size();
        vector<bool>vis(n+1,0);
        int ans=0;
        
        for(int i=1; i<=n; i++){
            if(!vis[i]){
                vis[i]=1;
                ans++;
                dfs(i, vis, isConnected, n);
            }
        }
        return ans;
    }
};