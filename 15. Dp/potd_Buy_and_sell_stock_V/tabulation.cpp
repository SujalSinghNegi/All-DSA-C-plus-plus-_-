#define ll long long
class Solution {
public:
// trans = 0, can buy or sell, trans = 1, can sell, trans = 2 , have to purchase
    long long maximumProfit(vector<int>& prices, int k) {
        int n= prices.size();
        vector<vector<vector<ll>>>dp(n+1, vector<vector<ll>>(3, vector<ll>(k+1, 0) ));
        for(int i = n; i>=0; i--){
            for(int trans = 0; trans <= 2; trans++){
                for(int cap = 0; cap <= k; cap++){
                    if(i == n || cap == 0 ){
                       if(trans == 2) dp[i][trans][cap] = -1e18;
                    }else{
                        ll profit;
                        if(trans == 0){
                            profit= max({dp[i+1][1][cap] - prices[i] , dp[i+1][2][cap] + prices[i] , dp[i+1][0][cap]});
                        }else if(trans == 1){
                            profit = max({dp[i+1][0][cap-1] + prices[i], dp[i+1][1][cap] });
                        }else{
                            profit = max( dp[i+1][0][cap-1] - prices[i], dp[i+1][2][cap] );
                        }
                        dp[i][trans][cap] = profit;
                    }
                }
            }
        }
        return dp[0][0][k];
    }
};