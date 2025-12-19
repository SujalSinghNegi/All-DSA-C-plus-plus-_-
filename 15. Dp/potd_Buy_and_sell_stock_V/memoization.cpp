#define ll long long
class Solution {
public:
// trans = 0, can buy or sell, trans = 1, can sell, trans = 2 , have to purchase
    ll rec(int i , int trans, int cap, vector<int>& prices, vector<vector<vector<ll>>>&dp){
        int n = prices.size();
        if(i == n || cap == 0) return (trans  == 2? -1e18 : 0 );
        if(dp[i][trans][cap] != -1) return dp[i][trans][cap];
        ll profit;
        if(trans == 0){
            profit= max({rec(i+1, 1, cap, prices, dp) - prices[i] , rec(i+1, 2, cap, prices, dp) + prices[i] , rec(i+1, 0, cap, prices, dp)});
        }else if(trans == 1){
            profit = max({rec(i+1, 0, cap-1, prices, dp) + prices[i], rec(i+1, 1, cap, prices, dp) });
        }else{
            profit = max(rec(i+1, 0, cap -1, prices, dp) - prices[i], rec(i+1 , 2, cap, prices, dp));
        }
         return dp[i][trans][cap] = profit;
    }
    long long maximumProfit(vector<int>& prices, int k) {
        int n= prices.size();
        vector<vector<vector<ll>>>dp(n+1, vector<vector<ll>>(3, vector<ll>(k+1, -1) ));
        return rec(0, 0, k, prices, dp);
    }
};