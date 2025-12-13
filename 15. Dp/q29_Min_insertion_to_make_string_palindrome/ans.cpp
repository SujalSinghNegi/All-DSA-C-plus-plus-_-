class Solution {
public:
    int lcs(string &a, string &b){
        int n = a.size();
        vector<int>dp(n+1, 0), cur(n+1, 0);
        for(int i = 1; i<=n; i++){
            for(int j =1; j<=n; j++){
                if(a[i-1] == b[j-1]) cur[j] = 1 + dp[j-1];
                else cur[j] = max(dp[j], cur[j-1]);
            }
            dp=cur;
        }
        return dp[n];
    }
    int minInsertions(string s) {
        string t = s;
        reverse(t.begin(), t.end());
        int n = s.size();
       return n - lcs(s, t);
    }
};