class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int n = grid.size(), m=grid[0].size();
        vector<int>ans(m,1e9);
        ans[0]=grid[0][0];
        for(int i = 0; i<n; i++){
        for(int j = 0; j<m; j++){
            if(i==0 && j==0)continue;
            int left = 1e9;
            int up = ans[j];
            if(j>0)left = ans[j-1];
            ans[j] = min(up, left)+ grid[i][j];
        }
        }
        return ans[m-1]; 
    }
};