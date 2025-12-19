#define ll long long
class Solution {
public:
// trans = 0, can buy or sell, trans = 1, can sell, trans = 3 , have to purchase
    ll rec(int i , int trans, int cap, vector<int>& prices){
        int n = prices.size();
        if(i == n || cap == 0) return (trans  == 3)? -1e9 : 0 ;
        ll profit;
        if(trans == 0){
            profit= max({rec(i+1, 1, cap, prices) - prices[i] , rec(i+1, 3, cap, prices) + prices[i] , rec(i+1, 0, cap, prices)});
        }else if(trans == 1){
            profit = max({rec(i+1, 0, cap-1, prices) + prices[i], rec(i+1, 1, cap, prices) });
        }else{
            profit = max(rec(i+1, 0, cap -1, prices) - prices[i], rec(i+1 , 3, cap, prices));
        }
         return profit;
    }
    long long maximumProfit(vector<int>& prices, int k) {
        return rec(0, 0, k, prices);
    }
};