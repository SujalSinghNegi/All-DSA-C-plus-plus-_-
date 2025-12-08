class Solution {
public:
    int longestCommonSubsequence(string a, string b) {
        int n= a.size(), m = b.size();
        vector<vector<int>>dp;
        dp.resize(n+1, vector<int>(m+1, 0));
        for(int i = 0; i<m; i++)dp[n][i]=0;
        for(int j = 0; j<n; j++)dp[j][m]=0;
        for(int i= n-1; i>=0; i--){
            for(int j = m-1; j>=0; j--){
        int cnt = (a[i] == b[j]);
        int c1 = cnt + dp[i+1][j+1];
        int c2 = dp[i+1][j];
        int c3 = dp[i][j+1];
         dp[i][j] = max({c1, c2, c3});
            }
        }
        return dp[0][0];
    }
};