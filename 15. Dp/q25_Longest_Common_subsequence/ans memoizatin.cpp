class Solution {
public:
vector<vector<int>>dp;
    int rec(string &a, string &b, int i, int j, int n, int m){
        if(i == n || j == m) return 0;
        if(dp[i][j] != -1) return dp[i][j];
        int cnt = (a[i] == b[j]);
        int c1 = cnt + rec(a, b, i+1, j+1, n, m); 
        int c2 = rec(a, b, i+1, j, n, m);
        int c3 = rec(a, b, i, j+1, n, m);
        return dp[i][j] = max({c1, c2, c3});
    }
    int longestCommonSubsequence(string text1, string text2) {
        int n= text1.size(), m = text2.size();
        dp.resize(n+1, vector<int>(m+1, -1));
        return rec(text1, text2, 0, 0,n, m);
    }
};