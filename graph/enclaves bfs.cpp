class crazy{
    public:
    int row; int col;
};
class Solution {
public:

    int numEnclaves(vector<vector<int>>& grid) {
        int n= grid.size(), m= grid[0].size();
        vector<vector<bool>>vis(n, vector<bool>(m,0));
        queue<crazy>q;

        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(grid[i][j]==1 &&(i==0 || j==0 || i==n-1 || j==m-1)){
                   q.push({i,j});
                }
            }
        }
        while(!q.empty()){
            crazy t= q.front();
            q.pop();
        vis[t.row][t.col]=1;

int dx[4]= {0, 0, 1, -1};
int dy[4]= {1, -1, 0, 0};
for(int k=0; k<4; k++){
int x= t.row+dx[k], y= t.col+dy[k];
if(x>=0 && x<n && y>=0 && y<m && !vis[x][y] && grid[x][y]==1){
q.push({x, y});
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