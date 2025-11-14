#define vvi vector<vector<int>>
struct dir{
    int i1, j1, i2, j2;
};
int d[] = {-1, 0, 1};

class Solution {
public:
    int dfs(dir c, vvi &grid, int n, int m){
        if(c.i1 == n-1){
            if(c.j1 == c.j2){
                return grid[c.i1][c.j1];
            }else return grid[c.i1][c.j1] + grid[c.i2][c.j2];
        }
        int cur= 0, maxa =0;
        if(c.j1 == c.j2)cur= grid[c.i1][c.j1];
        else cur = grid[c.i1][c.j1] + grid[c.i2][c.j2];
        for(int i =0; i<3; i++){
            for(int j = 0; j<3; j++){ 
                if(c.i1 + 1 < n  && c.j1 + d[i] < m && c.j1 + d[i] >=0 && c.j2 + d[j] < m && c.j2 + d[j] >= 0) { 
                maxa = max(maxa, cur+dfs({c.i1 + 1, c.j1 + d[i], c.i2 + 1, c.j2 + d[j]}, grid, n,m));
                }
            }
        }
        return maxa;
    }
    int cherryPickup(vector<vector<int>>& grid) {
        int n =grid.size(), m = grid[0].size();
        return dfs({0,0, 0, m-1}, grid, n, m);
    }
};