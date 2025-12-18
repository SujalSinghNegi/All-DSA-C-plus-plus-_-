class Solution {
public:
int rec(int i , int j, string &s, string &p, vector<vector<int>> &dp){
    if(i != -1 && j != -1 && dp[i][j] != -1) return dp[i][j];
    if(i == -1) return  (j == -1 ||(p[j] == '*' && rec(i, j-1, s, p, dp)));
    if(j == -1) return (i == -1);
    if(s[i] == p[j] || p[j] == '?') return rec(i-1, j-1, s, p, dp);
   if(p[j] != '*') return 0;
   return dp[i][j] = ((rec(i-1, j, s, p, dp) | rec(i-1, j-1, s, p, dp)) | rec(i, j-1, s, p, dp));
}
    bool isMatch(string s, string p) {
        int n =s.size(), m = p.size();
        vector<vector<int>>dp(n+1, vector<int>(m+1, -1));
        return rec(n-1, m-1, s, p, dp);
    }
};