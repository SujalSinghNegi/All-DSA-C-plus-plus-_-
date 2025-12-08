class Solution {
public:
    int longestCommonSubsequence(string a, string b) {
        int n= a.size(), m = b.size();
        vector<int>dp(m+1, 0);
        vector<int>cur(m+1, 0);
        for(int i= n-1; i>=0; i--){
            for(int j = m-1; j>=0; j--){
        int cnt = (a[i] == b[j]);
        int c1 = cnt + dp[j+1];
        int c2 = dp[j];
        int c3 = cur[j+1];
         cur[j] = max({c1, c2, c3});
            }
            dp =cur;
        }
        return dp[0];
    }
};