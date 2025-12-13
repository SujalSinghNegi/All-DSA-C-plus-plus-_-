class Solution {
public:
    int lcs(string &a, string &b){
        int n = a.size(), m= b.size();

        vector<int>dp(m+1, 0), cur(m+1, 0);
        for(int i = 1; i<=n; i++){
            for(int j =1; j<=m; j++){
                if(a[i-1] == b[j-1]) cur[j] = 1 + dp[j-1];
                else cur[j] = max(dp[j], cur[j-1]);
            }
            dp=cur;
        }
        return dp[m];
    }
    int minDistance(string word1, string word2) {
        int n = word1.size(), m =word2.size();
     return n+m- 2*lcs(word1, word2);
    }
};