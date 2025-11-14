class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int n = grid.size(), m=grid[0].size();
        vector<vector<int>>ans(n,vector<int>(m,1e9));
        ans[0][0]=grid[0][0];
        for(int i = 0; i<n; i++){
        for(int j = 0; j<m; j++){
            if(i==0 && j==0)continue;
            int up = 1e9, left = 1e9;
            if(i>0) up = ans[i-1][j];
            if(j>0)left = ans[i][j-1];
            ans[i][j] = min(up, left)+ grid[i][j];
        }
        }
        return ans[n-1][m-1]; 
    }
};