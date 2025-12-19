class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n= prices.size();
        vector<vector<int>>dp(n+2, vector<int>(2, 0));
            for(int i= n-1; i>=0; i--){
                for(int buy = 0; buy <= 1; buy++){
                int profit;
                if(buy == 0){
                    dp[i][buy] = max(dp[i+1][1] - prices[i] , dp[i+1][0]);
                }else if(buy == 1){
                    dp[i][buy] = max(dp[i+2][0] + prices[i], dp[i+1][1]);
                }
                }
            }
        return dp[0][0];
    }
};