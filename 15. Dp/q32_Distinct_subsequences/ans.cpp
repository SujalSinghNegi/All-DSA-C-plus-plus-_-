class Solution {
public: 
    int numDistinct(string s, string t) {
        int n= s.size(), m =t.size();
        vector<long long>dp(m+1, 0), cur(m+1, 0);
        cur[m] = 1;
        dp[m]=1;
        for(int i = n-1; i>=0; i--){
            for(int j = m-1; j>=0; j--){
                cur[j] = dp[j];
                if(s[i] == t[j]) cur[j] += dp[j+1];
                if(cur[j] > INT_MAX)cur[j] = 0;
            }
            dp= cur;
        
        }

        return cur[0];
    }
};