class Solution {
public:
    int rec(int i, int buy, vector<int>&prices, int fee, int n){
        if(i == n) return 0;
        int profit;
        if(buy == 0){
            profit = max(rec(i+1, 1, prices, fee, n) - prices[i] - fee, rec(i+1, 0,prices, fee, n));
        }else{
            profit = max(rec(i+1, 0, prices, fee, n) + prices[i], rec(i+1, 1, prices, fee, n));
        }
        return profit;
    }

    int maxProfit(vector<int>& prices, int fee) {
        int n = prices.size();
        return rec(0, 0, prices, fee, n);
    }
};