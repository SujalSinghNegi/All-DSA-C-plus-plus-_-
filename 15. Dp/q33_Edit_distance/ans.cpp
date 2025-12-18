class Solution {
public:
    int minDistance(string a, string b) {
        int n = a.size(), m = b.size();
        vector<int>dp(m+1, 0), cur(m+1, 0);
          for(int j = 0; j<=m; j++){dp[j] = j;}

        for(int i = 1; i<=n; i++){
            cur[0] = i;
            for(int j = 1; j<=m; j++){
cur[j]  = min({
        1 +cur[j-1],
         1+dp[j],
          (a[i-1] != b[j-1]) +  dp[j-1]
     });
            }
            dp = cur;
        }
        return dp[m];
    }
};