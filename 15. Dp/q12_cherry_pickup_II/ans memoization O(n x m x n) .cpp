class Solution {
public:

int dfs(int i , int j1, int j2, vector<vector<int>>&grid, int n , int m ,vector<vector<vector<int>>>&dp){
    if( j1 < 0 || j1 >= m || j2 <0 || j2 >= m) return -1e8;
    if( i == n-1 ){
        if(j1 == j2) return grid[i][j1];
        else return grid[i][j1] +grid[i][j2];
    }
    if(dp[i][j1][j2] != -1) return dp[i][j1][j2];
        int val = 0, maxa = 0;
        val = grid[i][j1];
        if(j1 != j2) val += grid[i][j2];
        for(int di = -1; di <= 1; di++){
            for(int dj = -1; dj <=1; dj++){
               maxa= max(maxa, val+ dfs(i+1 , j1+ di, j2+dj, grid, n, m, dp));

            }
        }

        return (dp[i][j1][j2] = maxa);
          
}
    int cherryPickup(vector<vector<int>>& grid) {
        int n= grid.size(), m = grid[0].size();
        vector<vector<vector<int>>>dp(n, vector<vector<int>>(m, vector<int>(m, -1)));
        return dfs(0, 0, m-1, grid, n, m, dp);
    }
};