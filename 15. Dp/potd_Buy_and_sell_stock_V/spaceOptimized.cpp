#define ll long long
class Solution {
public:
// trans = 0, can buy or sell, trans = 1, can sell, trans = 2 , have to purchase
    long long maximumProfit(vector<int>& prices, int k) {
        int n= prices.size();
        vector<vector<ll>>cur(3, vector<ll>(k+1, 0));
        vector<vector<ll>>ahead(3, vector<ll>(k+1, 0));
        for(int i = n; i>=0; i--){
            for(int trans = 0; trans <= 2; trans++){
                for(int cap = 0; cap <= k; cap++){
                    if(i == n || cap == 0 ){
                       if(trans == 2) cur[trans][cap] = -1e18;
                    }else{
                        ll profit;
                        if(trans == 0){
                            profit= max({ahead[1][cap] - prices[i] , ahead[2][cap] + prices[i] , ahead[0][cap]});
                        }else if(trans == 1){
                            profit = max({ahead[0][cap-1] + prices[i], ahead[1][cap] });
                        }else{
                            profit = max( ahead[0][cap-1] - prices[i], ahead[2][cap] );
                        }
                        cur[trans][cap] = profit;
                    }
                }
            }
                ahead = cur;
        }
        return ahead[0][k];
    }
};