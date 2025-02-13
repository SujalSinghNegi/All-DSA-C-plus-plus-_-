class Solution {
public:
void dfs(vector<vector<int>>& grid, int i, int j, vector<vector<bool>>& vis,int n, int m){

vis[i][j]=1;

int dx[4]= {0, 0, 1, -1};
int dy[4]= {1, -1, 0, 0};
for(int k=0; k<4; k++){
int x= i+dx[k], y= j+dy[k];
if(x>=0 && x<n && y>=0 && y<m && !vis[x][y] && grid[x][y]==1){
dfs(grid, x, y, vis,n,m);
}
}

}

    int numEnclaves(vector<vector<int>>& grid) {
        int n= grid.size(), m= grid[0].size();
        vector<vector<bool>>vis(n, vector<bool>(m,0));
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(grid[i][j]==1 && !vis[i][j]&&(i==0 || j==0 || i==n-1 || j==m-1)){
                    dfs(grid, i, j, vis,n,m);
                }
            }
        }
        int ans=0;
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                int cnt=1;
                if(grid[i][j]==1 && !vis[i][j]){
                    ans++;
                }
            }
        }
        return ans;
    }
};