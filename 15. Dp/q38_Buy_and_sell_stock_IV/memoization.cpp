class Solution {
public:
int rec(int i, int k,  int cur, vector<int>& prices, int n, vector<vector<vector<int>>>&dp){
    if(i == n || k == 0) return 0;
    
    if(dp[i][cur][k] != -1) return dp[i][cur][k];
    int profit = 0;
     if( cur == 0) profit= max(rec(i+1, k, 0, prices,n, dp) , rec(i+1, k, 1, prices,n, dp) - prices[i]);
  else profit=  max(rec(i+1, k-1, 0,  prices,n, dp) + prices[i] , rec(i+1, k, 1, prices,n, dp));
    
    return profit;
}
    int maxProfit(int k, vector<int>& prices) {
        int n= prices.size();
        vector<vector<vector<int>>>dp(n+1, vector<vector<int>>(2, vector<int>(k+1, -1)));
        return rec(0, k, 0, prices,n, dp);
    }
};