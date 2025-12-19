class Solution {
public:
    int rec(int i , int buy, vector<int> & prices, int n){
        if(i >= n) return 0;
        int profit;
        if(buy == 0){
            profit= max(rec(i+1, 1, prices, n) - prices[i] , rec(i+1, 0, prices,n));
        }else if(buy == 1){
            profit = max(rec(i+2, 0, prices, n) + prices[i], rec(i+1, 1, prices, n));
        }
        return profit;
    }
    int maxProfit(vector<int>& prices) {
        int n= prices.size();
        return rec(0, 0, prices, n);
    }
};