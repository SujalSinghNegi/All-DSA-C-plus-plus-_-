class Solution {
public:
int rec(int i, int j, string &s, string &t, vector<vector<int>>& dp){
    if(j == -1) return 1;
    if(i == -1) return 0;
    if(dp[i][j]!= -1) return dp[i][j];
    return dp[i][j]=  rec(i-1, j, s, t, dp) + (s[i] == t[j] ? rec(i-1, j-1, s, t, dp): 0);
}
  
    int numDistinct(string s, string t) {
        int n= s.size(), m =t.size();
        vector<vector<int>>dp(n+1, vector<int>(m+1, -1));
        return rec(n, m, s, t,dp);
    }
};