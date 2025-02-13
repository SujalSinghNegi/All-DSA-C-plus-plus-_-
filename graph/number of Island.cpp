
// number of Island
class Solution {
public:
void bfs (int row, int col , vector<vector<char>>& grid, vector<vector<bool>>&vis, int n, int m) {
    vis[row][col]=1;
    queue<pair<int,int>>q;
    q.push({row, col});
    while(!q.empty()){
        int row = q.front().first;
        int col= q.front().second;
        q.pop();
        // traverse in the agl bgl and mark them :)
        for(int delrow=-1; delrow<=1; delrow++){
            for(int delcol=-1; delcol<=1; delcol++){
                int nrow= row+delrow;
                int ncol= col+delcol;
               // if(nrow==1 && ncol==1)continue;
                if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && grid[nrow][ncol]=='1'&& !vis[nrow][ncol]){
                    vis[nrow][ncol]=1;
                    q.push({nrow, ncol});
                }
            }
        }
    }


}
    int numIslands(vector<vector<char>>& grid) {
        int n= grid.size();
        int m= grid[0].size();
        vector<vector<bool>>vis(n, vector<bool>(m,0));
        int cnt=0;
        for(int row=0; row<n; row++){
            for(int col=0; col<m; col++){
                if(!vis[row][col] && grid[row][col]=='1'){
                    cnt++;
                    bfs(row, col,  grid,vis, n , m);
                }
            }
        }
        return cnt;
    }
};