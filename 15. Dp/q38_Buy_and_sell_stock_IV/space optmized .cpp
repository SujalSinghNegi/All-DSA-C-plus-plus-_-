class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        int n= prices.size();
        vector<vector<int>>dp(2, vector<int>(k+1, 0)), ahead(2, vector<int>(k+1, 0));
       
        for(int i = n-1; i>=0; i--){
            for(int cur = 0; cur <= 1; cur++){
                for(int cap = 1; cap <=k; cap++){
                    if(cur == 0) dp[cur][cap] = max(ahead[0][cap], ahead[1][cap] - prices[i]);
                    else dp[cur][cap] = max(ahead[0][cap-1] + prices[i], ahead[1][cap]);
        
                }
            }
            ahead = dp;
        }
        return dp[0][k];
    }
};