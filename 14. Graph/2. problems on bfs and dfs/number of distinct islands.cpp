// number of distinct island
class Solution {
  public:
    int countDistinctIslands(vector<vector<int>>& grid) {
        // code here
        
        int n= grid.size();
        int m= grid[0].size();
        vector<vector<bool>>vis(n, vector<bool>(m,0));
        queue<pair<int,int>>q;
        set<set<pair<int,int>>>finite;
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(grid[i][j]==1 && !vis[i][j]){
                    // cout<<"i="<<i<<" "<<"j="<<j<<endl;
                    q.push({i,j});
                    set<pair<int,int>>s;
                    while(!q.empty()){
                        auto it= q.front();
                        q.pop();
                        vis[it.first][it.second]=1;
                       // cout<<it.first<<" "<<it.second<<endl;
                        s.insert({it.first, it.second});
                        int dx[4]={0,0,1,-1};
                        int dy[4]={1,-1,0,0};
                        
                        for(int k=0; k<4; k++){
                            int row= dx[k]+it.first;
                            int col= dy[k]+it.second;
                            if(row>=0 && col>=0 && row<n && col<m && grid[row][col]==1&&!vis[row][col]){
                                vis[row][col]=1;
                              //  cout<<"row="<<row<<"col="<<col<<endl;
                                q.push({row,col});
                            }
                        }
                    }
                    set<pair<int,int>>ans;
                    for(auto it:s){
                       pair<int,int>mod_ele={it.first-i, it.second-j};
                        //cout<<it.first<<" "<<it.second<<endl;
                       ans.insert(mod_ele);
                       
                    }
                    finite.insert(ans);
                }
            }
        }
        return finite.size();
    }
};