class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {
        int n= graph.size();

        vector<int>vis(n,-1);
        queue<int>q;
        for(int i=0; i<n; i++){
                if(vis[i]==-1){
                    q.push(i);
                    vis[i]=0;
                    while(!q.empty()){
                        int it=q.front();
                        q.pop();
                        int m= graph[it].size();
                        for(int k=0; k<m; k++){
                            int ad=graph[it][k];
                            if(vis[ad]==-1){
                                vis[ad]= !vis[it];
                                q.push(ad);
                            }else if(vis[ad]==vis[it]) {return false;       
                            }
                        }
                       
                    }
                }
            }
        
        return true;
    }
};n