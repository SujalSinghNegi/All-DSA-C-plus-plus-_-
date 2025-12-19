class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n= prices.size();
        vector<int>pre(2, 0), cur(2, 0), ahead(2, 0);
            for(int i= n-1; i>=0; i--){
                for(int buy = 0; buy <= 1; buy++){
                    int profit;
                    if(buy == 0){
                        pre[buy] = max(cur[1] - prices[i] , cur[0]);
                    }else if(buy == 1){
                        pre[buy] = max(ahead[0] + prices[i], cur[1]);
                    }
                }
                ahead= cur;
                cur = pre;
            }
        return pre[0];
    }
};