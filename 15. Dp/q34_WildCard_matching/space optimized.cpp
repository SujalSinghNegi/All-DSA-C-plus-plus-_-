class Solution {
public:
    bool isMatch(string s, string p) {
        int n =s.size(), m = p.size();
        vector<bool>dp(m+1, 0), cur(m+1, 0);
        for(int i =0; i<=n; i++){
            for(int j = 0; j<=m; j++){
                if(i == 0) cur[j] =   (j == 0) || ( p[j-1] == '*' && cur[j-1] );
                else if(j == 0) cur[j] = (i == 0);
                else if(s[i-1] == p[j-1] || p[j-1] == '?') cur[j] =  dp[j-1];
                else if(p[j-1] != '*') cur[j] = 0;
                else cur[j] =dp[j] | dp[j-1] | cur[j-1];
            }
            dp =cur;
        }
        return dp[m];
    }
};