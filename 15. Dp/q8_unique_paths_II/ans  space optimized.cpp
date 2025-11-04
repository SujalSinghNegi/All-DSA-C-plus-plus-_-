class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& ob) {
        int m = ob.size();
        int n = ob[0].size();
        vector<int>dp(n, 0);
        dp[0] =1;

        for(int i =0; i<m; i++){
            for(int j = 0; j<n; j++){
               if(ob[i][j] == 1)dp[j] = 0;
               else{
                if(j>0)dp[j]+= dp[j-1];
               }
            }
        }
        return dp[n-1];
    }
};