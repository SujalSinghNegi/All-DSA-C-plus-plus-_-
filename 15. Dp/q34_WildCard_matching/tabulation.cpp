class Solution {
public:
    bool isMatch(string s, string p) {
        int n =s.size(), m = p.size();
        vector<vector<bool>>dp(n+1, vector<bool>(m+1, 0));
        for(int i =0; i<=n; i++){
            for(int j = 0; j<=m; j++){
                if(i == 0) dp[i][j] =   (j == 0) || ( p[j-1] == '*' && dp[i][j-1] );
                else if(j == 0) dp[i][j] = (i == 0);
                else if(s[i-1] == p[j-1] || p[j-1] == '?') dp[i][j] =  dp[i-1][j-1];
                else if(p[j-1] != '*') dp[i][j] = 0;
                else dp[i][j] =dp[i-1][j] | dp[i-1][j-1] | dp[i][j-1];
            }
        }
        return dp[n][m];
    }
};