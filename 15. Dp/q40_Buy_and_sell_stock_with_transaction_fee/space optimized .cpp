class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
        int n = prices.size();
        vector<int>cur(2, 0), ahead(2, 0);
        for(int i= n-1; i>=0; i--){
            for(int buy = 0; buy <= 1; buy++){
                if(buy == 0){
                    cur[buy] = max(ahead[1] - prices[i] - fee, ahead[0]);
                }else{
                    cur[buy] = max(ahead[0] + prices[i] , ahead[1]);
                }
            }
            ahead = cur;
        }      
        return cur[0];
    }
};