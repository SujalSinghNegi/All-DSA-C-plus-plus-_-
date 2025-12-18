class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        int n= prices.size();
        vector<vector<vector<int>>>dp(n+1, vector<vector<int>>(2, vector<int>(k+1, 0)));
        for(int i = n-1; i>=0; i--){
            for(int cur = 0; cur <= 1; cur++){
                for(int cap = 1; cap <=k; cap++){
                    if(cur == 0) dp[i][cur][cap] = max(dp[i+1][0][cap], dp[i+1][1][cap] - prices[i]);
                    else dp[i][cur][cap] = max(dp[i+1][0][cap-1] + prices[i], dp[i+1][1][cap]);
        
                }
            }
        }
        return dp[0][0][k];
    }
};