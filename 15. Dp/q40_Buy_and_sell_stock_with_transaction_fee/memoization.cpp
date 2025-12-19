class Solution {
public:
    int rec(int i, int buy, vector<int>&prices, int fee, int n, vector<vector<int>> &dp){
        if(i == n) return 0;
        if(dp[i][buy] != -1) return dp[i][buy];
        int profit;
        if(buy == 0){
            profit = max(rec(i+1, 1, prices, fee, n, dp) - prices[i] - fee, rec(i+1, 0,prices, fee, n, dp));
        }else{
            profit = max(rec(i+1, 0, prices, fee, n, dp) + prices[i], rec(i+1, 1, prices, fee, n, dp));
        }
        return dp[i][buy] =profit;
    }

    int maxProfit(vector<int>& prices, int fee) {
        int n = prices.size();
        vector<vector<int>>dp(n+1, vector<int>(2, -1));
        return rec(0, 0, prices, fee, n, dp);
    }
};