class Solution {
public:
    int longestCommonSubsequence(string s1, string s2) {
        int n= s1.size(), m= s2.size();
        vector<int>dp(n+1, 0), cur(n+1, 0);
        for(int i= 1; i<=m; i++){
            for(int j = 1; j<=n; j++){
                if(s2[i-1] == s1[j-1])cur[j] = 1+dp[j-1];
                else cur[j] = max(dp[j] , cur[j-1]);
            }
        dp= cur;
        }
    return dp[n];
    }
};